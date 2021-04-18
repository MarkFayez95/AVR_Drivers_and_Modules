/*
 * Timer.c
 *
 * Created: 09/04/2021 1:40:40 PM
 *  Author: Mark Fayez
 */ 


#include "Timer.h"
#include <avr/interrupt.h>

/******************Timer 0******************/
TIMER0_CONF	Timer_0 = { 
OperationType = TIMER_NORM,
OperationMode = NORMAL,

Clk_Source_CS0 = CLK_PRESC_1024,
Reg_Size = REG_SI_8,
prescalar = PRESC_1024,

Ticks = 0,
Tick_Time = 0,
Num_Ovf = 0,
Init_Value = 0,
Comp_Value = 0,

CallBack_Fun = NULL
};

void Timer0_Init(void)
{
	// Set Normal Mode //
	ClearBit(TCCR0,WGM00);
	ClearBit(TCCR0,WGM01);

	// Enable OverFlow interrupts for Timer0 //
	SetBit(TIMSK, TOIE0);
	
	// Enable Global interrupts //
	SetBit(SREG,SREG_I);
}

void Timer0_SetDelay(uint32 Delay_Ms)
{
	Timer_0.Tick_Time = Tick_Time_Calc(Timer_0.prescalar,CLK_FREQ);
	switch (Timer_0.OperationType)
	{
		case TIMER_NORM:
			Max_Ticks(Timer_0.Ticks,Timer_0.Reg_Size);
			uint32 Num_of_Ticks = ((Delay_Ms * 1000) / Timer_0.Tick_Time);
			Timer_0.Num_Ovf = Num_of_Ticks / Timer_0.Ticks;
			Timer_0.Init_Value = Timer_0.Ticks - (Timer_0.Num_Ovf % Timer_0.Ticks );
			TCNT0 = Timer_0.Init_Value;
			
			if(Timer_0.Init_Value != 0)
			{
				Timer_0.Num_Ovf ++;
			}
		break;

		case TIMER_CTC:
			OCR1A = Timer_0.Comp_Value;
			uint32 Num_of_Ticks = ((Delay_Ms * 1000) / Timer_0.Tick_Time);
			Timer_0.Num_Ovf = Num_of_Ticks / Timer_0.Comp_Value;
			Timer_0.Init_Value = Timer_0.Ticks - (Timer_0.Num_Ovf % Timer_0.Comp_Value );
			TCNT0 = Timer_0.Init_Value;
			
			if(Timer_0.Init_Value != 0)
			{
				Timer_0.Num_Ovf ++;
			}
		break;

		default:
		break;
	}
	
}

void Timer0_Start(void)
{
	// Set Clock's source to prescalar 1024 to start timer //
	TCCR0 &= ~CS0_2_0_MASK;
	TCCR0 |= (Timer_0.CS0 << CS00 ) & CS0_2_0_MASK;
}

void Timer0_Stop(void)
{
	// Clear Clock source to stop timer //
	TCCR0 &= ~CS0_2_0_MASK;
}

void Set_Timer0_CallBack(void (*P)(void))
{
	Timer_0.CallBack_Fun = P;
}

ISR(TIMER0_OVF_vect)
{
	static uint32 Count = 0;
	Count++;
	
	if(Count == Timer_0.Num_Ovf)
	{
		Count = 0;
		(*Timer_0.CallBack_Fun)();
		TCNT0 = Timer_0.Init_Value;
	}
}


/******************Timer 1******************/
TIMER1_CONF	Timer_1 ={
	OperationType_WGM1_32 = 0,

    OperationMode_COM1A_10 = 0,
    OperationMode_COM1B_10 = 0,

    CUSTOME_TOP_ICR1 = 0,

    Clk_Source_CS1_2_0 = 0,

    Reg_Size = 0,
    prescalar = 0,
    Ticks = 0,
    Tick_Time = 0
    
    Num_Ovf = 0,
    Init_Value = 0,

    Comp_Value_A = 0,
    Comp_Value_B = 0,

    CallBack_Fun = NULL
};

