#include "typedef.h"
#include "tickTimer.h"
#include "timer.h"
void tickTimerInterrupt(void)
{
#ifdef USE_TIMER2
    timerInterrupt2();
#endif
#ifdef USE_TIMER4
    timerInterrupt4();
#endif
#ifdef USE_TIMER6
    timerInterrupt6();
#endif
}
