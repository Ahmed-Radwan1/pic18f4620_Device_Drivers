/* 
 * File:   mcal_timer1.c
 * Author: ahmed radwan
 *
 * Created on August 29, 2022, 4:16 AM
 */
#include"mcal_timer1.h"

static inline void Timer1_Prescaler_Config(const timer1_t* _timer1);
static inline void Timer1_Mode_Select(const timer1_t* _timer1);
static inline void Timer1_RW_Mode_Select(const timer1_t* _timer1);
static inline void Timer1_Preload_Value(const timer1_t* _timer1);


uint16 Timer1_PreLoaded_Value_Store=ZERO_INIT;//use in ISR to re write the preload value in the register after the overflow


#if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   
static void (*Timer1_Interrupt_Handler)(void)=NULL;
#endif

Std_returnType Timer1_Init(const timer1_t* _timer1)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer1)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /*timer1 disable*/
        TIMER1_DISABLE();
        /*timer1 set the Prescaler */
        Timer1_Prescaler_Config(_timer1);
        /*timer1 select mode*/
        Timer1_Mode_Select(_timer1);
        /*timer1 set the R/W Mode */
        Timer1_RW_Mode_Select(_timer1);
        /*set the preloaded value*/
        Timer1_Preload_Value(_timer1);
        Timer1_PreLoaded_Value_Store=_timer1->timer1_preload_value;
        /*interrupt set*/
#if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
        TIMER1_Interrupt_Disable();
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
        if(INTERRUPT_HIGH_priority==_timer1->priority)
        {
            TIMER1_Interrupt_High_priority_set();
        }
            else if(INTERRUPT_LOW_priority==_timer1->priority)
            {
                TIMER1_Interrupt_Low_priority_set();
            }
            else{/*no thing*/}

#else

        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
#endif 
        TIMER1_Interrupt_Flag_clear();
        TIMER1_Interrupt_Enable();

        Timer1_Interrupt_Handler=_timer1->Timer1_InterruptHandler;
 
#endif
        TIMER1_ENABLE();
    }
    return ERRORSTATUS;    
}
Std_returnType Timer1_DeInit(const timer1_t* _timer1)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer1)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        TIMER1_DISABLE();
        #if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
        TIMER1_Interrupt_Disable();
        #endif
    }
    return ERRORSTATUS;
}
Std_returnType Timer1_Write_Value(const timer1_t* _timer1,uint16 value)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer1)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
       TMR1H=(value)>>8;
       TMR1L=(uint8)(value);  
    }
    return ERRORSTATUS;
    
}       
Std_returnType Timer1_Read_Value(const timer1_t* _timer1,uint16 *value)
{
     uint8 tmr1l=ZERO_INIT,tmr1h=ZERO_INIT;
    Std_returnType ERRORSTATUS =E_OK;
    if ((NULL==_timer1)||(NULL==value ))
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        tmr1l=TMR1L;
        tmr1h=TMR1H;
     *value=(uint16)((tmr1h<<8)+tmr1l);
    }
    return ERRORSTATUS;
       
}


void TMR1_ISR(void)
{
   TIMER1_Interrupt_Flag_clear();
   TMR1H=Timer1_PreLoaded_Value_Store>>8;
   TMR1L=(uint8)Timer1_PreLoaded_Value_Store;
    if(Timer1_Interrupt_Handler){Timer1_Interrupt_Handler();}
}
static inline void Timer1_Prescaler_Config(const timer1_t* _timer1)
{
       TIMER1_PRESCALER_SET_VALUE(_timer1->timer1_prescaler_value); 
}
static inline void Timer1_Mode_Select(const timer1_t* _timer1)
{
   if(_timer1->timer1_mode==TIMER1_COUNTER_MODE_CFG)
   {
       TIMER1_COUNTER_MODE();
       if(_timer1->counter_mode==TIMER1_SYNC_COUNTER_MODE_CFG)
       {
           TIMER1_SYNC_COUNTER_MODE(); 
       }
       else if(_timer1->counter_mode==TIMER1_ASYNC_COUNTER_MODE_CFG)
       {
           TIMER1_ASYNC_COUNTER_MODE(); 
       }
       else{/*no thing*/}
   }
   else if (_timer1->timer1_mode==TIMER1_TIMER_MODE_CFG)
   {
       TIMER1_TIMER_MODE();
   }
   else{/*no thing*/}
}
static inline void Timer1_RW_Mode_Select(const timer1_t* _timer1)
{
   if(_timer1->timer1_register_mode==TIMER1_RW_REG_8BIT_MODE )
   {
       TIMER1_RW_REG_8BIT_MODE_set();
   }
   else if(_timer1->timer1_register_mode==TIMER1_RW_REG_16BIT_MODE )
   {
       TIMER1_RW_REG_16BIT_MODE_set();
   }
   else{/*no thing*/}
}   
static inline void Timer1_Preload_Value(const timer1_t* _timer1)
{     
       TMR1H=(_timer1->timer1_preload_value)>>8;
       TMR1L=(uint8)(_timer1->timer1_preload_value);
}  