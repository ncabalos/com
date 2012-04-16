#ifndef GLCD_H
#define GLCD_H

#define GLCD_WRITE  0
#define GLCD_READ   1

#define GLCD_COL_1

void glcdInit(void);



void glcdWriteByte(UINT_8 b);
UINT_8 glcdReadByte(void);

#endif