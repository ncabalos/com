#ifndef SERIALIO_H
#define SERIALIO_H

#define BUFFSIZE 50
#define USART1 1
#define USART2 2



typedef struct
{
    volatile UINT_8 txBuffer[BUFFSIZE];
    volatile UINT_8 txOut;
    volatile UINT_8 txIn;
    volatile UINT_8 txCount;

    volatile UINT_8 rxBuffer[BUFFSIZE];
    volatile UINT_8 rxOut;
    volatile UINT_8 rxIn;
    volatile UINT_8 rxCount;
    volatile BOOL isStringAvailable;

    UINT_8 uartNum;
}SERIALIO;



SERIALIO * serialioInit(UINT_8 num, UINT_8 baud);
void serialioWriteString(SERIALIO * self, char *s);
void serialioWriteChar(SERIALIO * self,char c);
char serialioGetChar(SERIALIO * self);
void serialioGetString(SERIALIO * self,char *buff);
void serialioTxInterrupt(SERIALIO * self);
char serialioRxInterrupt(SERIALIO *self);
BOOL serialioIsCharAvailable(SERIALIO * self);
void serialioWriteStringPolling(SERIALIO * self,char *s);
void serialioWriteCharPolling(SERIALIO * self,char c);
void serialioFlushRxBuffer(SERIALIO * self);
BOOL serialioIsStringAvailable(SERIALIO * self);

#endif