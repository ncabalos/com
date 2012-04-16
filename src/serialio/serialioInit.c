#include <htc.h>
#include "typedef.h"
#include "serialio.h"

static SERIALIO serialio_1;
static SERIALIO serialio_2;

//extern void initUSART1(UINT_8 setting);
//extern void initUSART2(UINT_8 setting);

SERIALIO * serialioInit(UINT_8 num, UINT_8 baud) {
    SERIALIO *serial;
    switch (num) {
        case USART1:
            serial = &serialio_1;
            TXSTA1bits.SYNC = 0;
            TXSTA1bits.TXEN = 1;
            TXSTA1bits.BRGH = 1;

            PIE1bits.TX1IE = 0;
            PIR1bits.TX1IF = 0;
            SPBRG1 = 34;

            RCSTA1bits.CREN = 1;
            RCSTA1bits.SPEN = 1;


            ANSELCbits.ANSC6 = 0;
            ANSELCbits.ANSC7 = 0;
            TRISCbits.TRISC7 = 1;
            TRISCbits.TRISC6 = 1;

            PIE1bits.RC1IE = 1;
            break;
        case USART2:
            serial = &serialio_2;
            TXSTA2bits.SYNC = 0;
            TXSTA2bits.TXEN = 1;
            TXSTA2bits.BRGH = 1;

            PIE3bits.TX2IE = 0;
            PIR3bits.TX2IF = 0;
            SPBRG2 = 34;

            RCSTA2bits.CREN = 1;
            RCSTA2bits.SPEN = 1;


            ANSELDbits.ANSD6 = 0;
            ANSELDbits.ANSD7 = 0;
            TRISDbits.TRISD7 = 1;
            TRISDbits.TRISD6 = 1;

            PIE3bits.RC2IE = 1;
            break;
        default:
            break;
    }

    serial->rxCount = 0;
    serial->rxIn = 0;
    serial->rxOut = 0;
    serial->txCount = 0;
    serial->txIn = 0;
    serial->txOut = 0;
    serial->uartNum = num;

    return serial;
}
