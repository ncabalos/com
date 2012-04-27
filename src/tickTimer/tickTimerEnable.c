#include "typedef.h"
#include "tickTimer.h"
#include "timer.h"

void tickTimerEnable(BOOL b)
{
#ifdef USE_TIMER2
    timerSetEnable2(b);
#endif
#ifdef USE_TIMER4
    timerSetEnable4(b);
#endif
#ifdef USE_TIMER6
    timerSetEnable6(b);
#endif
}
