/**
 * @brief This file contains the implementation for enabling/disabling the LCD
 *
 * @file glcdEnable.c
 * @author Nathaniel Abalos
 */

#include "typedef.h"
#include "glcd.h"

/**
 * This function is used to turn on or turn off LCD
 * @param b TRUE = on, FALSE = off
 */
void glcdEnable(BOOL b)
{
    if(b == TRUE)
    {
        glcdWriteInstruction(0x3F,1);
        glcdWriteInstruction(0x3F,2);
    }
    else
    {
        glcdWriteInstruction(0x3E,1);
        glcdWriteInstruction(0x3E,2);
    }  
}
