#include <htc.h>
#include "typedef.h"
#include "tickTimer.h"

void setTMR2Enable(BOOL b)
{
    T2CONbits.TMR2ON = b;
}

void setTMR4Enable(BOOL b)
{
    T4CONbits.TMR4ON = b;
}

void setTMR6Enable(BOOL b)
{
    T6CONbits.TMR6ON = b;
}

void TMR2Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
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

void TMR4Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
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

void TMR6Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
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

void TMR2Interrupt(void)
{
    if(PIR1bits.TMR2IF && PIE1bits.TMR2IE)
    {
        PIR1bits.TMR2IF = 0;
        tickTimerInterruptTask();
    }
}
void TMR4Interrupt(void)
{
    if(PIR5bits.TMR4IF && PIE5bits.TMR4IE)
    {
        PIR5bits.TMR4IF = 0;
        tickTimerInterruptTask();
    }
}
void TMR6Interrupt(void)
{
    if(PIR5bits.TMR6IF && PIE5bits.TMR6IE)
    {
        PIR5bits.TMR6IF = 0;
        tickTimerInterruptTask();
    }
}
