/* 
 * File:   mcal_ccp1.h
 * Author: ahmed radwan
 *
 * Created on September 1, 2022, 4:48 AM
 */

#ifndef MCAL_CCP1_H
#define	MCAL_CCP1_H

/********************************include section********************************/

#include"../std_libraries.h"
#include"../mcal_std_types.h"
#include"../GPIO/hal_gpio.h"
#include"../INTERRUPT/mcal_internal_interrupt.h"
#include"mcal_ccp1_cfg.h"
#include "../TIMER1/mcal_timer1.h"
#include "../TIMER2/mcal_timer2.h"
#include "../TIMER3/mcal_timer3.h"


/********************************macros declarations section********************************/

/* CCP1 Module Mode Select  */
#define CCP1_MODULE_DISABLE                 ((uint8)0x00)
#define CCP1_CAPTURE_MODE_1_FALLING_EDGE    ((uint8)0x04)
#define CCP1_CAPTURE_MODE_1_RISING_EDGE     ((uint8)0x05)
#define CCP1_CAPTURE_MODE_4_RISING_EDGE     ((uint8)0x06)
#define CCP1_CAPTURE_MODE_16_RISING_EDGE    ((uint8)0x07)
#define CCP1_COMPARE_MODE_SET_PIN_LOW       ((uint8)0x08)
#define CCP1_COMPARE_MODE_SET_PIN_HIGH      ((uint8)0x09)
#define CCP1_COMPARE_MODE_TOGGLE_ON_MATCH   ((uint8)0x02)
#define CCP1_COMPARE_MODE_GEN_SW_INTERRUPT  ((uint8)0x0A)
#define CCP1_COMPARE_MODE_GEN_EVENT         ((uint8)0x0B)
#define CCP1_PWM_MODE                       ((uint8)0x0C)

/* CCP1 Capture Mode State  */
#define CCP1_CAPTURE_NOT_READY              0X00
#define CCP1_CAPTURE_READY                  0X01


/* CCP1 Compare Mode State  */
#define CCP1_COMPARE_NOT_READY              0X00
#define CCP1_COMPARE_READY                  0X01


/********************************macros function declarations section***********************/
/* Set the CCP1 Mode Variant */
#define CCP1_SET_MODE(_CONFIG)  (CCP1CONbits.CCP1M = _CONFIG)



/********************************data types  section********************************/

typedef enum{
    CCP1_CAPTURE_MODE_SELECTED = 0, /* Select CCP1 Capture Mode */
    CCP1_COMPARE_MODE_SELECTED,     /* Select CCP1 Compare Mode */
    CCP1_PWM_MODE_SELECTED          /* Select CCP1 PWM Mode */
}ccp1_mode_t;


/*
  @Summary      Defines the values to convert from 16bit to two 8 bit and vice versa
  @Description  Used to get two 8 bit values from 16bit also two 8 bit value are combine to get 16bit.
*/
typedef union{
    struct{
        uint8 ccpr_low;  /* CCPR1 low register */
        uint8 ccpr_high; /* CCPR1 high register */
    };
    struct{
        uint16 ccpr_16Bit; /* Read CCPR1 as a 16 Bit value */
    };
}CCP1_REG_T;
typedef enum{
    CCP1_CCP2_TIMER3=0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1       
}ccp1_capture_compare_timer_cfg;

typedef struct{
    ccp1_mode_t ccp1_mode;
    uint8 ccp1_mode_variant;
    pin_config_t ccp1_pin;
#if CCP1_INTERRUPT_FEATURE_ENABLE==Interrupt_FEATURE_ENABLE
    void (* CCP1_InterruptHandler)(void);   /* Call back used for all CCP1 Modes */
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE    
    interrupt_priority_cfg CCP1_priority;   /* Configure the CCP1 mode interrupt */
#endif
#endif
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_CAPTURE_MODE_SELECTED)
    ccp1_capture_timer_cfg ccp_capture_timer;
#endif


#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_PWM_MODE_SELECTED)
     uint32 PWM1_frequancy;   /* Configure the CCP1 frequency */
     timer2_t ccp_timer2;// Configure timer2
#else
     ccp1_capture_compare_timer_cfg ccp_capture_compare_timer;
#endif          


}ccp1_t;
/*******************************function declarations section*************************************/
Std_returnType CCP1_Init(const ccp1_t *_ccp_obj);
Std_returnType CCP1_DeInit(const ccp1_t *_ccp_obj);

#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_CAPTURE_MODE_SELECTED)
Std_returnType CCP1_IsCapturedDataReady(uint8 *_capture_status);
Std_returnType CCP1_Capture_Mode_Read_Value(uint16 *capture_value);
#endif
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_COMPARE_MODE_SELECTED)
Std_returnType CCP1_IsCompareComplete(uint8 *_compare_status);
Std_returnType CCP1_Compare_Mode_Set_Value(uint16 compare_value);
#endif
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_PWM_MODE_SELECTED)
Std_returnType CCP1_PWM_Set_Duty(const uint8 _duty);
Std_returnType CCP1_PWM_Start();
Std_returnType CCP1_PWM_Stop();  
#endif
#endif	/* MCAL_CCP1_H */

