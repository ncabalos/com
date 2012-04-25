/**
 * @file pidInit.c
 *
 * @ingroup pidGroup
 */
#include "typedef.h"
#include "pid.h"

void pidInitInt8(PID *pid, INT_8 p, INT_8 i, INT_8 d, UINT_16 ms) {
    pid->datatype = DATA_TYPE_INT8;
    pid->ms = ms;
    pid->p.Int8 = p;
    pid->i.Int8 = i;
    pid->d.Int8 = d;
}

void pidInitInt16(PID *pid, INT_16 p, INT_16 i, INT_16 d, UINT_16 ms) {
    pid->datatype = DATA_TYPE_INT16;
    pid->ms = ms;
    pid->p.Int16 = p;
    pid->i.Int16 = i;
    pid->d.Int16 = d;
}

void pidInitFloat(PID *pid, FLOAT p, FLOAT i, FLOAT d, UINT_16 ms) {
    pid->datatype = DATA_TYPE_FLOAT;
    pid->ms = ms;
    pid->p.Float = p;
    pid->i.Float = i;
    pid->d.Float = d;
}
