#include "typedef.h"
#include "serialio.h"

char serialioGetChar(SERIALIO *self)
{
    char c;
    c = self->rxBuffer[self->rxOut];
    self->rxOut++;
    if(self->rxOut == BUFFSIZE) self->rxOut = 0;
    self->rxCount--;
    return c;
}
