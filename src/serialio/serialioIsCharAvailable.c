#include "typedef.h"
#include "serialio.h"

BOOL serialioIsCharAvailable(SERIALIO *self)
{
    return self->rxCount;
}
