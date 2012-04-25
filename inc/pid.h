/**
 * @file pid.h
 *
 * @defgroup pidGroup PID
 */
#ifndef PID_H
#define PID_H

#include "typedef.h"

typedef struct{

    union P_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }p;

    union I_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }i;

    union D_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }d;

    union CURERROR_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }curError;

    union PREVERROR_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }prevError;

    union DIFFERROR_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }diffError;
    
    union SUMERROR_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }sumError;

    union PIDRESULT_UNION{
        INT_8   Int8;
        INT_16  Int16;
        FLOAT   Float;
    }pidResult;

    DATA_TYPE datatype;

    UINT_16 ms;
}PID;

void pidInitInt8(PID *pid, INT_8 p, INT_8 i, INT_8 d, UINT_16 ms);
void pidInitInt16(PID *pid, INT_16 p, INT_16 i, INT_16 d, UINT_16 ms);
void pidInitFloat(PID *pid, FLOAT p, FLOAT i, FLOAT d, UINT_16 ms);
INT_8 pidUpdateInt8(PID * pid, INT_8 setpoint, INT_8 measured);
INT_16 pidUpdateInt16(PID * pid, INT_16 setpoint, INT_16 measured);
FLOAT pidUpdateFloat(PID * pid, FLOAT setpoint, FLOAT measured);

#endif