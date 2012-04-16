#include "typedef.h"
#include "serialio.h"

void serialioWriteString(SERIALIO * self,char *s)
{
    char c;
    while((c = *s++) != '\0') serialioWriteChar(self,c);
}
