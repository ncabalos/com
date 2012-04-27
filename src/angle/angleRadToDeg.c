/**
 * @file angleRadToDeg.c
 *
 * @brief Implementation of radian to degree conversion
 *
 * @ingroup angleGroup
 */
#include <math.h>
#include "typedef.h"
#include "angle.h"

/**
 * This function converts an angle from radian to degree
 *
 * @param deg The angle in radian
 * @return The angle in degree
 */
FLOAT radianToDegree(FLOAT deg)
{
    return deg * 57.2958;
}

