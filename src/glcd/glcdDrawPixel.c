/**
 * @brief This file contains the implementation for drawing a pixel
 *
 * @file glcdDrawPixel.c
 * @author Nathaniel Abalos
 */

#include "typedef.h"
#include "glcd.h"



/**
 * This function is used to draw a filled or cleared pixel at specified location
 * @param x X coordinate
 * @param y Y coordinate
 * @param fill This specifies whether to fill pixels or clear pixels
 */

void glcdDrawPixel(UINT_8 x, UINT_8 y, BOOL fill) {
    UINT_8 page;
    UINT_8 dot;
    UINT_8 seg;

    UINT_8 tmp;

    UINT_8 data = 0;

    if (x < 128 && y < 64) {
        page = ((y >> 3) & 0x07);
        dot = y % 8;

        data = (0x01 << dot);

        if (fill == GLCD_PIXEL_CLEAR) data = ~data;

        seg = x % 64;

        tmp = glcdReadRam(x, page);

        if (fill == GLCD_PIXEL_FILL)
            data |= tmp;
        else
            data &= tmp;

        glcdWriteRam(data, x, page);
    }
}
