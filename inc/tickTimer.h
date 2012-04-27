/**
 * @file tickTimer.h
 *
 * @brief Header file for functions for implementing a tick timer
 *
 * @author Nathaniel Abalos
 *
 * @defgroup tickTimerGroup Tick Timer
 *
 * @ingroup tickTimerGroup
 */
#ifndef TICKTIMER_H
#define TICKTIMER_H

#define USE_TIMER2
//#define USE_TIMER4
//#define USE_TIMER6

void tickTimerInit(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
void tickTimerInterrupt(void);
void tickTimerEnable(BOOL b);

/**
 * @brief This function is used to perform any function that needs a time base
 *
 * This function performs tick based functions. This function must be
 * implemented in the main program loop. This is only applicable if the timer is
 * running off an interrupt.
 */
extern void tickTimerInterruptTask(void);

#endif
