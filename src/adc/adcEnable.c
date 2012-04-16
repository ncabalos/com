#include "typedef.h"
#include "adc.h"

extern void setADON(BOOL b);

void adcEnable(BOOL b)
{
    setADON(b);
}
