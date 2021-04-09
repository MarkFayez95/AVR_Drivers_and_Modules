/*
 * EXT_INT.c
 *
 * Created: 02/04/2021 1:46:33 PM
 *  Author: Mark Fayez
 */ 

#include "EXT_INT.h"


void SET_GlobalInterrupt(void)
{
	#if GLOBAL_INTERRUPT == GLOBAL_INTERRUPT_ENABLE
	
	SetBit(SREG,7);
	
	#elif GLOBAL_INTERRUPT == GLOBAL_INTERRUPT_DISABLE
	
	ClearBit(SREG,7);
	
	#endif
}

void ExternalINT0_Init(void)
{
	// Enable Global Interrupt //
	SET_GlobalInterrupt();
	
	// Enable External INT0 //
	SetBit(GICR,6); 
	
	// Select External INT0 Trigger //
	#if EXTERNAL_INT0_TRIGGER == TRIGGER_RISSING
		MCUCR |= TRIGGER_RISSING;
	#elif EXTERNAL_INT0_TRIGGER == TRIGGER_FALLING
		MCUCR |= TRIGGER_FALLING;
	#elif EXTERNAL_INT0_TRIGGER == TRIGGER_LOW_LEVEL
		MCUCR |= TRIGGER_LOW_LEVEL;
	#elif EXTERNAL_INT0_TRIGGER == TRIGGER_ANY_LOGICAL_CHANGE
		MCUCR |= TRIGGER_ANY_LOGICAL_CHANGE;
	#endif
	
}

/**************** Assignment *******************/

void ExternalINT1_Init(void)
{
	// Enable Global Interrupt //
	SET_GlobalInterrupt();
	
	// Enable External INT1 //
	SetBit(GICR,7);
	
	// Select External INT1 Trigger //
	#if EXTERNAL_INT1_TRIGGER == TRIGGER_RISSING
	MCUCR |= TRIGGER_RISSING << 2;
	#elif EXTERNAL_INT1_TRIGGER == TRIGGER_FALLING
	MCUCR |= TRIGGER_FALLING << 2;
	#elif EXTERNAL_INT1_TRIGGER == TRIGGER_LOW_LEVEL
	MCUCR |= TRIGGER_LOW_LEVEL << 2;
	#elif EXTERNAL_INT1_TRIGGER == TRIGGER_ANY_LOGICAL_CHANGE
	MCUCR |= TRIGGER_ANY_LOGICAL_CHANGE << 2;
	#endif
}
void ExternalINT2_Init(void)
{
	// Enable Global Interrupt //
	SET_GlobalInterrupt();
	
	// Disable External INT2 //
	ClearBit(GICR,5);
		
	// Select External INT2 Trigger //
	#if EXTERNAL_INT2_TRIGGER == TRIGGER_RISSING
	SetBit(MCUCSR,6);
	#elif EXTERNAL_INT2_TRIGGER == TRIGGER_FALLING
	ClearBit(MCUCSR,6);
	#endif
	
	// Enable External INT2 //
	SetBit(GICR,5);
}

/********Another possible implementation*******
void ExternalINT_Init(uint8 EXT_INT_ID)
{
	if(EXT_INT_ID == INT_0)
	{
		// Enable Global Interrupt //
		SET_GlobalInterrupt();
		
		// Enable External INT0 //
		SetBit(GICR,6);
		
		// Select External INT0 Trigger //
		#if EXTERNAL_INT0_TRIGGER == TRIGGER_RISSING
		MCUCR |= TRIGGER_RISSING;
		#elif EXTERNAL_INT0_TRIGGER == TRIGGER_FALLING
		MCUCR |= TRIGGER_FALLING;
		#elif EXTERNAL_INT0_TRIGGER == TRIGGER_LOW_LEVEL
		MCUCR |= TRIGGER_LOW_LEVEL;
		#elif EXTERNAL_INT0_TRIGGER == TRIGGER_ANY_LOGICAL_CHANGE
		MCUCR |= TRIGGER_ANY_LOGICAL_CHANGE;
		#endif
	}
	else if(EXT_INT_ID == INT_1)
	{
		// Enable Global Interrupt //
		SET_GlobalInterrupt();
		
		// Enable External INT1 //
		SetBit(GICR,7);
		
		// Select External INT1 Trigger //
		#if EXTERNAL_INT1_TRIGGER == TRIGGER_RISSING
		MCUCR |= TRIGGER_RISSING << 2;
		#elif EXTERNAL_INT1_TRIGGER == TRIGGER_FALLING
		MCUCR |= TRIGGER_FALLING << 2;
		#elif EXTERNAL_INT1_TRIGGER == TRIGGER_LOW_LEVEL
		MCUCR |= TRIGGER_LOW_LEVEL << 2;
		#elif EXTERNAL_INT1_TRIGGER == TRIGGER_ANY_LOGICAL_CHANGE
		MCUCR |= TRIGGER_ANY_LOGICAL_CHANGE << 2;
		#endif
	}
	else if(EXT_INT_ID == INT_2)
	{
		// Enable Global Interrupt //
		SET_GlobalInterrupt();
		
		// Disable External INT2 //
		ClearBit(GICR,5);
		
		// Select External INT2 Trigger //
		#if EXTERNAL_INT2_TRIGGER == TRIGGER_RISSING
		SetBit(MCUCSR,6);
		#elif EXTERNAL_INT2_TRIGGER == TRIGGER_FALLING
		ClearBit(MCUCSR,6);
		#endif
		
		// Enable External INT2 //
		SetBit(GICR,5);
	}
}
***********************/

/*******************************************/