/* 
 * File:   mcal_timer2.h
 * Author: ahmed radwan
 *
 * Created on August 29, 2022, 11:54 PM
 */

#ifndef MCAL_TIMER2_H
#define	MCAL_TIMER2_H
/********************************include section********************************/

#include"../std_libraries.h"
#include"../mcal_std_types.h"
#include"../GPIO/hal_gpio.h"
#include"../INTERRUPT/mcal_internal_interrupt.h"


/********************************macros declarations section********************************/

/********************************macros function declarations section***********************/

#define TIMER2_ENABLE()                     (T2CONbits.TMR2ON=1)
#define TIMER2_DISABLE()                    (T2CONbits.TMR2ON=0)

  
#define TIMER2_PRESCALER_SET_VALUE(_value)   (T2CONbits.T2CKPS=_value)
#define TIMER2_POSTSCALER_SET_VALUE(_value)  (T2CONbits.TOUTPS=_value)



/********************************data types  section********************************/

typedef enum{
    TIMER2_PRESCALER_DIV_BY_1=0,
    TIMER2_PRESCALER_DIV_BY_4,
    TIMER2_PRESCALER_DIV_BY_16
}timer2_prescaler_select_t;

typedef enum{
    TIMER2_postscaler_DIV_BY_1=0,
    TIMER2_postscaler_DIV_BY_2,
    TIMER2_postscaler_DIV_BY_3,
    TIMER2_postscaler_DIV_BY_4,
    TIMER2_postscaler_DIV_BY_5,
    TIMER2_postscaler_DIV_BY_6,
    TIMER2_postscaler_DIV_BY_7, 
    TIMER2_postscaler_DIV_BY_8,
    TIMER2_postscaler_DIV_BY_9,
    TIMER2_postscaler_DIV_BY_10,
    TIMER2_postscaler_DIV_BY_11,
    TIMER2_postscaler_DIV_BY_12,
    TIMER2_postscaler_DIV_BY_13, 
    TIMER2_postscaler_DIV_BY_14,
    TIMER2_postscaler_DIV_BY_15,
    TIMER2_postscaler_DIV_BY_16
}timer2_postscaler_select_t;
        
typedef struct{
    uint8 timer2_preload_value;
    #if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
    void(*Timer2_InterruptHandler)(void);
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
    interrupt_priority_cfg priority;
#endif
#endif
    timer2_prescaler_select_t   timer2_prescaler_value;
    timer2_postscaler_select_t  timer2_postscaler_value;
}timer2_t;
/*******************************function declarations section*************************************/
Std_returnType Timer2_Init(const timer2_t* _timer2);
Std_returnType Timer2_DeInit(const timer2_t* _timer2);
Std_returnType Timer2_Write_Value(const timer2_t* _timer2,uint8 value);
Std_returnType Timer2_Read_Value(const timer2_t* _timer2,uint8 *value);

#endif	/* MCAL_TIMER2_H */

