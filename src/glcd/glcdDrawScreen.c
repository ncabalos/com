/**
 * @brief This file contains the implementation for drawing to the LCD screen
 *
 * @file glcdDrawScreen.c
 * @author Nathaniel Abalos
 *
 * @ingroup glcdGroup
 */

#include "typedef.h"
#include "glcd.h"

/**
 * This function will be used to draw contents of RAM to LCD.
 * 
 */

void glcdDrawScreen(void)
{
    UINT_8 x = 0;
    UINT_8 page = 0;
    UINT_8 cs = 0;
    
    for(page = 0; page < 8; page++)
    {
        for(x = 0; x < 128; x++)
        {
            cs = (x >> 6);
            cs = cs + 1;
            glcdSetAddress(x,cs);
            glcdSetPage(page,cs);
            glcdWriteData(glcdRam[x][page],cs);
        }
    }
}
