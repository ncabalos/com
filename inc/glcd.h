#ifndef GLCD_H
#define GLCD_H


#define GLCD_PIN_DI     LATDbits.LATD1
#define GLCD_PIN_RW     LATDbits.LATD2
#define GLCD_PIN_E      LATDbits.LATD3
#define GLCD_PIN_CS1    LATCbits.LATC4
#define GLCD_PIN_CS2    LATCbits.LATC5
#define GLCD_PIN_RST    LATCbits.LATC6

#define GLCD_PORT_OUT_DB0   LATBbits.LATB0
#define GLCD_PORT_OUT_DB1   LATBbits.LATB1
#define GLCD_PORT_OUT_DB2   LATBbits.LATB2
#define GLCD_PORT_OUT_DB3   LATBbits.LATB3
#define GLCD_PORT_OUT_DB4   LATAbits.LATA0
#define GLCD_PORT_OUT_DB5   LATAbits.LATA1
#define GLCD_PORT_OUT_DB6   LATAbits.LATA2
#define GLCD_PORT_OUT_DB7   LATAbits.LATA3

#define GLCD_PORT_IN_DB0   PORTBbits.RB0
#define GLCD_PORT_IN_DB1   PORTBbits.RB1
#define GLCD_PORT_IN_DB2   PORTBbits.RB2
#define GLCD_PORT_IN_DB3   PORTBbits.RB3
#define GLCD_PORT_IN_DB4   PORTAbits.RA0
#define GLCD_PORT_IN_DB5   PORTAbits.RA1
#define GLCD_PORT_IN_DB6   PORTAbits.RA2
#define GLCD_PORT_IN_DB7   PORTAbits.RA3

#define GLCD_PORT_DIR_DB0   TRISBbits.TRISB0
#define GLCD_PORT_DIR_DB1   TRISBbits.TRISB1
#define GLCD_PORT_DIR_DB2   TRISBbits.TRISB2
#define GLCD_PORT_DIR_DB3   TRISBbits.TRISB3
#define GLCD_PORT_DIR_DB4   TRISAbits.TRISA0
#define GLCD_PORT_DIR_DB5   TRISAbits.TRISA1
#define GLCD_PORT_DIR_DB6   TRISAbits.TRISA2
#define GLCD_PORT_DIR_DB7   TRISAbits.TRISA3

#define GLCD_WRITE  0
#define GLCD_READ   1

#define GLCD_COL_1

void glcdInit(void);

//void glcdWriteByte(UINT_8 b);
//UINT_8 glcdReadByte(void);

void glcdEnable(BOOL b);

void glcdClearScreen(void);
void glcdFillScreen(void);
void glcdGotoXY(UINT_8 x, UINT_8 y);
void glcdDrawPixel(UINT_8 x, UINT_8 y);
void glcdClearPixel(UINT_8 x, UINT_8 y);
void glcdDrawLine(UINT_8 x_start, UINT_8 y_start, UINT_8 x_end, UINT_8 y_end);
void glcdDrawCircle(UINT_8 x, UINT_8 y, UINT_8 r);
void glcdDrawChar(UINT_8 x, UINT_8 y, char c);
void glcdDrawString(UINT_8 x, UINT_8 y, char *s);


#endif