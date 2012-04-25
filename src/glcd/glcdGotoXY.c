/**
 * @brief This file contains the implementation for setting X and Y coordinates
 *
 * @file glcdGotoXY.c
 * @author Nathaniel Abalos
 *
 * @ingroup glcdGroup
 */

#include "typedef.h"
#include "glcd.h"

/**
 * This function is used to set location
 * @param x X coordinate
 * @param y Y coordinate
 */
void glcdGotoXY(UINT_8 x, UINT_8 y)
{
    UINT_8 seg;
    UINT_8 page;
    UINT_8 cs;

    cs = (x >> 6);
    cs = cs + 1;

    seg = x % 64;

    page = ((y >> 3) & 0x07);

    glcdSetPage(page,cs);
    glcdSetAddress(seg,cs);

}
