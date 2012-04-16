#include "typedef.h"
#include "serialio.h"

extern BOOL isTX1IE(void);
extern BOOL isTX1IF(void);
extern BOOL isTX2IE(void);
extern BOOL isTX2IF(void);
extern BOOL isRC1IE(void);
extern BOOL isRC1IF(void);
extern BOOL isRC2IE(void);
extern BOOL isRC2IF(void);

extern void setTX1Char(char);
extern void setTX2Char(char);
extern char getRxChar1(void);
extern char getRxChar2(void);

extern void setTX1IE(BOOL);
extern void setTX2IE(BOOL);

void serialioTxInterrupt(SERIALIO *self) {
    BOOL b;
    switch (self->uartNum) {
        case USART1:
            b = isTX1IE() && isTX1IF();
            break;
        case USART2:
            b = isTX2IE() && isTX2IF();
            break;
        default:
            break;
    }
    if (b) {
        switch (self->uartNum) {
            case USART1:
                setTX1Char(self->txBuffer[self->txOut]);
                break;
            case USART2:
                setTX2Char(self->txBuffer[self->txOut]);
                break;
            default:
                break;
        }
        self->txOut++;
        if (self->txOut == BUFFSIZE) self->txOut = 0;
        self->txCount--;
        if (!self->txCount) {
            switch (self->uartNum) {
                case USART1:
                    setTX1IE(FALSE);
                    break;
                case USART2:
                    setTX2IE(FALSE);
                    break;
                default:
                    break;
            }
        }

    }
}

char serialioRxInterrupt(SERIALIO *self) {
    char c;
    BOOL b;

    switch (self->uartNum) {
        case USART1:
            b = isRC1IE() && isRC1IF();
            break;
        case USART2:
            b = isRC2IE() && isRC2IF();
            break;
        default:
            break;
    }


    if (b) {
        switch (self->uartNum) {
            case USART1:
                c = getRxChar1();
                break;
            case USART2:
                c = getRxChar2();
                break;
            default:
                break;
        }

        self->rxBuffer[self->rxIn] = c;
        self->rxIn++;
        if (self->rxIn == BUFFSIZE) self->rxIn = 0;
        self->rxCount++;

        if (c == '\r') {
            self->rxBuffer[self->rxIn] = '\0';
            self->rxIn++;
            if (self->rxIn == BUFFSIZE) self->rxIn = 0;
            self->rxCount++;
            self->isStringAvailable = TRUE;
        }
    }
    return c;
}
