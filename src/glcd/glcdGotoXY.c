#include  "typedef.h"

extern void glcdSetPage(UINT_8 page,UINT_8 cs);
extern void glcdSetAddress(UINT_8 address,UINT_8 cs);

void glcdGotoXY(UINT_8 x, UINT_8 y)
{
    UINT_8 seg;
    UINT_8 page;
    UINT_8 cs;

    cs = (x >> 6);
    cs = cs + 1;

    seg = x % 64;

    page = ((y >> 3) & 0x07);

    glcdSetPage(page,cs);
    glcdSetAddress(seg,cs);

}
