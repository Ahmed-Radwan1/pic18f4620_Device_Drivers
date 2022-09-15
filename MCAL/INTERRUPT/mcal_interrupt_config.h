/* 
 * File:   mcal_interrupt_config.h
 * Author: ahmed radwan
 *
 * Created on August 5, 2022, 8:05 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H
/********************************include section********************************/
#include"../device_config.h"
#include "../mcal_std_types.h"
#include"../std_libraries.h"
#include"mcal_interrupt_gen_cfg.h"
#include "../GPIO/hal_gpio.h"


/********************************macros declarations section********************************/

#define INTERRUPT_ENABLE 1
#define INTERRUPT_DISABLE 0

#define INTERRUPT_OCCUR 1
#define INTERRUPT_NOT_OCCUR 0

#define INTERRUPT_PRORITY_ENABLE 1
#define INTERRUPT_PRORITY_DISABLE 0


/********************************macro function declarations section********************************/

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define Interrupt_poriority_Level_Enable()         (RCONbits.IPEN=1)//Enable priority feature
#define Interrupt_poriority_Level_Disable()        (RCONbits.IPEN=0)//Disable priority feature

#define Interrupt_Global_Iinterrupt_High_Enable()  (INTCONbits.GIEH=1) //Enables all high-priority interrupts
#define Interrupt_Global_Iinterrupt_High_Disable() (INTCONbits.GIEH=0) //Disables all interrupts

#define Interrupt_Global_Iinterrupt_Low_Enable()  (INTCONbits.GIEL=1) //Enables all low-priority peripheral interrupts
#define Interrupt_Global_Iinterrupt_Low_Disable() ( INTCONbits.GIEL=0) //Disables all low-priority peripheral interrupts

#else

#define Interrupt_Global_Iinterrupt_Enable()  (INTCONbits.GIE=1) //Enables Global interrupts
#define Interrupt_Global_Iinterrupt_Disable() (INTCONbits.GIE=0) //Disables Global  interrupts

#define Interrupt_Peripheral_Interrupt_Enable()  ( INTCONbits.PEIE=1)//Enable Peripheral Interrupt 
#define Interrupt_Peripheral_Interrupt_Disable()  ( INTCONbits.PEIE=0)//Disable Peripheral Interrupt 

#endif

/********************************data types  section********************************/
typedef enum{
   INTERRUPT_LOW_priority=0,
   INTERRUPT_HIGH_priority
}interrupt_priority_cfg;




/*******************************function declarations section*************************************/


#endif	/* MCAL_INTERRUPT_CONFIG_H */

