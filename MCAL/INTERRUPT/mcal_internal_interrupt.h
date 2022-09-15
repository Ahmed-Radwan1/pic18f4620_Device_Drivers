/* 
 * File:   mcal_internal_interrupt.h
 * Author: ahmed radwan
 *
 * Created on August 5, 2022, 8:09 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H


/********************************include section********************************/

#include"mcal_interrupt_config.h"

/********************************macros declarations section********************************/
 #if ADC_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define ADC_Interrupt_Disable() (PIE1bits.ADIE=0)// disable the iterrupt  for the ADC
#define ADC_Interrupt_Enable()  (PIE1bits.ADIE=1)// set the iterrupt enable for the ADC

#define ADC_Interrupt_Flag_clear() (PIR1bits.ADIF=0)// clear the iterrupt flag for the ADC

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define ADC_Interrupt_High_priority_set() (IPR1bits.ADIP=1)//set the interrupt for the ADC to be high priority
#define ADC_Interrupt_Low_priority_set()  (IPR1bits.ADIP=0)//set the interrupt for the ADC to be low priority

#endif
  #endif

 #if TIMER0_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define TIMER0_Interrupt_Disable() (INTCONbits.T0IE=0)// disable the iterrupt  for timer0
#define TIMER0_Interrupt_Enable()  (INTCONbits.T0IE=1)// set the iterrupt enable for timer0

#define TIMER0_Interrupt_Flag_clear() (INTCONbits.TMR0IF=0)// clear the iterrupt flag for the timer0

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define TIMER0_Interrupt_High_priority_set() (INTCON2bits.TMR0IP=1)//set the interrupt for the timer0 to be high priority
#define TIMER0_Interrupt_Low_priority_set()  (INTCON2bits.TMR0IP=0)//set the interrupt for the timer0 to be low priority

#endif
  #endif

 #if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define TIMER1_Interrupt_Disable() (PIE1bits.TMR1IE=0)// disable the iterrupt  for timer1
#define TIMER1_Interrupt_Enable()  (PIE1bits.TMR1IE=1)// set the iterrupt enable for timer1

#define TIMER1_Interrupt_Flag_clear() (PIR1bits.TMR1IF=0)// clear the iterrupt flag for the timer1

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define TIMER1_Interrupt_High_priority_set() (IPR1bits.TMR1IP=1)//set the interrupt for the timer1 to be high priority
#define TIMER1_Interrupt_Low_priority_set()  (IPR1bits.TMR1IP=0)//set the interrupt for the timer1 to be low priority

#endif
  #endif
 #if TIMER2_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define TIMER2_Interrupt_Disable() (PIE1bits.TMR2IE=0)// disable the iterrupt  for timer2
#define TIMER2_Interrupt_Enable()  (PIE1bits.TMR2IE=1)// set the iterrupt enable for timer2

#define TIMER2_Interrupt_Flag_clear() (PIR1bits.TMR2IF=0)// clear the iterrupt flag for the timer2

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define TIMER2_Interrupt_High_priority_set() (IPR1bits.TMR2IP=1)//set the interrupt for the timer2 to be high priority
#define TIMER2_Interrupt_Low_priority_set()  (IPR1bits.TMR2IP=0)//set the interrupt for the timer2 to be low priority

#endif
#endif

 #if TIMER3_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define TIMER3_Interrupt_Disable() (PIE2bits.TMR3IE=0)// disable the iterrupt  for timer3
#define TIMER3_Interrupt_Enable()  (PIE2bits.TMR3IE=1)// set the iterrupt enable for timer3

#define TIMER3_Interrupt_Flag_clear() (PIR2bits.TMR3IF=0)// clear the iterrupt flag for the timer3

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define TIMER3_Interrupt_High_priority_set() (IPR2bits.TMR3IP=1)//set the interrupt for the timer3 to be high priority
#define TIMER3_Interrupt_Low_priority_set()  (IPR2bits.TMR3IP=0)//set the interrupt for the timer3 to be low priority

#endif
#endif

