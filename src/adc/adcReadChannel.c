#include "typedef.h"
#include "adc.h"

extern UINT_16 adcRead(UINT_8 channel);

UINT_16 adcReadChannel(UINT_8 channel, UINT_16 sample)
{
    UINT_8 i = 0;
    UINT_8 j = 0;
    UINT_16 sum = 0;
    for(i = 0; i < sample; i++)
    {
        j = 30; while(j--);
        sum += adcRead(channel);
    }
    sum /= sample;
    return sum;
}
