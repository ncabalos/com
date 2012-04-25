/**
 * @file pidUpdate.c
 *
 * @ingroup pidGroup
 */

#include "typedef.h"
#include "pid.h"

INT_8 pidUpdateInt8(PID * pid, INT_8 setpoint, INT_8 measured)
{
    INT_8 p;
    INT_8 i;
    INT_8 d;

    if(pid->datatype == DATA_TYPE_INT8)
    {
        pid->curError.Int8 = setpoint - measured;
        pid->diffError.Int8 = pid->curError.Int8 - pid->prevError.Int8;
        pid->sumError.Int8 = pid->sumError.Int8 + pid->curError.Int8;

        p = pid->p.Int8 * pid->curError.Int8;
        i = pid->i.Int8 * pid->sumError.Int8;
        d = pid->i.Int8 * pid->diffError.Int8;

        pid->pidResult.Int8 = p + i + d;
    }
    return pid->pidResult.Int8;
}
INT_16 pidUpdateInt16(PID * pid, INT_16 setpoint, INT_16 measured)
{
    INT_16 p;
    INT_16 i;
    INT_16 d;

    if(pid->datatype == DATA_TYPE_INT16)
    {
        pid->curError.Int16 = setpoint - measured;
        pid->diffError.Int16 = pid->curError.Int16 - pid->prevError.Int16;
        pid->sumError.Int16 = pid->sumError.Int16 + pid->curError.Int16;

        p = pid->p.Int16 * pid->curError.Int16;
        i = pid->i.Int16 * pid->sumError.Int16;
        d = pid->i.Int16 * pid->diffError.Int16;

        pid->pidResult.Int16 = p + i + d;
    }
    return pid->pidResult.Int16;
}
FLOAT pidUpdateFloat(PID * pid, FLOAT setpoint, FLOAT measured)
{
    FLOAT p;
    FLOAT i;
    FLOAT d;

    if(pid->datatype == DATA_TYPE_FLOAT)
    {
        pid->curError.Float = setpoint - measured;
        pid->diffError.Float = pid->curError.Float - pid->prevError.Float;
        pid->sumError.Float = pid->sumError.Float + pid->curError.Float;

        p = pid->p.Float * pid->curError.Float;
        i = pid->i.Float * pid->sumError.Float;
        d = pid->i.Float * pid->diffError.Float;

        pid->pidResult.Float = p + i + d;
    }
    return pid->pidResult.Float;
}
