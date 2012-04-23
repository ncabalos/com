#include "typedef.h"
#include "glcd.h"

extern const UINT_8 glcdFont[][6];

void glcdDrawChar(UINT_8 x, UINT_8 y, char c,BOOL fill)
{
    UINT_8 i;
    UINT_8 j;
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(((glcdFont[c][i] >> j)&0x01))
                glcdDrawPixel(x+i,y+j,fill);
        }
    }
}
