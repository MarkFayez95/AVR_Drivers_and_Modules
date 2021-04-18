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
#include "Timer_Structures.h"

/******************Timers Configuration options******************/
#define	PRESC_OFF	1
#define	PRESC_8		8
#define	PRESC_64	64
#define	PRESC_256	256
#define	PRESC_1024	1024

#define REG_SI_8	8
#define REG_SI_10	10
#define REG_SI_16	16
#define REG_SI_24	24
#define REG_SI_32	32


/****************** Timers Constrains / Settings ******************/
#define CLK_FREQ	16

#define	TIMER0_PRESCALAR	PRESC_1024
#define TIMER0_REG_SIZE		REG_SI_8

#define	TIMER1_PRESCALAR	PRESC_1024
#define TIMER1_REG_SIZE		REG_SI_16

#define Max_Ticks(Ticks,Reg_Size)		Ticks=((uint32)1<<Reg_Size)
#define Tick_Time_Calc(Tick_Time,Presc,Clk)     Tick_Time=(float64)(Presc/Clk)

#define TIMER0_TICKS		((uint32)1 << TIMER0_REG_SIZE) /* == (2 ^ TIMER0_REG_SIZE) == 256 */
#define TIMER0_TICK_TIME	(float64)(TIMER0_PRESCALAR / CLK_FREQ)

#define TIMER1_TICKS		((uint32)1 << TIMER1_REG_SIZE) /* == (2 ^ TIMER0_REG_SIZE) == 65535 */
#define TIMER1_TICK_TIME	(float64)(TIMER1_PRESCALAR / CLK_FREQ)

#define PWM1_TOP_VALUE	1250


#define CS0_MASK    0x07

/******************Timer 0******************/
void Timer0_Init(void);
void Timer0_SetDelay(uint32 Delay_Ms);
void Timer0_Start(void);
void Timer0_Stop(void);
void Set_Timer0_CallBack(void (*P)(void));

/******************Timer 1******************/
void Timer1_Init(void);
void Timer1_SetDelay(uint32 Delay_Ms);
void Timer1_Start(void);
void Timer1_Stop(void);
void Set_Timer1_CallBack(void (*P)(void));


/******************PWM 0******************/
void PWM0_Init(void);
void PWM0_Generate(uint16 Duty_Cycle);
void PWM0_Start(void);

/******************PWM 1******************/
void PWM1_Init(void);
void PWM1_Generate(uint16 Duty_Cycle);
void PWM1_Start(void);


#endif /* TIMER_H_ */