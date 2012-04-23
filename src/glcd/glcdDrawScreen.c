#include "typedef.h"
#include "glcd.h"
extern void glcdSetPage(UINT_8 page,UINT_8 cs);
extern void glcdSetAddress(UINT_8 address,UINT_8 cs);
extern void glcdWriteData(UINT_8 data,UINT_8 cs);
void glcdDrawScreen(void)
{
    UINT_8 x = 0;
    UINT_8 page = 0;
    UINT_8 cs = 0;
    
    for(page = 0; page < 8; page++)
    {
        for(x = 0; x < 128; x++)
        {
            cs = (x >> 6);
            cs = cs + 1;
            glcdSetAddress(x,cs);
            glcdSetPage(page,cs);
            glcdWriteData(glcdRam[x][page],cs);
        }
    }
}
