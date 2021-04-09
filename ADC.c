/*
 * ADC.c
 *
 * Created: 03/04/2021 12:46:31 PM
 *  Author: Mark Fayez
 */ 

#include "ADC.h"

void ADC_Init(void)
{
	// Set the ADC's Voltage reference source
	/*
	#if ADC_VOLTAGE_REFERENCE == ADC_VREF_AVCC
	SetBit(ADMUX,6);
	ClearBit(ADMUX,7);
	#endif
	*/
	ADMUX &= ~ADC_VOLTAGE_REF_ADMUX_REFS_MASK; // clear the Voltage reference selection bits before setting the required bits
	ADMUX |= ((ADC_VOLTAGE_REFERENCE << REFS0) & ADC_VOLTAGE_REF_ADMUX_REFS_MASK);
		
	// Set ADC's adjust right or left for saving the 10 bits of the readings
	/*#if ADC_ADJUST == ADC_RIGHT_ADJUST
	ClearBit(ADMUX,5);
	#endif
	*/
	ADMUX &= ~ADC_ADJUST_ADMUX_ADLAR_MASK; // clear the Adjust selection bits before setting the required bits
	ADMUX |= ((ADC_ADJUST << ADLAR) & ADC_ADJUST_ADMUX_ADLAR_MASK );
		
	// Set the ADC channel that shall run
	/*
	#if ADC_CHANNEL == ADC_CHANNEL_1
	SetBit(ADMUX,0);
	#endif
	*/
	ADMUX &= ~ADC_CHANNEL_ADMUX_MUX_MASK;
	ADMUX |= (ADC_CHANNEL & ADC_CHANNEL_ADMUX_MUX_MASK);
		
	// Set ADC Prescalar value
	/*
	#if ADC_PRESCALAR == ADC_PRESC_128
	SetBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	#endif 
	*/
	ADCSRA &= ~ADC_PRESCALAR_ADCSRA_ADPS_MASK; // clear the prescalar selection bits before setting the required bits
	ADCSRA |= (ADC_PRESCALAR & ADC_PRESCALAR_ADCSRA_ADPS_MASK); 
	
	// Set ADC Conversion Start trigger signal source
	/*
	#if ADC_CONVERSION_TRIGGER == ADC_AUTO_TRIGGER
		SetBit(ADCSRA,ADATE);
	#endif
	*/
	#if	ADC_CONV_TRIGGER_TYPE == ADC_AUTO_ENABLE
		SFIOR &= ~ADC_TRIGGER_SFIOR_ADTS_MASK; // clear the trigger selection bits before setting the required bits
		SFIOR |= ((ADC_CONVERSION_TRIGGER << ADTS) & ADC_TRIGGER_SFIOR_ADTS_MASK);
		SetBit(ADCSRA,ADATE); // enable automatic conversion start
	#endif
	
	// Set ADC Interrupt generate settings
	#if ADC_INTERRUPT_STATUS == ADC_INTERRUPT_DISABLE
		ClearBit(ADCSRA,ADIE); // disable ADC interrupts ADIE Bit in ADCSRA Register
	#elif ADC_INTERRUPT_STATUS == ADC_INTERRUPT_ENABLE
		// Enable Global Interrupts
		SetBit(SREG,SREG_I);
		// Enable ACD Interrupt
		SetBit(ADCSRA,ADIE);
	#endif
	
	/*** Enable ADC ***/
	SetBit(ADCSRA,ADEN);
	
	_delay_ms(10);
	
	#if (ADC_INTERRUPT_STATUS == ADC_INTERRUPT_ENABLE) && (ADC_CONVERSION_TRIGGER == ADC_FREE_RUN_TRIGGER)
		SetBit(ADCSRA,ADSC); // start conversion //
	#endif
}
void ADC_Read(uint16* value)
{
		SetBit(ADCSRA,ADSC); // start conversion //
		
		while (GetBit(ADCSRA,ADIF) == 0); // wait till end of conversion //
		
		#if ADC_ADJUST == ADC_RIGHT_ADJUST
			*value = ADC_VAL;
		#elif ADC_ADJUST == ADC_LEFT_ADJUST
			*value = ADC_VAL >> 6;
		#endif
}


void ADC_INT_Read(uint16* value)
{
	// read current converted value
	#if ADC_ADJUST == ADC_RIGHT_ADJUST
		*value = ADC_VAL;
	#elif ADC_ADJUST == ADC_LEFT_ADJUST
		*value = ADC_VAL >> 6;
	#endif
}
