#include "typedef.h"
#include "serialio.h"

void serialioTxInterrupt(SERIALIO *self) {
    BOOL b;
    switch (self->uartNum) {
        case USART1:
            b = isInterruptEnableTX1HIL() && isInterruptFlagTX1HIL();
            break;
        case USART2:
            b = isInterruptEnableTX2HIL() && isInterruptFlagTX2HIL();
            break;
        default:
            break;
    }
    if (b) {
        switch (self->uartNum) {
            case USART1:
                setCharTX1HIL(self->txBuffer[self->txOut]);
                break;
            case USART2:
                setCharTX2HIL(self->txBuffer[self->txOut]);
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
                    setInterruptEnableTX1HIL(FALSE);
                    break;
                case USART2:
                    setInterruptEnableTX2HIL(FALSE);
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
            b = isInterruptEnableRC1HIL() && isInterruptFlagRC1HIL();
            break;
        case USART2:
            b = isInterruptEnableRC2HIL() && isInterruptFlagRC2HIL();
            break;
        default:
            break;
    }


    if (b) {
        switch (self->uartNum) {
            case USART1:
                c = getCharRC1HIL();
                break;
            case USART2:
                c = getCharRC2HIL();
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
