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

extern void TMR2Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
extern void TMR4Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
extern void TMR6Init(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);


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

