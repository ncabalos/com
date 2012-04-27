#include "typedef.h"
#include "serialio.h"

void serialioGetString(SERIALIO *self, char *buff)
{
    char *ptr;
    char c;

    ptr = buff;
    do
    {
        c = serialioGetChar(self);
        *ptr++ = c;
    }while(c != '\0');
    *ptr = 0;
    self->isStringAvailable = FALSE;
}
