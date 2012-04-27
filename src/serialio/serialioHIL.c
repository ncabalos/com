#include <htc.h>
#include "typedef.h"

char getCharRC1HIL(void)
{
    return RCREG1;
}
char getCharRC2HIL(void)
{
    return RCREG2;
}

BOOL isInterruptEnableRC1HIL(void)
{
    return PIE1bits.RC1IE;
}
BOOL isInterruptFlagRC1HIL(void)
{
    return PIR1bits.RC1IF;
}
BOOL isInterruptEnableRC2HIL(void)
{
    return PIE3bits.RC2IE;
}
BOOL isInterruptFlagRC2HIL(void)
{
    return PIR3bits.RC2IF;
}

BOOL isInterruptEnableTX1HIL(void)
{
    return PIE1bits.TX1IE;
}
BOOL isInterruptFlagTX1HIL(void)
{
    return PIR1bits.TX1IF;
}
BOOL isInterruptEnableTX2HIL(void)
{
    return PIE3bits.TX2IE;
}
BOOL isInterruptFlagTX2HIL(void)
{
    return PIR3bits.TX2IF;
}

void setInterruptEnableTX1HIL(BOOL b)
{
    PIE1bits.TX1IE = b;
}

void setInterruptEnableTX2HIL(BOOL b)
{
    PIE3bits.TX2IE = b;
}

void setCharTX1HIL(char c)
{
    TXREG1 = c;
}

void setCharTX2HIL(char c)
{
    TXREG2 = c;
}
