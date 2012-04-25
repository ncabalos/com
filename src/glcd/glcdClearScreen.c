/**
 *
 * @file glcdClearScreen.c
 *
 * @brief This file contains the implementation for clearing LCD screen
 *
 * @author Nathaniel Abalos
 *
 * @ingroup glcdGroup
 */

#include "typedef.h"
#include "glcd.h"

/**
 * This function is used to clear LCD RAM of pixels
 */

void glcdClearScreen(void)
{
    UINT_8 x;
    UINT_8 page;

    for(page = 0; page < 8; page++)
    {
        for(x = 0; x < 128; x++)
        {
            glcdWriteRam(0x00,x,page);
        }
    }
}
