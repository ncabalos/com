#include "typedef.h"
#include "serialio.h"

BOOL serialioIsStringAvailable(SERIALIO *self)
{
    return self->isStringAvailable;
}