void Timer1_Init(void)
{
	// Set Timer Normal mode
	ClearBit(TCCR1A,WGM10);
	ClearBit(TCCR1A,WGM11);
	ClearBit(TCCR1B,WGM12);
	ClearBit(TCCR1B,WGM13);
	
	// Enable Global interrupts //
	SetBit(SREG,SREG_I);
	
	// Enable OverFlow interrupts for Timer0 //
	SetBit(TIMSK,TOIE1);
	
}
void Timer1_SetDelay(uint32 Delay_Ms)
{
	uint32 Total_Ticks = ((Delay_Ms * 1000) / TIMER1_TICK_TIME);
	
	Timer1_Num_Ovf = Total_Ticks / TIMER1_TICKS;
	
	Timer1_Init_Value = TIMER1_TICKS - (Total_Ticks % TIMER1_TICKS );
	
	TCNT1_VAL = Timer1_Init_Value;
	
	if(Timer1_Init_Value != 0)
		Timer1_Num_Ovf ++;
}
void Timer1_Start(void)
{
	// Set Clock's source to prescalar 1024 to start timer //
	SetBit(TCCR1B,CS10);
	ClearBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS12);
}
void Timer1_Stop(void)
{
	// Clear Clock source to stop timer //
	ClearBit(TCCR1B,CS10);
	ClearBit(TCCR1B,CS11);
	ClearBit(TCCR1B,CS12);
}
void Set_Timer1_CallBack(void (*P)(void))
{
	Timer1_CallBack_Fun_Ptr = P;
}

/******************PWM 0******************/
PWM0_CONF	PWM_0 ={
	OperationType = 0,
	OperationMode = 0,

	Clk_Source_CS0_2_0 = 0,

	Reg_Size = 0,
	prescalar = 0,
	Ticks = 0,
	Tick_Time = 0,

	Num_Ovf = 0,
	Init_Value = 0,

	Comp_Value = 0,

	CallBack_Fun = NULL
};

void PWM0_Init(void)
{
	// Set OC0 Pin Direction Output //
	SetBit(PWM0_PORT_DIR_REG, PWM0_PORT_DIR_BIT);
	
	// Set PWM Fast //
	SetBit(TCCR0,WGM01);
	SetBit(TCCR0,WGM00);
	
	// Set Non-Inverted Mode //
	SetBit(TCCR0,COM01);
}
void PWM0_Generate(uint16 Duty_Cycle)
{
	OCR0 = ((Duty_Cycle * 256) / 100) - 1;
}
void PWM0_Start(void)
{
	// Set no pre-scalar //
	SetBit(TCCR0,CS00);
	ClearBit(TCCR0,CS01);
	ClearBit(TCCR0,CS02);
}

/******************PWM 1******************/
PWM1_CONF	PWM_1 ={
	OperationType_WGM1_32 = 0,
	Operation_Fast_Type_WGM1_10 = 0,
	Operation_Fast_Mod_WGM1_10 = 0,
	Operation_Ph_Co_Type_WGM1_10 = 0,
	Operation_Ph_Co_Mod_WGM1_10 = 0,

    OperationMode_COM1A_10 = 0,
    OperationMode_COM1B_10 = 0,

    CUSTOME_TOP_ICR1 = 0,

    Clk_Source_CS1_2_0 = 0,

    Reg_Size = 0,
    prescalar = 0,
    Ticks = 0,
    Tick_Time = 0,
    
    Num_Ovf = 0,
    Init_Value = 0,

    Comp_Value_A = 0,
    Comp_Value_B = 0,

    CallBack_Fun = NULL
};

void PWM1_Init(void)
{
	// Set OC1A Pin Direction Output //
	SetBit(DDRD,5);
	
	// Set Timer_1 Mode-14 //
	ClearBit(TCCR1A,WGM10);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1B,WGM13);
	
	// Set Non-Inverted PWM //
	SetBit(TCCR1A,COM1A1);
	ClearBit(TCCR1A,COM1A0);
	
	// Set Value of ICR1 //
	ICR1 = PWM1_TOP_VALUE;
	
}
void PWM1_Generate(uint16 Duty_Cycle)
{
	OCR1A_VAL = ((Duty_Cycle * PWM1_TOP_VALUE)/100) - 1;
}
void PWM1_Start(void)
{
	// Set Pre-scalar 256 //
	SetBit(TCCR1B,CS11);
}