/**
 * @file kalman.h
 *
 * @defgroup kalmanGroup Kalman Filter
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
