#include <htc.h>
#include "typedef.h"
#include "glcd.h"

extern UINT_8 glcdReadRam(UINT_8 x, UINT_8 page);
extern void glcdWriteRam(UINT_8 data, UINT_8 x, UINT_8 page);
void glcdDrawPixel(UINT_8 x, UINT_8 y, BOOL fill)
{
    UINT_8 page;
    UINT_8 dot;
    UINT_8 cs;
    UINT_8 seg;

    UINT_8 tmp;

    UINT_8 data = 0;

    page = ((y >> 3) & 0x07);
    dot = y % 8;

    data = (0x01 << dot);

    if(fill == GLCD_PIXEL_CLEAR) data = ~data;

    seg = x % 64;

    tmp = glcdReadRam(x,page);

    if(fill == GLCD_PIXEL_FILL)
        data |= tmp;
    else
        data &= tmp;

    glcdWriteRam(data,x,page);
}
