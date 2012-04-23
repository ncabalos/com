#include <htc.h>
#include "typedef.h"
#include "glcd.h"

// Function Prototypes
void glcdWriteData(UINT_8 data,UINT_8 cs);
void glcdSetPage(UINT_8 page,UINT_8 cs);
void glcdSetAddress(UINT_8 address,UINT_8 cs);
void glcdSetPort(UINT_8 io);
void glcdWritePort(UINT_8 d);
UINT_8 glcdReadPort(void);
BOOL glcdIsBusy(void);
UINT_8 glcdReadData(UINT_8 cs);


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

void glcdSetPort(UINT_8 io)
{
    if(io)
        GLCD_PORT_DIR = 0xFF;
    else
        GLCD_PORT_DIR = 0x00;
}

void glcdWritePort(UINT_8 d)
{
    UINT_8 i = 7;
    GLCD_PORT_OUT = d;
    while(i--);
}

UINT_8 glcdReadPort(void)
{
    UINT_8 d = 0;
    UINT_8 i = 15;
    while(i--);
    d = GLCD_PORT_IN;
    return d;
}

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

void glcdWriteRam(UINT_8 data, UINT_8 x, UINT_8 page)
{
    glcdRam[x][page] = data;
}
UINT_8 glcdReadRam(UINT_8 x, UINT_8 page)
{
    return glcdRam[x][page];
}

