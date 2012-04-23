#ifndef GLCD_H
#define GLCD_H


#define GLCD_PIN_DI     LATDbits.LATD1
#define GLCD_PIN_RW     LATDbits.LATD2
#define GLCD_PIN_E      LATDbits.LATD3
#define GLCD_PIN_CS1    LATCbits.LATC4
#define GLCD_PIN_CS2    LATCbits.LATC5
#define GLCD_PIN_RST    LATCbits.LATC6

#define GLCD_PORT_OUT       PORTA
#define GLCD_PORT_IN        PORTA
#define GLCD_PORT_DIR       TRISAbits.TRISA


#define GLCD_WRITE  0
#define GLCD_READ   1

#define GLCD_COL_1

#define GLCD_PIXEL_CLEAR 0
#define GLCD_PIXEL_FILL 1

UINT_8 glcdRam[128][8];

void glcdInit(void);
void glcdEnable(BOOL b);
void glcdClearScreen(void);
void glcdFillScreen(void);
void glcdGotoXY(UINT_8 x, UINT_8 y);
void glcdDrawPixel(UINT_8 x, UINT_8 y, BOOL fill);
void glcdDrawLine(UINT_8 x_start, UINT_8 y_start, UINT_8 x_end, UINT_8 y_end,BOOL fill);
void glcdDrawRectangle(UINT_8 x, UINT_8 y, UINT_8 w, UINT_8 h,BOOL fill);
void glcdDrawCircle(UINT_8 x, UINT_8 y, UINT_8 r,BOOL fill);
void glcdDrawChar(UINT_8 x, UINT_8 y, char c,BOOL fill);
void glcdDrawString(UINT_8 x, UINT_8 y, char *s,BOOL fill);
void glcdDrawScreen(void);

extern void delayMs(UINT_16 ms);

#endif