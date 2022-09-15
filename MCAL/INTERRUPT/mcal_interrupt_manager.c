/* 
 * File:   mcal_interrupt_manager.c
 * Author: ahmed radwan
 *
 * Created on August 5, 2022, 8:11 PM
 */
#include"mcal_interrupt_manager.h"


volatile static uint8 RB4_flag=1;
volatile static uint8 RB5_flag=1;
volatile static uint8 RB6_flag=1;
volatile static uint8 RB7_flag=1;

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
void __interrupt() Interrupt_Manager_High(void)
{
     if((INTERRUPT_ENABLE==INTCONbits.INT0E)&&(INTERRUPT_OCCUR==INTCONbits.INT0F))
    {
       INT0_ISR();
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCON3bits.INT2E)&&(INTERRUPT_OCCUR==INTCON3bits.INT2F))
    {
        INT2_ISR();

    }  
    else{/*nothing*/} 
}
void __interrupt(low_priority) Interrupt_Manager_Low(void)
{
    if((INTERRUPT_ENABLE==INTCON3bits.INT1E)&&(INTERRUPT_OCCUR==INTCON3bits.INT1F))
    {
        INT1_ISR();

    }  
    else{/*nothing*/} 
 
}
#else
void __interrupt() Interrupt_Manager(void)
{
     if((INTERRUPT_ENABLE==INTCONbits.INT0E)&&(INTERRUPT_OCCUR==INTCONbits.INT0F))
    {      
       INT0_ISR();
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCON3bits.INT1E)&&(INTERRUPT_OCCUR==INTCON3bits.INT1F))
    {
        INT1_ISR();

    }  
    else{/*nothing*/}    
    if((INTERRUPT_ENABLE==INTCON3bits.INT2E)&&(INTERRUPT_OCCUR==INTCON3bits.INT2F))
    {
        INT2_ISR();
    }  
    else{/*nothing*/}  
    if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB4==GPIO_HIGH)&&(RB4_flag==1))
    {
        RB4_flag=0;
        RB4_ISR(1);
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB4==GPIO_LOW&&(RB4_flag==0)))
    {
        RB4_flag=1;
        RB4_ISR(0);
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB5==GPIO_HIGH)&&(RB5_flag==1))
    {
        RB5_flag=0; 
        RB5_ISR(1);
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB5==GPIO_LOW)&&(RB5_flag==0))
    {
        RB5_flag=1;
        RB5_ISR(0);
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB6==GPIO_HIGH)&&(RB6_flag==1))
    {
        RB6_flag=0;
        RB6_ISR(1);
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB6==GPIO_LOW)&&(RB6_flag==0))
    {
        RB6_flag=1;
        RB6_ISR(0);
    }  
    else{/*nothing*/}
         if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB7==GPIO_HIGH)&&(RB7_flag==1))
    {
        RB7_flag=0;
        RB7_ISR(1);
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCCUR==INTCONbits.RBIF)&&(PORTBbits.RB7==GPIO_LOW)&&(RB7_flag==0))
    {
        RB7_flag=1;
        RB7_ISR(0);
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==PIE1bits.ADIE)&&(INTERRUPT_OCCUR==PIR1bits.ADIF))
    {
        ADC_ISR();
    }  
    else{/*nothing*/}
     if((INTERRUPT_ENABLE==INTCONbits.T0IE)&&(INTERRUPT_OCCUR==INTCONbits.T0IF))
    {
        TMR0_ISR();
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==PIE1bits.TMR1IE)&&(INTERRUPT_OCCUR==PIR1bits.TMR1IF))
    {
        TMR1_ISR();
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==PIE1bits.TMR2IE)&&(INTERRUPT_OCCUR==PIR1bits.TMR2IF))
    {
        TMR2_ISR();
    }  
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==PIE2bits.TMR3IE)&&(INTERRUPT_OCCUR==PIR2bits.TMR3IF))
    {
        TMR3_ISR();
    }  
    else{/*nothing*/}  
    if((INTERRUPT_ENABLE==PIE1bits.CCP1IE)&&(INTERRUPT_OCCUR==PIR1bits.CCP1IF))
    {
        CCP1_ISR();
    }  
    else{/*nothing*/} 
    if((INTERRUPT_ENABLE==PIE1bits.TXIE)&&(INTERRUPT_OCCUR==PIR1bits.TXIF))
    {
        EUSART_TX_ISR();
    }  
    else{/*nothing*/} 
    if((INTERRUPT_ENABLE==PIE1bits.RCIE)&&(INTERRUPT_OCCUR==PIR1bits.RCIF))
    {
        EUSART_RX_ISR();
    }  
    else{/*nothing*/} 
    if((INTERRUPT_ENABLE==PIE1bits.SSPIE)&&(INTERRUPT_OCCUR==PIR1bits.SSPIF))
    {
        I2C_ISR();
    }  
    else{/*nothing*/}     
    if((INTERRUPT_ENABLE==PIE2bits.BCLIE)&&(INTERRUPT_OCCUR==PIR2bits.BCLIF))
    {
        I2C_BC_ISR();
    }  
    else{/*nothing*/}      
}
  
#endif