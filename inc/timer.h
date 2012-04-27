/**
 * @file timer.h
 *
 * @defgroup timerGroup Timer
 */
#ifndef TIMER_H
#define TIMER_H

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

void timerInit1(void);
void timerInit2(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
void timerInit3(void);
void timerInit4(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
void timerInit5(void);
void timerInit6(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);

void timerSetEnable1(BOOL b);
void timerSetEnable2(BOOL b);
void timerSetEnable3(BOOL b);
void timerSetEnable4(BOOL b);
void timerSetEnable5(BOOL b);
void timerSetEnable6(BOOL b);

void timerInterrupt1(void);
void timerInterrupt2(void);
void timerInterrupt3(void);
void timerInterrupt4(void);
void timerInterrupt5(void);
void timerInterrupt6(void);

void timerInterruptTask1(void);
void timerInterruptTask2(void);
void timerInterruptTask3(void);
void timerInterruptTask4(void);
void timerInterruptTask5(void);
void timerInterruptTask6(void);

extern void timerInit1HIL(void);
extern void timerInit2HIL(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
extern void timerInit3HIL(void);
extern void timerInit4HIL(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);
extern void timerInit5HIL(void);
extern void timerInit6HIL(UINT_8 pre, UINT_8 post, BOOL intrp, UINT_8 pr);

extern void timerInterrupt1HIL(void);
extern void timerInterrupt2HIL(void);
extern void timerInterrupt3HIL(void);
extern void timerInterrupt4HIL(void);
extern void timerInterrupt5HIL(void);
extern void timerInterrupt6HIL(void);

extern void timerSetEnable1HIL(BOOL b);
extern void timerSetEnable2HIL(BOOL b);
extern void timerSetEnable3HIL(BOOL b);
extern void timerSetEnable4HIL(BOOL b);
extern void timerSetEnable5HIL(BOOL b);
extern void timerSetEnable6HIL(BOOL b);

#endif
