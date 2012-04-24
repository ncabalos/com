/**
 * @brief This file contains the implementation for drawing a string
 *
 * @file glcdDrawString.c
 * @author Nathaniel Abalos
 */

#include "typedef.h"
#include "glcd.h"
/**
 * This function will be used to draw a string at the specified coordinate
 * @param x X coordinate
 * @param y Y coordinate
 * @param s This is the string
 * @param fill This specifies whether to fill pixels or clear pixels
 */
void glcdDrawString(UINT_8 x, UINT_8 y, char *s,BOOL fill)
{
    UINT_8 i = 0;
    char c;

    while( (c = *s++) != '\0')
    {
        glcdDrawChar(x + (i * 6),y,c,fill);
        i++;
    }
}
