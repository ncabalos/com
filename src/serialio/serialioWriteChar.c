#include "typedef.h"
#include "serialio.h"

extern void setTX1IE(BOOL);
extern void setTX2IE(BOOL);

void serialioWriteChar(SERIALIO *self,char c)
{
    self->txBuffer[self->txIn] = c;
    self->txIn++;
    if(self->txIn == BUFFSIZE) self->txIn = 0;
    self->txCount++;

    switch(self->uartNum)
    {
        case USART1:
            setTX1IE(TRUE);
            break;
        case USART2:
            setTX2IE(TRUE);
            break;
        default:
            break;
    }
    
}
