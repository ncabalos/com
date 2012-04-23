#include "typedef.h"
#include "glcd.h"

extern void glcdWriteInstruction(UINT_8 data,UINT_8 cs);

void glcdEnable(BOOL b)
{
    if(b == TRUE)
    {
        glcdWriteInstruction(0x3F,1);
        glcdWriteInstruction(0x3F,2);
    }
    else
    {
        glcdWriteInstruction(0x3E,1);
        glcdWriteInstruction(0x3E,2);
    }  
}
