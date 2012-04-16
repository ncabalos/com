#include "typedef.h"
#include "tickTimer.h"

extern void TMR2Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
extern void TMR4Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
extern void TMR6Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);

void tickTimerInit(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
#ifdef TIMER2
    TMR2Init(pre,post,intrp,pr);
#endif
#ifdef TIMER4
    TMR4Init(pre,post,intrp,pr);
#endif
#ifdef TIMER6
    TMR6Init(pre,post,intrp,pr);
#endif
}

