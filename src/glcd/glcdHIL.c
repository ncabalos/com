/**
 * @file glcdHIL.c
 * @brief This file is the Hardware Interface Layer (HIL) for the graphical LCD library.
 *
 * This file contains all functions that are hardware dependent. If using a different
 * microcontroller, these are the functions that need to be ported.
 * @author Nathaniel Abalos
 *
 * @ingroup glcdGroup
 */

#include <htc.h>
#include "typedef.h"
#include "glcd.h"

void glcdInitHIL(void);
void glcdWriteData(UINT_8 data,UINT_8 cs);
void glcdSetPage(UINT_8 page,UINT_8 cs);
void glcdSetAddress(UINT_8 address,UINT_8 cs);
void glcdSetPort(UINT_8 io);
void glcdWritePort(UINT_8 d);
UINT_8 glcdReadPort(void);
BOOL glcdIsBusy(void);
UINT_8 glcdReadData(UINT_8 cs);

/**
 * This function is used to initialize the I/O pins connected to the LCD
 */
void glcdInitHIL(void)
{

    UINT_8 i = 100;

    ANSELAbits.ANSA0 = 0;
    ANSELAbits.ANSA1 = 0;
    ANSELAbits.ANSA2 = 0;
    ANSELAbits.ANSA3 = 0;
    ANSELAbits.ANSA5 = 0;

    ANSELDbits.ANSD1 = 0;
    ANSELDbits.ANSD2 = 0;
    ANSELDbits.ANSD3 = 0;
    ANSELCbits.ANSC4 = 0;
    ANSELCbits.ANSC5 = 0;
    ANSELCbits.ANSC6 = 0;

    ANSELBbits.ANSB0 = 0;
    ANSELBbits.ANSB1 = 0;
    ANSELBbits.ANSB2 = 0;
    ANSELBbits.ANSB3 = 0;
    ANSELBbits.ANSB4 = 0;
    ANSELBbits.ANSB5 = 0;

    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC5 = 0;
    TRISCbits.TRISC6 = 0;

    TRISBbits.TRISB = 0;

    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;

    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;
    TRISAbits.TRISA6 = 0;
    TRISAbits.TRISA7 = 0;

    GLCD_PIN_DI = 0;
    GLCD_PIN_RW = 0;
    GLCD_PIN_E = 0;
    GLCD_PIN_CS1 = 0;
    GLCD_PIN_CS2 = 0;
    GLCD_PIN_RST = 0;
    while(i--);
    GLCD_PIN_RST = 1;
}

/**
 * This funtion is used to write data to the LCD.
 * @param data Data to write
 * @param cs Selects left segment or right segment of LCD. 1 = Left, 2 = Right
 */
void glcdWriteData(UINT_8 data,UINT_8 cs)
{
    GLCD_PIN_CS1 = ((cs >> 0) & 0x01);
    GLCD_PIN_CS2 = ((cs >> 1) & 0x01);
    glcdSetPort(0);
    GLCD_PIN_DI = 1;
    GLCD_PIN_RW = 0;
    GLCD_PIN_E = 1;
    glcdWritePort(data);
    GLCD_PIN_E = 0;
}

/**
 * This function is used to write instructions to the LCD
 * @param data Instruction to write
 * @param cs Selects left segment or right segment of LCD. 1 = Left, 2 = Right
 */
void glcdWriteInstruction(UINT_8 data,UINT_8 cs)
{
    GLCD_PIN_CS1 = ((cs >> 0) & 0x01);
    GLCD_PIN_CS2 = ((cs >> 1) & 0x01);
    glcdSetPort(0);
    GLCD_PIN_DI = 0;
    GLCD_PIN_RW = 0;
    GLCD_PIN_E = 1;
    glcdWritePort(data);
    GLCD_PIN_E = 0;
}

/**
 * This function is used to set the page to write to.
 * @param page Page number. 0-7
 * @param cs Selects left segment or right segment of LCD. 1 = Left, 2 = Right
 */
void glcdSetPage(UINT_8 page,UINT_8 cs)
{
    UINT_8 data;
    GLCD_PIN_CS1 = ((cs >> 0) & 0x01);
    GLCD_PIN_CS2 = ((cs >> 1) & 0x01);
    data = 0xB8;
    data |= (page & 0x07);
    glcdSetPort(0);
    GLCD_PIN_DI = 0;
    GLCD_PIN_RW = 0;
    GLCD_PIN_E = 1;
    glcdWritePort(data);
    GLCD_PIN_E = 0;
}
/**
 * This function is used to set the X address to write to
 * @param address X address
 * @param cs Selects left segment or right segment of LCD. 1 = Left, 2 = Right
 */
void glcdSetAddress(UINT_8 address,UINT_8 cs)
{
    UINT_8 data;
    GLCD_PIN_CS1 = ((cs >> 0) & 0x01);
    GLCD_PIN_CS2 = ((cs >> 1) & 0x01);
    data = 0x40;
    data |= (address & 0x3F);
    glcdSetPort(0);
    GLCD_PIN_DI = 0;
    GLCD_PIN_RW = 0;
    GLCD_PIN_E = 1;
    glcdWritePort(data);
    GLCD_PIN_E = 0;
}
/**
 * This function is used to set the direction of the data port used by the LCD data port
 * @param io Direction: 1 = input, 0 = output
 */
void glcdSetPort(UINT_8 io)
{
    if(io)
        GLCD_PORT_DIR = 0xFF;
    else
        GLCD_PORT_DIR = 0x00;
}
/**
 * This function is used to write the data to the data port
 * @param d Data to write
 */
void glcdWritePort(UINT_8 d)
{
    UINT_8 i = 7;
    GLCD_PORT_OUT = d;
    while(i--);
}
/**
 * This function is used to read the data from the data port
 * @return Data read from data port
 */
UINT_8 glcdReadPort(void)
{
    UINT_8 d = 0;
    UINT_8 i = 15;
    while(i--);
    d = GLCD_PORT_IN;
    return d;
}
/**
 * This function is used to check if the LCD is busy with previous instruction
 * @return TRUE if busy, FALSE if not busy
 */
BOOL glcdIsBusy(void)
{
    UINT_8 data;
    glcdSetPort(1);
    GLCD_PIN_DI = 1;
    GLCD_PIN_RW = 1;
    GLCD_PIN_E = 1;
    data = glcdReadPort();
    GLCD_PIN_E = 0;

    data = (data >> 7) & 0x01;

    return data;
}

/**
 * This function is used to read data from the LCD
 * @param cs Selects left segment or right segment of LCD. 1 = Left, 2 = Right
 * @return Data read
 */

UINT_8 glcdReadData(UINT_8 cs)
{
    UINT_8 data;
    UINT_16 i = 10;
    GLCD_PIN_CS1 = ((cs >> 0) & 0x01);
    GLCD_PIN_CS2 = ((cs >> 1) & 0x01);
    glcdSetPort(1);
    GLCD_PIN_DI = 1;
    GLCD_PIN_RW = 1;
    GLCD_PIN_E = 1;
    
    data = glcdReadPort();
    GLCD_PIN_E = 0;

    return data;
}

/**
 * This function is used to write data to the LCD RAM
 * @param data Data to write
 * @param x X address
 * @param page Page number
 */
void glcdWriteRam(UINT_8 data, UINT_8 x, UINT_8 page)
{
    glcdRam[x][page] = data;
}

/**
 * This function is used to read data from the LCD RAM
 * @param x X address
 * @param page Page Number
 * @return Data read
 */
UINT_8 glcdReadRam(UINT_8 x, UINT_8 page)
{
    return glcdRam[x][page];
}

