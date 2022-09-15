/* 
 * File:   mcal_timer3.h
 * Author: ahmed radwan
 *
 * Created on August 30, 2022, 12:00 AM
 */

#ifndef MCAL_TIMER3_H
#define	MCAL_TIMER3_H
/********************************include section********************************/

#include"../std_libraries.h"
#include"../mcal_std_types.h"
#include"../GPIO/hal_gpio.h"
#include"../INTERRUPT/mcal_internal_interrupt.h"


/********************************macros declarations section********************************/

/********************************macros function declarations section***********************/
#define TIMER3_ENABLE()                     (T3CONbits.TMR3ON=1)
#define TIMER3_DISABLE()                    (T3CONbits.TMR3ON=0)


#define TIMER3_TIMER_MODE()                 (T3CONbits.TMR3CS=0)
#define TIMER3_COUNTER_MODE()               (T3CONbits.TMR3CS=1)
    
#define TIMER3_SYNC_COUNTER_MODE()          (T3CONbits.T3SYNC=0)
#define TIMER3_ASYNC_COUNTER_MODE()         (T3CONbits.T3SYNC=1)

#define TIMER3_PRESCALER_SET_VALUE(_value)  (T3CONbits.T3CKPS=_value)

#define TIMER3_RW_REG_8BIT_MODE_set()       (T3CONbits.RD16=0)
#define TIMER3_RW_REG_16BIT_MODE_set()      (T3CONbits.RD16=1)
/********************************data types  section********************************/

typedef enum{
    TIMER3_COUNTER_MODE_CFG=0,
    TIMER3_TIMER_MODE_CFG
}timer3_mode_cfg_t;

typedef enum{
    TIMER3_SYNC_COUNTER_MODE_CFG=0,
    TIMER3_ASYNC_COUNTER_MODE_CFG
}timer3_sync_cfg_t;

typedef enum{
    TIMER3_PRESCALER_DIV_BY_1=0,
    TIMER3_PRESCALER_DIV_BY_2,
    TIMER3_PRESCALER_DIV_BY_4,
    TIMER3_PRESCALER_DIV_BY_8,
}timer3_prescaler_select_t;

typedef enum{
    TIMER3_RW_REG_8BIT_MODE=0,
    TIMER3_RW_REG_16BIT_MODE
}timer3_Read_Write_Mode_select_t;

typedef struct{
    uint16 timer3_preload_value;
#if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
    void(*Timer3_InterruptHandler)(void);
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
    interrupt_priority_cfg priority;
#endif
#endif
    timer3_prescaler_select_t timer3_prescaler_value;
    timer3_mode_cfg_t timer3_mode;
    timer3_sync_cfg_t counter_mode;
    timer3_Read_Write_Mode_select_t timer3_register_mode;
    
}timer3_t;
/*******************************function declarations section*************************************/
Std_returnType Timer3_Init(const timer3_t* _timer3);
Std_returnType Timer3_DeInit(const timer3_t* _timer3);
Std_returnType Timer3_Write_Value(const timer3_t* _timer3,uint16 value);
Std_returnType Timer3_Read_Value(const timer3_t* _timer3,uint16 *value);
#endif	/* MCAL_TIMER3_H */

