/* -*- indent-tabs-mode:T; c-basic-offset:8; tab-width:8; -*- vi: set ts=8:
 * $Id: tilt.c,v 1.1 2003/07/09 18:23:29 john Exp $
 *
 * 1 dimensional tilt sensor using a dual axis accelerometer
 * and single axis angular rate gyro.  The two sensors are fused
 * via a two state Kalman filter, with one state being the angle
 * and the other state being the gyro bias.
 *
 * Gyro bias is automatically tracked by the filter.  This seems
 * like magic.
 *
 * Please note that there are lots of comments in the functions and
 * in blocks before the functions.  Kalman filtering is an already complex
 * subject, made even more so by extensive hand optimizations to the C code
 * that implements the filter.  I've tried to make an effort of explaining
 * the optimizations, but feel free to send mail to the mailing list,
 * autopilot-devel@lists.sf.net, with questions about this code.
 *
 *
 * (c) 2003 Trammell Hudson <hudson@rotomotion.com>
 *
 *************
 *
 *  This file is part of the autopilot onboard code package.
 *
 *  Autopilot is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Autopilot is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Autopilot; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#include <math.h>
#include "kalman.h"


float kalmanGetAngle(KALMAN *self)
{
    return self->angle;
}

float kalmanGetRate(KALMAN *self)
{
    return self->rate;
}
float kalmanGetBias(KALMAN *self)
{
    return self->q_bias;
}


void kalmanInit(KALMAN *self, float dt, float r_angle, float q_angle, float q_gyro)
{
    self->dt = dt;
    self->R_angle = r_angle;
    self->Q_angle = q_angle;
    self->Q_gyro = q_gyro;

    self->P[0][0] = 1;
    self->P[0][1] = 0;
    self->P[1][0] = 0;
    self->P[1][1] = 1;
}

void kalmanStateUpdate(KALMAN *self,
	float q_m	/* Pitch gyro measurement */
)
{
	float q = q_m - self->q_bias;

        self->Pdot[0] = self->Q_angle - self->P[0][1] - self->P[1][0];
        self->Pdot[1] = self->P[1][1] * -1.0;
        self->Pdot[2] = self->P[1][1] * -1.0;
        self->Pdot[3] = self->Q_gyro;

	/* Store our unbias gyro estimate */
	self->rate = q;

	self->angle += q * self->dt;

	/* Update the covariance matrix */
	self->P[0][0] += self->Pdot[0] * self->dt;
	self->P[0][1] += self->Pdot[1] * self->dt;
	self->P[1][0] += self->Pdot[2] * self->dt;
	self->P[1][1] += self->Pdot[3] * self->dt;
}

void
kalmanUpdate(KALMAN *self,
	float ax_m,	/* X acceleration */
	float az_m	/* Z acceleration */
)
{
	/* Compute our measured angle and the error in our estimate */
	float angle_m = atan2( -az_m, ax_m );
	float angle_err = angle_m - self->angle;
	float C_0 = 1;
	float PCt_0 = C_0 *self->P[0][0]; /* + C_1 * P[0][1] = 0 */
	float PCt_1 = C_0 * self->P[1][0]; /* + C_1 * P[1][1] = 0 */
	float E = self->R_angle + C_0 * PCt_0;
	float K_0 = PCt_0 / E;
	float K_1 = PCt_1 / E;
	float t_0 = PCt_0; /* C_0 * P[0][0] + C_1 * P[1][0] */
	float t_1 = C_0 * self->P[0][1]; /* + C_1 * P[1][1]  = 0 */

	self->P[0][0] -= K_0 * t_0;
	self->P[0][1] -= K_0 * t_1;
	self->P[1][0] -= K_1 * t_0;
	self->P[1][1] -= K_1 * t_1;

	self->angle	+= K_0 * angle_err;
        self->q_bias	+= K_1 * angle_err;
}
