/*
 * DIO.h
 *
 * Created: 08/05/2021 2:06:02 AM
 *  Author: Mark Fayez
 */ 

#ifndef MOTORS_H_
#define MOTORS_H_

#include "Timer.h"
#include "DIO.h"


#define DISABLE 0
#define ENABLE  1

#define MOTOR_A_SEL ENABLE
#define MOTOR_B_SEL ENABLE

#define SERVO_MOTOR_SEL ENABLE


#if ((MOTOR_A_SEL == ENABLE) || (MOTOR_B_SEL == ENABLE))
    typedef enum{
        NO_CURRENT_OUTPUT,
        MOTOR_DIR_CLK_WISE,
        MOTOR_DIR_ANTI_CLK_WISE,
        MOTOR_STOP
    }DCMotor_Dir;
    
    void DCMotor_Init(void);

    #define H_BRIDGE_DIR_DIO_PORT       DIO_PORTC
    #define H_BRIDGE_DIR_PINS_PORT      PORT_C

    #if (MOTOR_A_SEL == ENABLE)
        #define H_BRIDGE_DIR_PIN_1          PIN3
        #define H_BRIDGE_DIR_PIN_2          PIN4
        #define H_BRIDGE_DIR_MOTOR_A_MASK   0b00011000

        void DCMotor_A_SetDir(DCMotor_Dir dir);
        void DCMotor_A_Start(void);
        void DCMotor_A_Stop(void);
    #endif

    #if (MOTOR_B_SEL == ENABLE)
        #define H_BRIDGE_DIR_PIN_3          PIN5
        #define H_BRIDGE_DIR_PIN_4          PIN6
        #define H_BRIDGE_DIR_MOTOR_B_MASK   0b00000110

        void DCMotor_B_SetDir(DCMotor_Dir dir);
        void DCMotor_B_Start(void);
        void DCMotor_B_Stop(void);
    #endif

    #if ((MOTOR_A_SEL == ENABLE) && (MOTOR_B_SEL == ENABLE))
        void DCMotors_SetSpeed(uint8 Speed_A, uint8 Speed_B);
    #elif (MOTOR_A_SEL == ENABLE)
        void DCMotor_A_SetSpeed(uint8 Speed_A);
    #elif (MOTOR_B_SEL == ENABLE)
        void DCMotor_B_SetSpeed(uint8 Speed_B);
    #endif
#endif

#if SERVO_MOTOR_SEL == ENABLE
    #define SERVO_DIR_DIO_PORT  DIO_PORTD
    #define SERVO_PIN           PIN7

    #define SERVO_OP_FREQ           50
    #define SERVO_ANGLE_OFFSET      90
    #define SERVO_SLOPE             (float64)(0.0277777777777778)
    #define SERVO_MIN_DUTY_CYCLE    5

    #define SERVO_SIGNAL_PERIODIC_TIME  (uint32)((float64)1000/(2*SERVO_OP_FREQ))

    void Servo_Motor_Init(void);
    void Servo_Motor_Move(sint8 Degrees);
#endif

#endif