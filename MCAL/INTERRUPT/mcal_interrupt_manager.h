/* 
 * File:   mcal_interrupt_manager.h
 * Author: ahmed radwan
 *
 * Created on August 5, 2022, 8:11 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H


/********************************include section********************************/
#include"mcal_interrupt_config.h"


/********************************macros declarations section********************************/



/********************************data types  section********************************/



/*******************************function declarations section*************************************/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8 RB4_source);
void RB5_ISR(uint8 RB5_source);
void RB6_ISR(uint8 RB6_source);
void RB7_ISR(uint8 RB7_source);


void ADC_ISR(void);
void TMR0_ISR(void);
void TMR1_ISR(void);
void TMR2_ISR(void);
void TMR3_ISR(void);
void CCP1_ISR(void);

void EUSART_TX_ISR(void);
void EUSART_RX_ISR(void);
void EUSART_RX_Framing_ISR(void);
void EUSART_RX_Overrun_ISR(void);


void I2C_ISR(void);
void I2C_BC_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

