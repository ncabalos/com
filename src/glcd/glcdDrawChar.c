/**
 * @brief This file contains the implementation for drawing a character
 *
 * @file glcdDrawChar.c
 * @author Nathaniel Abalos
 *
 * @ingroup glcdGroup
 */

#include "typedef.h"
#include "glcd.h"

/**
 * This function is used to draw a character at the specified location
 * @param x X coordinate
 * @param y Y coordinate
 * @param c This is the character to draw
 * @param fill This specifies whether to fill pixels or clear pixels
 */

void glcdDrawChar(UINT_8 x, UINT_8 y, char c,BOOL fill)
{
    UINT_8 i;
    UINT_8 j;
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(((glcdFont[c][i] >> j)&0x01))
                glcdDrawPixel(x+i,y+j,fill);
        }
    }
}
