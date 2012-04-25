/**
 * @brief This file contains the implementation for drawing a line
 *
 * @file glcdDrawLine.c
 * @author Nathaniel Abalos
 *
 * @ingroup glcdGroup
 */

#include "typedef.h"
#include "glcd.h"

/**
 * This function will be used to draw a line to RAM
 * @param x_start X coordinate for start point
 * @param y_start y coordinate for start point
 * @param x_end X coordinate for end point
 * @param y_end Y coordinate for end point
 * @param fill Specifies fill pixel or clear pixel
 */

void glcdDrawLine(UINT_8 x_start, UINT_8 y_start, UINT_8 x_end, UINT_8 y_end,BOOL fill) {
    INT_8 x_div_y;
    INT_8 y_div_x;
    INT_8 x;
    INT_8 y;
    INT_8 xm;
    INT_8 ym;

    xm = (INT_8) x_end - (INT_8) x_start;
    ym = (INT_8) y_end - (INT_8) y_start;

    x_div_y = xm / ym;
    y_div_x = ym / xm;

    if(x_div_y > 0 && y_div_x == 0 && xm > 0 && ym > 0){
        x = 0;
        y = 0;
        do {
            
            glcdDrawPixel(x_start + x, y_start + y,fill);
            
            x++;
            if (x % x_div_y == 0) y++;
        } while ((x_start + x) != x_end);
    }
    else if(y_div_x > 0 && x_div_y == 0 && xm > 0 && ym > 0){
        x = 0;
        y = 0;
        do {
            glcdDrawPixel(x_start + x, y_start + y,fill);
            y++;
            if (x % y_div_x == 0) x++;
        } while ((y_start + y) != y_end);
    }
    else if(x_div_y < 0 && y_div_x == 0 && xm > 0 && ym < 0){
        x = 0;
        y = 0;
        do {
            glcdDrawPixel(x_start + x, y_start - y,fill);
            x++;
            if (x % x_div_y == 0) y++;
        } while ((x_start + x) != x_end);
    }
    else if(y_div_x < 0 && x_div_y == 0 && xm > 0 && ym < 0){
        x = 0;
        y = 0;
        do {
            glcdDrawPixel(x_start + x, y_start - y,fill);
            y++;
            if (y % y_div_x == 0) x++;
        } while ((y_start - y) != y_end);
    }
    else if (xm == 0)
    {
        x = 0;
        y = 0;
        do{
            
            glcdDrawPixel(x_start + x, y_start + y,fill);
            
            y++;
        }while((y_start+y) != y_end);
    }
    else if( ym == 0)
    {
        x = 0;
        y = 0;
        do{
            glcdDrawPixel(x_start + x, y_start + y,fill);
            x++;
        }while((x_start+x) != x_end);
    }
}
