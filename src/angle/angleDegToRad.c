/**
 * @file angleDegToRad.c
 *
 * @brief Implementation of degree to radian conversion
 * 
 * @ingroup angleGroup
 */
#include <math.h>
#include "typedef.h"
#include "angle.h"

/**
 * This function converts an angle from degree to radian
 *
 * @param deg The angle in degree
 * @return The angle in radian
 */
FLOAT degreeToRadian(FLOAT deg)
{
    return deg * 0.01745;
}
