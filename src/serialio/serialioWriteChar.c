#include "typedef.h"
#include "serialio.h"

void serialioWriteChar(SERIALIO *self,char c)
{
    self->txBuffer[self->txIn] = c;
    self->txIn++;
    if(self->txIn == BUFFSIZE) self->txIn = 0;
    self->txCount++;

    switch(self->uartNum)
    {
        case USART1:
            setInterruptEnableTX1HIL(TRUE);
            break;
        case USART2:
            setInterruptEnableTX2HIL(TRUE);
            break;
        default:
            break;
    }
    
}
