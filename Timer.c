/*
 * Timer.c
 *
 * Created: 09/04/2021 1:40:40 PM
 *  Author: Mark Fayez
 */ 


#include "Timer.h"
#include <avr/interrupt.h>

uint32 Num_Ovf = 0;
uint32 Init_Value = 0;

void (*Ptr)(void);

void Timer0_Init(void)
{
	// Set Normal Mode //
	ClearBit(TCCR0,WGM00);
	ClearBit(TCCR0,WGM01);
	
	// Enable Global interrupts //
	SetBit(SREG,SREG_I);
	
	// Enable OverFlow interrupts for Timer0 //
	SetBit(TIMSK, TOIE0);
}

void Timer0_SetDelay(uint32 Delay_Ms)
{
	uint32 Total_Ticks = ((Delay_Ms * 1000) / TIMER0_TICK_TIME);
	
	Num_Ovf = Total_Ticks / TIMER0_TICKS;
	
	Init_Value = TIMER0_TICKS - (Total_Ticks % TIMER0_TICKS );
	
	TCNT0 = Init_Value;
	
	if(Init_Value != 0)
		Num_Ovf ++;
	
}

void Timer0_Start(void)
{
	// Set Clock's source to prescalar 1024 to start timer //
	SetBit(TCCR0,CS00);
	ClearBit(TCCR0,CS01);
	SetBit(TCCR0,CS02);
}

void Timer0_Stop(void)
{
	// Clear Clock source to stop timer //
	ClearBit(TCCR0,CS00);
	ClearBit(TCCR0,CS01);
	ClearBit(TCCR0,CS02);
}

void Set_Timer0_CallBack(void (*P)(void))
{
	Ptr = P;
}

ISR(TIMER0_OVF_vect)
{
	static uint32 Count = 0;
	Count++;
	
	if(Count == Num_Ovf)
	{
		Count = 0;
		(*Ptr)();
		TCNT0 = Init_Value;
	}
}