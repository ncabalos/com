#include "typedef.h"
#include "glcd.h"

void glcdDrawString(UINT_8 x, UINT_8 y, char *s,BOOL fill)
{
    UINT_8 i = 0;
    char c;

    while( (c = *s++) != '\0')
    {
        glcdDrawChar(x + (i * 6),y,c,fill);
        i++;
    }
}
