/*
 * EXT_INT.h
 *
 * Created: 02/04/2021 1:46:49 PM
 *  Author: Mark Fayez
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_CFG.h"
#include "STD_DTypes.h"
#include "Bit_math.h"
#include "MCU.h"

#define GLOBAL_INTERRUPT_ENABLE		0
#define GLOBAL_INTERRUPT_DISABLE	1

#define TRIGGER_RISSING				0x03
#define TRIGGER_FALLING				0x02
#define TRIGGER_LOW_LEVEL			0x00
#define TRIGGER_ANY_LOGICAL_CHANGE	0x01

void SET_GlobalInterrupt(void);

void ExternalINT0_Init(void);

/***********Assignment*********/

void ExternalINT1_Init(void);
void ExternalINT2_Init(void);


/****Another possible implementation****
#define INT_0	0
#define INT_1	1
#define INT_2	2

void ExternalINT_Init(uint8 EXT_INT_ID);
***********************/

/*******************************/

#endif /* EXT_INT_H_ */