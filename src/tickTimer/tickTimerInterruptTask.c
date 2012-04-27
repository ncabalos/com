#include "typedef.h"
#include "tickTimer.h"
#include "timer.h"

#ifdef USE_TIMER2
void timerInterruptTask2(void)
{
    tickTimerInterruptTask();
}
#endif
#ifdef USE_TIMER4
void timerInterruptTask4(void)
{
    tickTimerInterruptTask();
}
#endif
#ifdef USE_TIMER6
void timerInterruptTask6(void)
{
    tickTimerInterruptTask();
}
#endif
