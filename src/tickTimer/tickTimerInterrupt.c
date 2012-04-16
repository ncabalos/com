#include "typedef.h"
#include "tickTimer.h"

extern void TMR2Interrupt(void);
extern void TMR4Interrupt(void);
extern void TMR6Interrupt(void);

void tickTimerInterrupt(void)
{
#ifdef TIMER2
    TMR2Interrupt();
#endif
#ifdef TIMER4
    TMR4Interrupt();
#endif
#ifdef TIMER6
    TMR6Interrupt();
#endif
}
