/**
 * HARDWARE INTERFACE LAYER
 * Hardware: PIC
 */
#include <htc.h>
#include "typedef.h"

void setTRIGSEL(UINT_8 i)
{
    ADCON1bits.TRIGSEL = i;
}

void setPVCFG(UINT_8 i)
{
    ADCON1bits.PVCFG = i;
}

void setNVCFG(UINT_8 i)
{
    ADCON1bits.NVCFG = i;
}

void setADFM(UINT_8 i)
{
    ADCON2bits.ADFM = i;
}

void setACQT(UINT_8 i)
{
    ADCON2bits.ACQT = i;
}

void setADCS(UINT_8 i)
{
    ADCON2bits.ADCS = i;
}

void setADON(BOOL b)
{
    ADCON0bits.ADON = b;
}

UINT_16 adcRead(UINT_8 channel)
{
    ADCON0bits.CHS = channel;
    ADCON0bits.GODONE = 1;
    while(ADCON0bits.GODONE);
    return (ADRESH << 8) + ADRESL;
}