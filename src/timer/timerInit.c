/**
 * @file timerInit.c
 *
 * @ingroup timerGroup
 */
#include "typedef.h"
#include "timer.h"

void timerInit1(void);
void timerInit2(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
    timerInit2HIL(pre,post,intrp,pr);
}
void timerInit3(void);
void timerInit4(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
    timerInit4HIL(pre,post,intrp,pr);
}
void timerInit5(void);
void timerInit6(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
    timerInit6HIL(pre,post,intrp,pr);
}
