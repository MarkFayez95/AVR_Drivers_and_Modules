/*
 * ADC.h
 *
 * Created: 03/04/2021 12:46:19 PM
 *  Author: Mark Fayez
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "MCU.h"
#include "Bit_math.h"

#include "ADC_CFG.h"

#define F_CPU 16000000UL
#include <util/delay.h>

#define ADC_VREF_AREF_Vreff_OFF		0x00
#define ADC_VREF_AVCC				0x01
#define ADC_VREF_Internal_2_56		0x03

#define ADC_VOLTAGE_REF_ADMUX_REFS_MASK	0xC0

#define ADC_LEFT_ADJUST		0
#define ADC_RIGHT_ADJUST	1

#define ADC_ADJUST_ADMUX_ADLAR_MASK		0x10

#define ADC_CHANNEL_0		0
#define ADC_CHANNEL_1		1
#define ADC_CHANNEL_2		2
#define ADC_CHANNEL_3		3
#define ADC_CHANNEL_4		4
#define ADC_CHANNEL_5		5
#define ADC_CHANNEL_6		6
#define ADC_CHANNEL_7		7

#define ADC_CHANNEL_ADMUX_MUX_MASK	0x0F

#define ADC_FREE_RUN_TRIGGER				0x00
#define ADC_ANALOG_COMP_TRIGGER				0x01
#define ADC_EXT_INT_TRIGGER					0x02
#define ADC_TIM_COUNT_0_COMP_TRIGGER		0x03
#define ADC_TIM_COUNT_0_OVF_TRIGGER			0x04
#define ADC_TIM_COUNT_COMP_MATCH_B_TRIGGER	0x05
#define ADC_TIM_COUNT_1_OVF_TRIGGER			0x06
#define ADC_TIM_COUNT_CAP_EVENT_TRIGGER		0x07

#define ADC_TRIGGER_SFIOR_ADTS_MASK	0xE0

#define ADC_PRESC_1			0x00
#define ADC_PRESC_2			0x01
#define ADC_PRESC_4			0x02
#define ADC_PRESC_8			0x03
#define ADC_PRESC_16		0x04
#define ADC_PRESC_32		0x05
#define ADC_PRESC_64		0x06
#define ADC_PRESC_128		0x07

#define ADC_PRESCALAR_ADCSRA_ADPS_MASK	0x07

#define ADC_INTERRUPT_DISABLE	0
#define ADC_INTERRUPT_ENABLE	1

#define ADC_AUTO_DISABLE	0
#define ADC_AUTO_ENABLE		1


void ADC_Init(void);

void ADC_Read(uint16* value);
void ADC_INT_Read(uint16* value);

#endif /* ADC_H_ */