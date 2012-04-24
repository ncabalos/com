/**
 * @brief This file contains the implementation for drawing a rectangle
 *
 * @file glcdDrawRectangle.c
 * @author Nathaniel Abalos
 */

#include "typedef.h"
#include "glcd.h"

/**
 * This function is used to draw a rectangle with specified height and width at specified location
 * @param x X coordinate
 * @param y Y coordinate
 * @param w Width of rectangle
 * @param h Height of rectangle
 * @param fill This specifies whether to fill pixels or clear pixels
 */
void glcdDrawRectangle(UINT_8 x, UINT_8 y, UINT_8 w, UINT_8 h,BOOL fill)
{
    if(!w) w = 1;
    if(!h) h = 1;
    glcdDrawLine(x,y,x+w,y,fill);
    glcdDrawLine(x,y,x,y+h,fill);
    glcdDrawLine(x+w-1,y,x+w-1,y+h,fill);
    glcdDrawLine(x,y+h-1,x+w,y+h-1,fill);
}
