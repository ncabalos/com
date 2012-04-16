#ifndef TICKTIMER_H
#define TICKTIMER_H

#define TIMER2
//#define TIMER4
//#define TIMER6

#define TIMER_PRESCALE_1    0
#define TIMER_PRESCALE_4    1
#define TIMER_PRESCALE_16   2

#define TIMER_POSTSCALE_1   0
#define TIMER_POSTSCALE_2   1
#define TIMER_POSTSCALE_3   2
#define TIMER_POSTSCALE_4   3
#define TIMER_POSTSCALE_5   4
#define TIMER_POSTSCALE_6   5
#define TIMER_POSTSCALE_7   6
#define TIMER_POSTSCALE_8   7
#define TIMER_POSTSCALE_9   8
#define TIMER_POSTSCALE_10   9
#define TIMER_POSTSCALE_11   10
#define TIMER_POSTSCALE_12   11
#define TIMER_POSTSCALE_13   12
#define TIMER_POSTSCALE_14   13
#define TIMER_POSTSCALE_15   14
#define TIMER_POSTSCALE_16   15

void tickTimerInit(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
void tickTimerInterrupt(void);
void tickTimerEnable(BOOL b);

extern void tickTimerInterruptTask(void);

#endif
