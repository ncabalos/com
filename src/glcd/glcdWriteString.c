/**
 * @brief This file contains the implementation for writing a string
 *
 * @file glcdWriteString.c
 * @author Nathaniel Abalos
 *
 * @ingroup glcdGroup
 */

#include "typedef.h"
#include "glcd.h"
/**
 * This function is used to write a string at a specified line
 * @param line This is the line number. Line number ranges from 0-7.
 * @param s This is the string to write
 */
void glcdWriteString(UINT_8 line, char *s)
{
    UINT_8 x;
    UINT_8 y;

    x = 0;
    y = line * 8;

    glcdDrawString(x,y,s,GLCD_PIXEL_FILL);
}
