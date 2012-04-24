/**
 * @file glcdFillScreen.c
 * @author Nathaniel Abalos
 */

#include "typedef.h"
#include "glcd.h"
/**
 * This function will be used to fill up the screen. 
 */
void glcdFillScreen(void)
{
    UINT_8 x;
    UINT_8 page;

    for(page = 0; page < 8; page++)
    {
        for(x = 0; x < 128; x++)
        {
            glcdWriteRam(0xFF,x,page);
        }
    }
}
