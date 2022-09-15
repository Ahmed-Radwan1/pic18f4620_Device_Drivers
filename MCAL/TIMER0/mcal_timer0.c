/* 
 * File:   mcal_timer0.c
 * Author: ahmed radwan
 *
 * Created on August 28, 2022, 12:24 AM
 */
#include"mcal_timer0.h"

static inline void Timer0_Prescaler_Config(const timer0_t* _timer0);
static inline void Timer0_Mode_Select(const timer0_t* _timer0);
static inline void Timer0_Register_Size_Config(const timer0_t* _timer0);
static inline void Timer0_Preload_Value(const timer0_t* _timer0);


uint16 Timer0_PreLoaded_Value_Store=ZERO_INIT;//use in ISR to re write the preload value in the register after the overflow


#if TIMER0_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   
static void (*Timer0_Interrupt_Handler)(void)=NULL;
#endif

Std_returnType Timer0_Init(const timer0_t* _timer0)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer0)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /*timer0 disable*/
        TIMER0_DISABLE();
        /*timer0 set the Prescaler */
        Timer0_Prescaler_Config(_timer0);
        /*timer0 select mode*/
        Timer0_Mode_Select(_timer0);
        /*timer0 set the register size */
        Timer0_Register_Size_Config(_timer0);
        /*set the preloaded value*/
        Timer0_Preload_Value(_timer0);
        Timer0_PreLoaded_Value_Store=_timer0->timer0_preload_value;
        /*interrupt set*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
        TIMER0_Interrupt_Disable();
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
        if(INTERRUPT_HIGH_priority==_timer0->priority)
        {
            TIMER0_Interrupt_High_priority_set();
        }
            else if(INTERRUPT_LOW_priority==_timer0->priority)
            {
                TIMER0_Interrupt_Low_priority_set();
            }
            else{/*no thing*/}

#else
        
        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
#endif 
        TIMER0_Interrupt_Flag_clear();
        TIMER0_Interrupt_Enable();

        Timer0_Interrupt_Handler=_timer0->Timer0_InterruptHandler;
 
#endif
        TIMER0_ENABLE();
    }
    return ERRORSTATUS;
    
}
Std_returnType Timer0_DeInit(const timer0_t* _timer0)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer0)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        TIMER0_DISABLE();
        #if TIMER0_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
        TIMER0_Interrupt_Disable();
        #endif
    }
    return ERRORSTATUS;
    
}
Std_returnType Timer0_Write_Value(const timer0_t* _timer0,uint16 value)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer0)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
       TMR0H=(value)>>8;
       TMR0L=(uint8)(value);  
    }
    return ERRORSTATUS;
    
}
Std_returnType Timer0_Read_Value(const timer0_t* _timer0,uint16 *value)
{
    uint8 tmr0l=ZERO_INIT,tmr0h=ZERO_INIT;
    Std_returnType ERRORSTATUS =E_OK;
    if ((NULL==_timer0)||NULL==value)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        tmr0l=TMR0L;
        tmr0h=TMR0H;
     *value=(uint16)((tmr0h<<8)+tmr0l);
    }
    return ERRORSTATUS;
    
}


void TMR0_ISR(void)
{
   TIMER0_Interrupt_Flag_clear();
   TMR0H=Timer0_PreLoaded_Value_Store>>8;
   TMR0L=(uint8)Timer0_PreLoaded_Value_Store;
   
    if(Timer0_Interrupt_Handler){Timer0_Interrupt_Handler();}
}
static inline void Timer0_Prescaler_Config(const timer0_t* _timer0)
{
   if(_timer0->timer0_prescaler_cfg==TIMER0_PRESCALER_ENABLE)
   {
       TIMER0_PRESCALER_ENABLE();
       TIMER0_PRESCALER_SET_VALUE(_timer0->timer0_prescaler_value); 
   }
   else if (_timer0->timer0_prescaler_cfg==TIMER0_PRESCALER_DISABLE)
   {
       TIMER0_PRESCALER_DISABLE();
   }
   else{/*no thing*/}
}
static inline void Timer0_Mode_Select(const timer0_t* _timer0)
{
   if(_timer0->timer0_mode==COUNTER_MODE )
   {
       TIMER0_COUNTER_MODE();
       if(_timer0->timer0_counter_ege==RISING_EGE)
       {
           TIMER0_COUNTER_RISING_EGE();
       }
       else if(_timer0->timer0_counter_ege==FALING_EGE)
       {
          TIMER0_COUNTER_FALING_EGE();
       }
       else{/*no thing*/}

   }
   else if (_timer0->timer0_mode==TIMER_MODE)
   {
       TIMER0_TIMER_MODE();
   }
   else{/*no thing*/}
}
static inline void Timer0_Register_Size_Config(const timer0_t* _timer0)
{
   if(_timer0->timer0_register_size==timer0_16_bit_reg )
   {
       TIMER0_16_BIT_REGISTER();
   }
   else if(_timer0->timer0_register_size==timer0_8_bit_reg )
   {
       TIMER0_8_BIT_REGISTER();
   }
   else{/*no thing*/}
}   
static inline void Timer0_Preload_Value(const timer0_t* _timer0)
{     
       TMR0H=(_timer0->timer0_preload_value)>>8;
       TMR0L=(uint8)(_timer0->timer0_preload_value);
}   