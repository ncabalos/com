/**
 * @file tickTimerInit.c
 *
 * @brief This file contains implementation for initializing a tick timer
 *
 * @author Nathaniel Abalos
 *
 * @ingroup tickTimerGroup
 */

#include "typedef.h"
#include "tickTimer.h"
#include "timer.h"

/**
 * @brief This function sets up a timer as a tick timer.
 *
 * 
 *
 * @param pre This is the prescale value
 * @param post This is the postscale value
 * @param intrp This specifies whether interrupts will be used
 * @param pr This is the compare value
 */
void tickTimerInit(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr)
{
#ifdef USE_TIMER2
    timerInit2(pre,post,intrp,pr);
#endif
#ifdef USE_TIMER4
    timerInit4(pre,post,intrp,pr);
#endif
#ifdef USE_TIMER6
    timerInit6(pre,post,intrp,pr);
#endif
}

