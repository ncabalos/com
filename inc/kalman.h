/* -*- indent-tabs-mode:T; c-basic-offset:8; tab-width:8; -*- vi: set ts=8:
 * $Id: tilt.h,v 1.1 2003/07/09 18:23:29 john Exp $
 *
 * 1 dimensional tilt sensor using a dual axis accelerometer
 * and single axis angular rate gyro.  The two sensors are fused
 * via a two state Kalman filter, with one state being the angle
 * and the other state being the gyro bias.
 *
 * Gyro bias is automatically tracked by the filter.  This seems
 * like magic.
 *
 * Please see the file tilt.c for more details on the implementation.
 * This header only has comments for the use of the module, not the
 * inner workings.
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
#ifndef _kalman_h_
#define _kalman_h_

typedef struct
{   
    float angle;
    float q_bias;
    float rate;

    float dt;
    float P[2][2];

    float   R_angle;
    float   Q_angle;
    float   Q_gyro;
    float   Pdot[4];
}KALMAN;

/*
 * Our two states, the angle and the gyro bias.  As a byproduct of computing
 * the angle, we also have an unbiased angular rate available.   These are
 * read-only to the user of the module.
 */
float kalmanGetAngle(KALMAN *self);
float kalmanGetRate(KALMAN *self);
float kalmanGetBias(KALMAN *self);

void kalmanInit(KALMAN *self, float dt, float r_angle, float q_angle, float q_gyro);
/*
 * state_update is called every dt with a biased gyro measurement
 * by the user of the module.  It updates the current angle and
 * rate estimate.
 *
 * The pitch gyro measurement should be scaled into real units, but
 * does not need any bias removal.  The filter will track the bias.
 */
void kalmanStateUpdate(KALMAN *self, float q_m);
/*
 * kalman_update is called by a user of the module when a new
 * accelerometer measurement is available.  ax_m and az_m do not
 * need to be scaled into actual units, but must be zeroed and have
 * the same scale.
 *
 * This does not need to be called every time step, but can be if
 * the accelerometer data are available at the same rate as the
 * rate gyro measurement.
 */
void kalmanUpdate(KALMAN *self, float ax_m, float az_m);

#endif
