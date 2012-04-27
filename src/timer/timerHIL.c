/**
 * @file timerHIL.c
 *
 * @ingroup timerGroup
 *
 */
#include <htc.h>
#include "typedef.h"
#include "timer.h"

void timerInit1HIL(void);

void timerInit2HIL(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
    T2CONbits.T2CKPS = pre;
    T2CONbits.T2OUTPS = post;
    PR2 = pr - 1;

    if(intrp)
    {
        PIR1bits.TMR2IF = 0;
        PIE1bits.TMR2IE = 1;
    }
}
void timerInit3HIL(void);

void timerInit4HIL(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
    T4CONbits.T4CKPS = pre;
    T4CONbits.T4OUTPS = post;
    PR4 = pr - 1;

    if(intrp)
    {
        PIR5bits.TMR4IF = 0;
        PIE5bits.TMR4IE = 1;
    }
}
void timerInit5HIL(void);

void timerInit6HIL(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
    T6CONbits.T6CKPS = pre;
    T6CONbits.T6OUTPS = post;
    PR6 = pr - 1;

    if(intrp)
    {
        PIR5bits.TMR6IF = 0;
        PIE5bits.TMR6IE = 1;
    }
}

void timerInterrupt1HIL(void);
void timerInterrupt2HIL(void)
{
    if(PIR1bits.TMR2IF && PIE1bits.TMR2IE)
    {
        PIR1bits.TMR2IF = 0;
        timerInterruptTask2();
    }
}
void timerInterrupt3HIL(void);
void timerInterrupt4HIL(void)
{
    if(PIR5bits.TMR4IF && PIE5bits.TMR4IE)
    {
        PIR5bits.TMR4IF = 0;
        timerInterruptTask4();
    }
}
void timerInterrupt5HIL(void);
void timerInterrupt6HIL(void)
{
    if(PIR5bits.TMR6IF && PIE5bits.TMR6IE)
    {
        PIR5bits.TMR6IF = 0;
        timerInterruptTask6();
    }
}

void timerSetEnable1HIL(BOOL b)
{
    T1CONbits.TMR1ON = b;
}
void timerSetEnable2HIL(BOOL b)
{
    T2CONbits.TMR2ON = b;
}
void timerSetEnable3HIL(BOOL b)
{
    T3CONbits.TMR3ON = b;
}
void timerSetEnable4HIL(BOOL b)
{
    T4CONbits.TMR4ON = b;
}
void timerSetEnable5HIL(BOOL b)
{
    T5CONbits.TMR5ON = b;
}
void timerSetEnable6HIL(BOOL b)
{
    T6CONbits.TMR6ON = b;
}
