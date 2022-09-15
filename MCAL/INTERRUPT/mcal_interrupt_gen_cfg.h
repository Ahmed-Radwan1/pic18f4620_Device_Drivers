 /*
 * File:   mcal_interrupt_gen_cfg.h
 * Author: ahmed radwan
 *
 * Created on August 5, 2022, 11:00 PM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

 #define Interrupt_FEATURE_ENABLE 1 
 #define Interrupt_FEATURE_DISABLE 0 
                    /******************************************************************************************************/
                     // enable or disable priority

/*****************/        //   #define Interrupt_priority_Levels_Enable Interrupt_FEATURE_ENABLE                  /**************/

                    /******************************************************************************************************/
 

 #define External_Interrupt_INTx_Feature_Enable       Interrupt_FEATURE_ENABLE 
 #define External_Interrupt_OnChange_Feature_Enable   Interrupt_FEATURE_ENABLE 
 #define ADC_INTERRUPT_FEATURE_ENABLE                 Interrupt_FEATURE_ENABLE
 #define TIMER0_INTERRUPT_FEATURE_ENABLE              Interrupt_FEATURE_ENABLE
 #define TIMER1_INTERRUPT_FEATURE_ENABLE              Interrupt_FEATURE_ENABLE
 #define TIMER2_INTERRUPT_FEATURE_ENABLE              Interrupt_FEATURE_ENABLE
 #define TIMER3_INTERRUPT_FEATURE_ENABLE              Interrupt_FEATURE_ENABLE
 #define CCP1_INTERRUPT_FEATURE_ENABLE                Interrupt_FEATURE_ENABLE
 #define CCP2_INTERRUPT_FEATURE_ENABLE                Interrupt_FEATURE_ENABLE 
 #define EUSART_TX_INTERRUPT_FEATURE_ENABLE           Interrupt_FEATURE_ENABLE 
 #define EUSART_RX_INTERRUPT_FEATURE_ENABLE           Interrupt_FEATURE_ENABLE 
 #define MSSP_I2C_Interrupt_FEATURE_ENABLE            Interrupt_FEATURE_ENABLE
 #define MSSP_I2C_BUS_COL_Interrupt_FEATURE_ENABLE    Interrupt_FEATURE_ENABLE  

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

