/*
 * Timer_Dtypes.h
 *
 * Created: 17/04/2021 09:35:39 PM
 *  Author: Mark Fayez
 */ 

#ifndef TIMER_STRUCTURES_H_
#define TIMER_STRUCTURES_H_

#include "Bit_math.h"
#include "MCU.h"

//*********** Genral Timer SettingS / Options ***********//
typedef enum
{
    TIMER_NORM,
    PWM_PH_CORRECT,
    TIMER_CTC,
    PWM_FAST
} OP_TYPES;

typedef enum
{
    NORMAL,
    CTC_TOGGLE,
    CTC_CLEAR,
    CTC_SET
} CTC_OP;

typedef enum
{
    NO_CLK,
    CLK_NO_PRESC,
    CLK_PRESC_8,
    CLK_PRESC_64,
    CLK_PRESC_256,
    CLK_PRESC_1024,
    EXT_CLK_FALLING_EDGE,
    EXT_CLK_RISSING_EDGE
} CLK_SEL;

//*********** Special for Timer_0 Setting Options ***********//

typedef enum
{
    NORMAL,
    RESERVED,
    CLR_SET,
    SET_CLR
} PWM_MOD;

//*********** Special for Timer_1 Setting Options ***********//
typedef enum
{
    NORM_PWM_PH_CO_TYPE,
    CTC_PWM_FAST_TYPE,
    PWM_PH_CO_MODE,
    CTC_PWM_FAST_MODE
} WAVE_GEN_MAIN_SETS;

typedef enum
{
    NORMAL,
    FAST_8_BIT,
    FAST_9_BIT,
    FAST_10_BIT
} PWM_FAST_TYPES;

typedef enum
{
    NORMAL,
    PWM_PH_CO_8_BIT,
    PWM_PH_CO_9_BIT,
    PWM_PH_CO_10_BIT
} PWM_PH_CO_TYPES;

typedef enum
{
    NORMAL,
    TOGGLE_OC1A_ON_MATCH,
    CLR_ON_MATCH_SET_ON_TOP,
    SET_ON_MATCH_CLR_ON_TOP
} PWM_OP;

typedef enum
{
    TOP_ICR1_UPDATE_ON_BOTTOM,
    TOP_OCR1A_UPDATE_ON_BOTTOM,
    TOP_ICR1_UPDATE_ON_TOP,
    TOP_OCR1A_UPDATE_ON_TOP
} PWM_PH_CO_MODES;

typedef enum
{
    TOP_ICR1,
    TOP_OCR1A
} PWM_FAST_modes;



//*********** Timers Configuration Structures ***********//
typedef struct 
{
    OP_TYPES OperationType;
    CTC_OP OperationMode;

    CLK_SEL CS0;

    uint8   Reg_Size;
    uint32  prescalar;
    uint32  Ticks;
    uint32  Tick_Time;

    uint32  Num_Ovf;
    uint32  Init_Value;

    void (*CallBack_Fun)(void);
} TIMER0_CONF;

typedef struct 
{
    WAVE_GEN_MAIN_SETS  OperationType_WGM1_32;
    CTC_OP  OperationMode_COM1A_10;
    CTC_OP  OperationMode_COM1B_10;

    uint16 CUSTOME_TOP_ICR1;

    CLK_SEL CS1_2_0;

    uint8   Reg_Size;
    uint32  prescalar;
    uint32  Ticks;
    uint32  Tick_Time;

    uint32  Num_Ovf;
    uint32  Init_Value;

    void (*CallBack_Fun)(void);
} TIMER1_CONF;


//*********** PWMs Configuration Structures ***********//
typedef struct 
{
    OP_TYPES OperationType;
    PWM_MOD OperationMode;

    CLK_SEL CS0_2_0;

    uint8   Reg_Size;
    uint32  prescalar;
    uint32  Ticks;
    uint32  Tick_Time;
    uint32  Comp_Value;

    uint32  Num_Ovf;
    uint32  Init_Value;
    
    void (*CallBack_Fun)(void);
} PWM0_CONF;

typedef struct 
{
    WAVE_GEN_MAIN_SETS  OperationType_WGM1_32;
    PWM_FAST_TYPES  Operation_Fast_Type_WGM1_10;
    PWM_FAST_modes  Operation_Fast_Mod_WGM1_10;
    PWM_PH_CO_TYPES Operation_Ph_Co_Type_WGM1_10;
    PWM_PH_CO_MODES Operation_Ph_Co_Mod_WGM1_10;

    PWM_OP OperationMode_COM1A_10;
    PWM_OP OperationMode_COM1B_10;

    uint16 CUSTOME_TOP_ICR1;

    CLK_SEL CS1_2_0;

    uint8   Reg_Size;
    uint32  prescalar;
    uint32  Ticks;
    uint32  Tick_Time;
    uint32  Comp_Value;

    uint32  Num_Ovf;
    uint32  Init_Value;

    void (*CallBack_Fun)(void);
} PWM1_CONF;

#endif /* TIMER_STRUCTURES_H_ */