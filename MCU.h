/*
 * MCU.h
 *
 * Created: 18/03/2021 10:05:01 PM
 *  Author: Mark Fayez
 */ 


#ifndef MCU_H_
#define MCU_H_

#include "STD_DTypes.h"

#define PINA (*(volatile uint8*)0x39)
#define DDRA (*(volatile uint8*)0x3A)
#define PORTA (*(volatile uint8*)0x3B)

#define PINB (*(volatile uint8*)0x36)
#define DDRB (*(volatile uint8*)0x37)
#define PORTB (*(volatile uint8*)0x38)

#define PINC (*(volatile uint8*)0x33)
#define DDRC (*(volatile uint8*)0x34)
#define PORTC (*(volatile uint8*)0x35)

#define PIND (*(volatile uint8*)0x30)
#define DDRD (*(volatile uint8*)0x31)
#define PORTD (*(volatile uint8*)0x32)

/*************************************** Special FunctionIO Register **********************************/
#define SFIOR	(*(volatile uint8*) 0x50)
#define PSR10			0
#define PSR2			1
#define PUD				2
#define ACME			3
#define SFIOR_Res_Bit	4
#define ADTS			5

/*********************************** Interrupts Registers ********************************/

#define SREG	(*(volatile uint8*)0x5F)
#define SREG_I	7

#define GICR	(*(volatile uint8*)0x5B)
#define GIFR	(*(volatile uint8*)0x5A)
#define MCUCR	(*(volatile uint8*)0x55)
#define MCUCSR	(*(volatile uint8*)0x54)

/*************************************** ADC Registers **********************************/

#define ADMUX	(*(volatile uint8*)0x27)
#define ADLAR	5
#define REFS0	6

#define ADCSRA	(*(volatile uint8*)0x26)
#define ADIE	3
#define ADIF	4
#define ADATE	5
#define ADSC	6
#define ADEN	7

#define ADCH	(*(volatile uint8*)0x25)
#define ADCL	(*(volatile uint8*)0x24)
#define ADC_VAL	(*(volatile uint16*)0x24)

#endif /* MCU_H_ */