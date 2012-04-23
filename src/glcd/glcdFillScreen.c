#include "typedef.h"
#include "glcd.h"

extern void glcdWriteRam(UINT_8 data, UINT_8 x, UINT_8 page);
void glcdFillScreen(void)
{
    UINT_8 x;
    UINT_8 page;

    for(page = 0; page < 8; page++)
    {
        for(x = 0; x < 128; x++)
        {
            glcdWriteRam(0xFF,x,page);
        }
    }
}