#if CCP1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define CCP1_Interrupt_Disable() (PIE1bits.CCP1IE=0)// disable the iterrupt  for CCP1
#define CCP1_Interrupt_Enable()  (PIE1bits.CCP1IE=1)// set the iterrupt enable for CCP1

#define CCP1_Interrupt_Flag_clear() (PIR1bits.CCP1IF=0)// clear the iterrupt flag for the CCP1

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define CCP1_Interrupt_High_priority_set() (IPR1bits.CCP1IP=1)//set the interrupt for the CCP1 to be high priority
#define CCP1_Interrupt_Low_priority_set()  (IPR1bits.CCP1IP=0)//set the interrupt for the CCP1 to be low priority

#endif
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define CCP2_Interrupt_Disable() (PIE2bits.CCP2IE=0)// disable the iterrupt  for CCP2
#define CCP2_Interrupt_Enable()  (PIE2bits.CCP2IE=1)// set the iterrupt enable for CCP2

#define CCP2_Interrupt_Flag_clear() (PIR2bits.CCP2IF=0)// clear the iterrupt flag for the CCP2

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define CCP2_Interrupt_High_priority_set() (IPR2bits.CCP2IP=1)//set the interrupt for the CCP2 to be high priority
#define CCP2_Interrupt_Low_priority_set()  (IPR2bits.CCP2IP=0)//set the interrupt for the CCP2 to be low priority
#endif
#endif
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define EUSART_TX_Interrupt_Disable() (PIE1bits.TXIE=0)// disable the iterrupt  EUSART_TX
#define EUSART_TX_Interrupt_Enable()  (PIE1bits.TXIE=1)// set the iterrupt enable for EUSART_TX

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define  EUSART_TX_Interrupt_High_priority_set() (IPR1bits.TXIP=1)//set the interrupt for the EUSART_TX to be high priority
#define  EUSART_TX_Interrupt_Low_priority_set()  (IPR1bits.TXIP=0)//set the interrupt for the EUSART_TX to be low priority

#endif
#endif

#if EUSART_RX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define EUSART_RX_Interrupt_Disable() (PIE1bits.RCIE=0)// disable the iterrupt  EUSART_RX
#define EUSART_RX_Interrupt_Enable()  (PIE1bits.RCIE=1)// set the iterrupt enable for EUSART_RX


#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define  EUSART_RX_Interrupt_High_priority_set() (IPR1bits.RCIP=1)//set the interrupt for the EUSART_RX to be high priority
#define  EUSART_RX_Interrupt_Low_priority_set()  (IPR1bits.RCIP=0)//set the interrupt for the EUSART_RX to be low priority

#endif
#endif

#if MSSP_I2C_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   

#define I2C_Interrupt_Disable() (PIE1bits.SSPIE=0)// disable the iterrupt  i2c
#define I2C_Interrupt_Enable()  (PIE1bits.SSPIE=1)// set the iterrupt enable for i2c

#define I2C_Interrupt_Flag_clear() (PIR1bits.SSPIF=0)// clear the iterrupt flag for the i2c

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define  I2C_Interrupt_High_priority_set() (IPR1bits.SSPIP=1)//set the interrupt for the i2c to be high priority
#define  I2C_Interrupt_Low_priority_set()  (IPR1bits.SSPIP=0)//set the interrupt for the i2c to be low priority

#endif
#endif

#if MSSP_I2C_BUS_COL_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE  

#define I2C_BUS_COL_Disable() (PIE2bits.BCLIE=0)// disable the iterrupt for bus colision in i2c
#define I2C_BUS_COL_Enable() (PIE2bits.BCLIE=1)// set the iterrupt enable for bus colision in i2c

#define I2C_BUS_COL_Interrupt_Flag_clear() (PIR2bits.BCLIF=0)// clear the iterrupt flag for bus colision in i2c

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define I2C_BUS_COL_Interrupt_High_priority_set() (IPR2bits.BCLIP=1)//set the interrupt for bus colision in the i2c to be high priority
#define I2C_BUS_COL_Interrupt_Low_priority_set()  (IPR2bits.BCLIP=0)//set the interrupt for bus colision in the i2c to be low priority
#endif
#endif
/********************************data types  section********************************/



/*******************************function declarations section*************************************/


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

