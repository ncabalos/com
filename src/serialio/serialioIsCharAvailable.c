#include "typedef.h"
#include "serialio.h"

BOOL serialioIsCharAvailable(SERIALIO *self)
{
    if(self->rxCount == 0) return FALSE;
    else return TRUE;
}
