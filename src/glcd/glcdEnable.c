#include "typedef.h"
#include "glcd.h"

extern void glcdWriteInstruction(UINT_8 data,UINT_8 cs);
extern void glcdSetPage(UINT_8 page,UINT_8 cs);
extern void glcdSetAddress(UINT_8 address,UINT_8 cs);

void glcdEnable(BOOL b)
{

    glcdWriteInstruction(0x3F,1);
    glcdWriteInstruction(0x3F,2);
    glcdClearScreen();
    glcdSetPage(0,1);
    glcdSetAddress(0,1);
    glcdSetPage(0,2);
    glcdSetAddress(0,2);
}
