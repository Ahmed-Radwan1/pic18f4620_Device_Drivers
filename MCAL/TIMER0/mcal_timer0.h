/* 
 * File:   mcal_timer0.h
 * Author: ahmed radwan
 *
 * Created on August 28, 2022, 12:24 AM
 */

#ifndef MCAL_TIMER0_H
#define	MCAL_TIMER0_H


/********************************include section********************************/

#include"../std_libraries.h"
#include"../mcal_std_types.h"
#include"../GPIO/hal_gpio.h"
#include"../INTERRUPT/mcal_internal_interrupt.h"


/********************************macros declarations section********************************/

/********************************macros function declarations section***********************/

#define TIMER0_ENABLE() (T0CONbits.TMR0ON=1)
#define TIMER0_DISABLE() (T0CONbits.TMR0ON=0)

#define TIMER0_8_BIT_REGISTER() (T0CONbits.T08BIT=1)
#define TIMER0_16_BIT_REGISTER() (T0CONbits.T016BIT=0)

#define TIMER0_TIMER_MODE() (T0CONbits.T0CS=0)
#define TIMER0_COUNTER_MODE() (T0CONbits.T0CS=1)

#define TIMER0_COUNTER_FALING_EGE() (T0CONbits.T0SE=1)
#define TIMER0_COUNTER_RISING_EGE() (T0CONbits.T0SE=0)

#define TIMER0_PRESCALER_ENABLE() (T0CONbits.PSA=0)
#define TIMER0_PRESCALER_DISABLE() (T0CONbits.PSA=1)

#define TIMER0_PRESCALER_SET_VALUE(_value) (T0CONbits.T0PS=_value)

/********************************data types  section********************************/



typedef enum{
    TIMER0_PRESCALER_ENABLE=0,
    TIMER0_PRESCALER_DISABLE        
}timer0_prescaler_cfg_t;

typedef enum{
    TIMER0_PRESCALER_DIV_BY_2=0,
    TIMER0_PRESCALER_DIV_BY_4,
    TIMER0_PRESCALER_DIV_BY_8,
    TIMER0_PRESCALER_DIV_BY_16,
    TIMER0_PRESCALER_DIV_BY_32,
    TIMER0_PRESCALER_DIV_BY_64,
    TIMER0_PRESCALER_DIV_BY_128,
    TIMER0_PRESCALER_DIV_BY_256,
}timer0_prescaler_select_t;

typedef enum{
    RISING_EGE=0,
    FALING_EGE
}timer0_counter_cfg_t;

typedef enum{
    COUNTER_MODE=0,
    TIMER_MODE
}timer0_mode_cfg_t;



typedef enum{
    timer0_16_bit_reg=0,
    timer0_8_bit_reg
}timer0_reg_size_t;        
        
typedef struct{
    
    uint16 timer0_preload_value;
    timer0_prescaler_select_t timer0_prescaler_value;

#if TIMER0_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
    void(*Timer0_InterruptHandler)(void);
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
    interrupt_priority_cfg priority;
#endif
#endif
    timer0_prescaler_cfg_t timer0_prescaler_cfg;
    timer0_mode_cfg_t timer0_mode;
    timer0_reg_size_t timer0_register_size;
    timer0_counter_cfg_t timer0_counter_ege; 
}timer0_t;
/*******************************function declarations section*************************************/
Std_returnType Timer0_Init(const timer0_t* _timer0);
Std_returnType Timer0_DeInit(const timer0_t* _timer0);
Std_returnType Timer0_Write_Value(const timer0_t* _timer0,uint16 value);
Std_returnType Timer0_Read_Value(const timer0_t* _timer0,uint16 *value);
#endif	/* MCAL_TIMER0_H */

