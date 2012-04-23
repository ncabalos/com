#include "typedef.h"
#include "glcd.h"

void glcdDrawRectangle(UINT_8 x, UINT_8 y, UINT_8 w, UINT_8 h,BOOL fill)
{
    if(!w) w = 1;
    if(!h) h = 1;
    glcdDrawLine(x,y,x+w,y,fill);
    glcdDrawLine(x,y,x,y+h,fill);
    glcdDrawLine(x+w-1,y,x+w-1,y+h,fill);
    glcdDrawLine(x,y+h-1,x+w,y+h-1,fill);
}
