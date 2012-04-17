#include "typedef.h"
#include "glcd.h"


extern void glcdWriteData(UINT_8 data,UINT_8 cs);
extern void glcdSetPage(UINT_8 page,UINT_8 cs);
extern void glcdSetAddress(UINT_8 address,UINT_8 cs);

void glcdClearScreen(void)
{
    UINT_8 x;
    UINT_8 page;
    UINT_8 cs;

    for(page = 0; page < 8; page++)
    {
        for(x = 0; x < 128; x++)
        {
            cs = (x >> 6);
            cs = cs + 1;
            glcdSetAddress(x,cs);
            glcdSetPage(page,cs);
            glcdWriteData(0x00,cs);

        }
    }
}
