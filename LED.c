/*
 * LED.c
 *
 * Created: 19/03/2021 11:59:49 AM
 *  Author: Mark Fayez
 */ 

#include "LED.h"


void LED_Init(uint8 LED)
{
	switch(LED)
	{
		case LED0:
			DIO_SetPinDir(LED0_PORT, LED0_PIN, DIO_PIN_INPUT);
		break;
		
		case LED1:
			DIO_SetPinDir(LED1_PORT, LED1_PIN, DIO_PIN_INPUT);
		break;
		
		case LED2:
			DIO_SetPinDir(LED2_PORT, LED2_PIN, DIO_PIN_INPUT);
		break;
		
		case ALL_LEDS:
			DIO_SetPinDir(LED0_PORT, LED0_PIN, DIO_PIN_INPUT);
			DIO_SetPinDir(LED1_PORT, LED1_PIN, DIO_PIN_INPUT);
			DIO_SetPinDir(LED2_PORT, LED2_PIN, DIO_PIN_INPUT);
		break;
		
		default:
		break;
	}
	
}
void LED_ON(uint8 LED)
{
	switch(LED)
	{
		case LED0:
		DIO_SetPinValue(LED0_PORT, LED0_PIN, DIO_PIN_HIGH);
		break;
		
		case LED1:
		DIO_SetPinValue(LED1_PORT, LED1_PIN, DIO_PIN_HIGH);
		break;
		
		case LED2:
		DIO_SetPinValue(LED2_PORT, LED2_PIN, DIO_PIN_HIGH);
		break;
		
		default:
		break;
	}
}
void LED_OFF(uint8 LED)
{
	switch(LED)
	{
		case LED0:
		DIO_SetPinValue(LED0_PORT, LED0_PIN, DIO_PIN_LOW);
		break;
		
		case LED1:
		DIO_SetPinValue(LED1_PORT, LED1_PIN, DIO_PIN_LOW);
		break;
		
		case LED2:
		DIO_SetPinValue(LED2_PORT, LED2_PIN, DIO_PIN_LOW);
		break;
		
		default:
		break;
	}
}
void LED_Toggle(uint8 LED)
{
	switch(LED)
	{
		case LED0:
		DIO_TogglePin(LED0_PORT, LED0_PIN);
		break;
		
		case LED1:
		DIO_TogglePin(LED1_PORT, LED1_PIN);
		break;
		
		case LED2:
		DIO_TogglePin(LED2_PORT, LED2_PIN);
		break;
		
		default:
		break;
	}
}
