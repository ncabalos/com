#include "typedef.h"
#include "tickTimer.h"

extern void setTMR2Enable(BOOL b);
extern void setTMR4Enable(BOOL b);
extern void setTMR6Enable(BOOL b);

void tickTimerEnable(BOOL b)
{
#ifdef TIMER2
    setTMR2Enable(b);
#endif
#ifdef TIMER4
    setTMR4Enable(b);
#endif
#ifdef TIMER6
    setTMR6Enable(b);
#endif
}
