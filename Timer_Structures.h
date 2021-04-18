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
    TIMER_NORM,
    PWM_PH_CORRECT,
    TIMER_CTC,
    PWM_FAST
} OP_TYPES;

typedef enum
{
    NORMAL,         // COM0_10 Mode selection
    RESERVED,       // COM0_10 Mode selection
    CLR_SET,        // COM0_10 Mode selection
    SET_CLR         // COM0_10 Mode selection
} PWM_MOD;

//*********** Special for Timer_1 Setting Options ***********//
typedef enum
{
    NORM_PWM_PH_CO_TYPE,    // WGM1_32 Modes 0-3
    CTC_PWM_FAST_TYPE,      // WGM1_32 Modes 4-7
    PWM_PH_CO_MODE,         // WGM1_32 Modes 8-11
    CTC_PWM_FAST_MODE       // WGM1_32 Modes 12-15
} WAVE_GEN_MAIN_SETS;

typedef enum
{
    //NORMAL,           // WGM1_10 Mode 0
    PWM_PH_CO_8_BIT=1,  // WGM1_10 Mode 1
    PWM_PH_CO_9_BIT,    // WGM1_10 Mode 2
    PWM_PH_CO_10_BIT    // WGM1_10 Mode 3
} PWM_PH_CO_TYPES;

typedef enum
{
    CTC_TOP_OCR1A,    // WGM1_10 Mode 4
    FAST_8_BIT,       // WGM1_10 Mode 5
    FAST_9_BIT,         // WGM1_10 Mode 6
    FAST_10_BIT         // WGM1_10 Mode 7
} PWM_FAST_TYPES;


typedef enum
{
    TOP_ICR1_UPDATE_ON_BOTTOM,      // WGM1_10 Mode 8
    TOP_OCR1A_UPDATE_ON_BOTTOM,     // WGM1_10 Mode 9
    TOP_ICR1_UPDATE_ON_TOP,         // WGM1_10 Mode 10
    TOP_OCR1A_UPDATE_ON_TOP         // WGM1_10 Mode 11
} PWM_PH_CO_MODES;

typedef enum
{
    CTC_TOP_ICR1,   // WGM1_10 Mode 12
    //RESERVED,       // WGM1_10 Mode 13
    TOP_ICR1=2,       // WGM1_10 Mode 14
    TOP_OCR1A         // WGM1_10 Mode 15
} PWM_FAST_modes;

typedef enum
{
    //NORMAL,
    TOGGLE_OC1A_ON_MATCH=1,     // COM1A/COM1B_10 Mode selection
    CLR_ON_MATCH_SET_ON_TOP,    // COM1A/COM1B_10 Mode selection
    SET_ON_MATCH_CLR_ON_TOP     // COM1A/COM1B_10 Mode selection
} PWM_OP;

//*********** Timers Configuration Structures ***********//
typedef struct 
{
    OP_TYPES OperationType;
    CTC_OP OperationMode;

    CLK_SEL Clk_Source_CS0;

    uint8   Reg_Size;
    uint16  prescalar;
    uint32  Ticks;
    float64  Tick_Time;
    

    uint32  Num_Ovf;
    uint8  Init_Value;

    uint8  Comp_Value;

    void (*CallBack_Fun)(void);
} TIMER0_CONF;

typedef struct 
{
    WAVE_GEN_MAIN_SETS  OperationType_WGM1_32;
    
    CTC_OP  OperationMode_COM1A_10;
    CTC_OP  OperationMode_COM1B_10;

    uint16 CUSTOME_TOP_ICR1;

    CLK_SEL Clk_Source_CS1_2_0;

    uint8   Reg_Size;
    uint16  prescalar;
    uint32  Ticks;
    float64  Tick_Time;
    
    uint32  Num_Ovf;
    uint16  Init_Value;

    uint16  Comp_Value_A;
    uint16  Comp_Value_B;

    void (*CallBack_Fun)(void);
} TIMER1_CONF;


//*********** PWMs Configuration Structures ***********//
typedef struct 
{
    OP_TYPES OperationType;
    PWM_MOD OperationMode;

    CLK_SEL Clk_Source_CS0_2_0;

    uint8   Reg_Size;
    uint16  prescalar;
    uint32  Ticks;
    float64  Tick_Time;
    

    uint32  Num_Ovf;
    uint8  Init_Value;

    uint8  Comp_Value;
    
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

    CLK_SEL Clk_Source_CS1_2_0;

    uint8   Reg_Size;
    uint16  prescalar;
    uint32  Ticks;
    float64  Tick_Time;
    
    uint32  Num_Ovf;
    uint16  Init_Value;

    uint16  Comp_Value_A;
    uint16  Comp_Value_B;

    void (*CallBack_Fun)(void);
} PWM1_CONF;

#endif /* TIMER_STRUCTURES_H_ */