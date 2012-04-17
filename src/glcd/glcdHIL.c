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
    GLCD_PORT_DIR_DB0 = (io & 0x01);
    GLCD_PORT_DIR_DB1 = (io & 0x01);
    GLCD_PORT_DIR_DB2 = (io & 0x01);
    GLCD_PORT_DIR_DB3 = (io & 0x01);
    GLCD_PORT_DIR_DB4 = (io & 0x01);
    GLCD_PORT_DIR_DB5 = (io & 0x01);
    GLCD_PORT_DIR_DB6 = (io & 0x01);
    GLCD_PORT_DIR_DB7 = (io & 0x01);
}

void glcdWritePort(UINT_8 d)
{
    GLCD_PORT_OUT_DB0 = ((d >> 0) & 0x01);
    GLCD_PORT_OUT_DB1 = ((d >> 1) & 0x01);
    GLCD_PORT_OUT_DB2 = ((d >> 2) & 0x01);
    GLCD_PORT_OUT_DB3 = ((d >> 3) & 0x01);
    GLCD_PORT_OUT_DB4 = ((d >> 4) & 0x01);
    GLCD_PORT_OUT_DB5 = ((d >> 5) & 0x01);
    GLCD_PORT_OUT_DB6 = ((d >> 6) & 0x01);
    GLCD_PORT_OUT_DB7 = ((d >> 7) & 0x01);
}

UINT_8 glcdReadPort(void)
{
    UINT_8 d = 0;
    d = (GLCD_PORT_IN_DB0 << 0);
    d |= (GLCD_PORT_IN_DB1 << 1);
    d |= (GLCD_PORT_IN_DB2 << 2);
    d |= (GLCD_PORT_IN_DB3 << 3);
    d |= (GLCD_PORT_IN_DB4 << 4);
    d |= (GLCD_PORT_IN_DB5 << 5);
    d |= (GLCD_PORT_IN_DB6 << 6);
    d |= (GLCD_PORT_IN_DB7 << 7);
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

