/**
 * @file kalman.c
 *
 * @ingroup kalmanGroup
 */
#include <math.h>
#include "typedef.h"
#include "kalman.h"


FLOAT kalmanGetAngle(KALMAN *self)
{
    return self->angle;
}

FLOAT kalmanGetRate(KALMAN *self)
{
    return self->rate;
}
FLOAT kalmanGetBias(KALMAN *self)
{
    return self->q_bias;
}


void kalmanInit(KALMAN *self, FLOAT dt, FLOAT r_angle, FLOAT q_angle, FLOAT q_gyro)
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
	FLOAT q_m	/* Pitch gyro measurement */
)
{
	FLOAT q = q_m - self->q_bias;

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
	FLOAT ax_m,	/* X acceleration */
	FLOAT az_m	/* Z acceleration */
)
{
	/* Compute our measured angle and the error in our estimate */
	FLOAT angle_m = atan2( -az_m, ax_m );
	FLOAT angle_err = angle_m - self->angle;
	FLOAT C_0 = 1;
	FLOAT PCt_0 = C_0 *self->P[0][0]; /* + C_1 * P[0][1] = 0 */
	FLOAT PCt_1 = C_0 * self->P[1][0]; /* + C_1 * P[1][1] = 0 */
	FLOAT E = self->R_angle + C_0 * PCt_0;
	FLOAT K_0 = PCt_0 / E;
	FLOAT K_1 = PCt_1 / E;
	FLOAT t_0 = PCt_0; /* C_0 * P[0][0] + C_1 * P[1][0] */
	FLOAT t_1 = C_0 * self->P[0][1]; /* + C_1 * P[1][1]  = 0 */

	self->P[0][0] -= K_0 * t_0;
	self->P[0][1] -= K_0 * t_1;
	self->P[1][0] -= K_1 * t_0;
	self->P[1][1] -= K_1 * t_1;

	self->angle	+= K_0 * angle_err;
        self->q_bias	+= K_1 * angle_err;
}
