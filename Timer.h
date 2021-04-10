/*
 * Timer.h
 *
 * Created: 09/04/2021 1:40:49 PM
 *  Author: Mark Fayez
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Bit_math.h"
#include "MCU.h"

#define CLK_FREQ			16
#define	TIMER0_PRESCALAR	1024
#define TIMER0_REG_SIZE		8

#define TIMER0_TICKS		(1 << TIMER0_REG_SIZE) /* == (2 ^ TIMER0_REG_SIZE) == 256 */
#define TIMER0_TICK_TIME	(float64)(TIMER0_PRESCALAR / CLK_FREQ)


void Timer0_Init(void);

void Timer0_SetDelay(uint32 Delay_Ms);

void Timer0_Start(void);

void Timer0_Stop(void);

void Set_Timer0_CallBack(void (*P)(void));

#endif /* TIMER_H_ */