#include "typedef.h"
#include "glcd.h"

extern UINT_8 glcdReadData(UINT_8 cs);
extern void glcdWriteData(UINT_8 data,UINT_8 cs);


void glcdDrawPixel(UINT_8 x, UINT_8 y)
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

    cs = (x >> 6);
    cs = cs + 1;

    seg = x % 64;


    glcdGotoXY(x,y);
    tmp = glcdReadData(cs);
    glcdGotoXY(x,y);
    tmp = glcdReadData(cs);


    data |= tmp;

    glcdGotoXY(x,y);
    glcdWriteData(data,cs);


}
