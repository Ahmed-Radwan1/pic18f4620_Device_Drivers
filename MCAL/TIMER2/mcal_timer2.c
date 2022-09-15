/* 
 * File:   mcal_timer2.c
 * Author: ahmed radwan
 *
 * Created on August 29, 2022, 11:54 PM
 */
#include"mcal_timer2.h"

#if TIMER0_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   
static void (*Timer2_Interrupt_Handler)(void)=NULL;
#endif

uint8 Timer2_PreLoaded_Value_Store=ZERO_INIT;


Std_returnType Timer2_Init(const timer2_t* _timer2)
{
     Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer2)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /*timer1 disable*/
        TIMER2_DISABLE();
        /*timer1 set the Prescaler */
        TIMER2_PRESCALER_SET_VALUE(_timer2->timer2_prescaler_value);
         /*timer1 set the postscaler */
        TIMER2_POSTSCALER_SET_VALUE(_timer2->timer2_postscaler_value);      
        /*set the preloaded value*/
        TMR2=_timer2->timer2_preload_value;
        Timer2_PreLoaded_Value_Store=_timer2->timer2_preload_value;
        /*interrupt set*/
#if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
        TIMER1_Interrupt_Disable();
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
        if(INTERRUPT_HIGH_priority==_timer2->priority)
        {
            TIMER2_Interrupt_High_priority_set();
        }
            else if(INTERRUPT_LOW_priority==_timer2->priority)
            {
                TIMER2_Interrupt_Low_priority_set();
            }
            else{/*no thing*/}

#else

        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
#endif 
        TIMER2_Interrupt_Flag_clear();
        TIMER2_Interrupt_Enable();

        Timer2_Interrupt_Handler=_timer2->Timer2_InterruptHandler;
 
#endif
        TIMER2_ENABLE();
    }
    return ERRORSTATUS;       
}
Std_returnType Timer2_DeInit(const timer2_t* _timer2)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer2)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        TIMER2_DISABLE();
        #if TIMER2_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
        TIMER2_Interrupt_Disable();
        #endif
    }
    return ERRORSTATUS;    
}
Std_returnType Timer2_Write_Value(const timer2_t* _timer2,uint8 value)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer2)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        TMR2=value;
    }
    return ERRORSTATUS;    
   
}
Std_returnType Timer2_Read_Value(const timer2_t* _timer2,uint8 *value)
{
     
    Std_returnType ERRORSTATUS =E_OK;
    if ((NULL==_timer2)||(NULL==value ))
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        *value=TMR2;
    }
    return ERRORSTATUS;   
    
}
void TMR2_ISR(void)
{
   TIMER2_Interrupt_Flag_clear();
   TMR2=Timer2_PreLoaded_Value_Store;
   if(Timer2_Interrupt_Handler){Timer2_Interrupt_Handler();}
}