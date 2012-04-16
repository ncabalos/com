#include <htc.h>
#include "typedef.h"

char getRxChar1(void)
{
    return RCREG1;
}
char getRxChar2(void)
{
    return RCREG2;
}

BOOL isRC1IE(void)
{
    return PIE1bits.RC1IE;
}
BOOL isRC1IF(void)
{
    return PIR1bits.RC1IF;
}
BOOL isRC2IE(void)
{
    return PIE3bits.RC2IE;
}
BOOL isRC2IF(void)
{
    return PIR3bits.RC2IF;
}

BOOL isTX1IE(void)
{
    return PIE1bits.TX1IE;
}
BOOL isTX1IF(void)
{
    return PIR1bits.TX1IF;
}
BOOL isTX2IE(void)
{
    return PIE3bits.TX2IE;
}
BOOL isTX2IF(void)
{
    return PIR3bits.TX2IF;
}

void setTX1IE(BOOL b)
{
    PIE1bits.TX1IE = b;
}

void setTX2IE(BOOL b)
{
    PIE3bits.TX2IE = b;
}

void setTX1Char(char c)
{
    TXREG1 = c;
}

void setTX2Char(char c)
{
    TXREG2 = c;
}
