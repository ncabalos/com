#include <htc.h>
#include "typedef.h"

void setFVRS(UINT_8 ref)
{
    VREFCON0bits.FVRS = ref;
}
void setFVREN(BOOL b)
{
    VREFCON0bits.FVREN = b;
    while(!VREFCON0bits.FVRST);
}
