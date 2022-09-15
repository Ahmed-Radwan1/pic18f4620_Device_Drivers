/* 
 * File:   mcal_timer3.C
 * Author: ahmed radwan
 *
 * Created on August 30, 2022, 12:00 AM
 */

#include"mcal_timer3.h"

static inline void Timer3_Prescaler_Config(const timer3_t* _timer3);
static inline void Timer3_Mode_Select(const timer3_t* _timer3);
static inline void Timer3_RW_Mode_Select(const timer3_t* _timer3);
static inline void Timer3_Preload_Value(const timer3_t* _timer3);

uint16 Timer3_PreLoaded_Value_Store=ZERO_INIT;//use in ISR to re write the preload value in the register after the overflow

#if TIMER3_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   
static void (*Timer3_Interrupt_Handler)(void)=NULL;
#endif


Std_returnType Timer3_Init(const timer3_t* _timer3)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer3)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /*timer3 disable*/
        TIMER3_DISABLE();
        /*timer3 set the Prescaler */
        Timer3_Prescaler_Config(_timer3);
        /*timer3 select mode*/
        Timer3_Mode_Select(_timer3);
        /*timer3 set the R/W Mode */
        Timer3_RW_Mode_Select(_timer3);
        /*set the preloaded value*/
        Timer3_Preload_Value(_timer3);
        Timer3_PreLoaded_Value_Store=_timer3->timer3_preload_value;
        /*interrupt set*/    
#if TIMER3_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
        TIMER3_Interrupt_Disable();
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
        if(INTERRUPT_HIGH_priority==_timer3->priority)
        {
            TIMER3_Interrupt_High_priority_set();
        }
            else if(INTERRUPT_LOW_priority==_timer3->priority)
            {
                TIMER3_Interrupt_Low_priority_set();
            }
            else{/*no thing*/}

#else

        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
#endif 
        TIMER3_Interrupt_Flag_clear();
        TIMER3_Interrupt_Enable();

        Timer3_Interrupt_Handler=_timer3->Timer3_InterruptHandler;
 
#endif
        TIMER3_ENABLE();   
    }
    return ERRORSTATUS ;
}
Std_returnType Timer3_DeInit(const timer3_t* _timer3)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer3)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        TIMER3_DISABLE();
        #if TIMER3_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
        TIMER3_Interrupt_Disable();
        #endif
    }
    return ERRORSTATUS;    
}
Std_returnType Timer3_Write_Value(const timer3_t* _timer3,uint16 value)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_timer3)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
       TMR3H=(value)>>8;
       TMR3L=(uint8)(value);  
    }
    return ERRORSTATUS;    
}
Std_returnType Timer3_Read_Value(const timer3_t* _timer3,uint16 *value)
{
     uint8 tmr3l=ZERO_INIT,tmr3h=ZERO_INIT;
    Std_returnType ERRORSTATUS =E_OK;
    if ((NULL==_timer3)||(NULL==value ))
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        tmr3l=TMR3L;
        tmr3h=TMR3H;
     *value=(uint16)((tmr3h<<8)+tmr3l);
    }
    return ERRORSTATUS;   
}

void TMR3_ISR(void)
{
   TIMER3_Interrupt_Flag_clear();
   TMR3H=Timer3_PreLoaded_Value_Store>>8;
   TMR3L=(uint8)Timer3_PreLoaded_Value_Store;
    if(Timer3_Interrupt_Handler){Timer3_Interrupt_Handler();}
}
static inline void Timer3_Prescaler_Config(const timer3_t* _timer3)
{
       TIMER3_PRESCALER_SET_VALUE(_timer3->timer3_prescaler_value); 
}
static inline void Timer3_Mode_Select(const timer3_t* _timer3)
{
   if(_timer3->timer3_mode==TIMER3_COUNTER_MODE_CFG)
   {
       TIMER3_COUNTER_MODE();
       if(_timer3->counter_mode==TIMER3_SYNC_COUNTER_MODE_CFG)
       {
           TIMER3_SYNC_COUNTER_MODE(); 
       }
       else if(_timer3->counter_mode==TIMER3_ASYNC_COUNTER_MODE_CFG)
       {
           TIMER3_ASYNC_COUNTER_MODE(); 
       }
       else{/*no thing*/}
   }
   else if (_timer3->timer3_mode==TIMER3_TIMER_MODE_CFG)
   {
       TIMER3_TIMER_MODE();
   }
   else{/*no thing*/}
}
static inline void Timer3_RW_Mode_Select(const timer3_t* _timer3)
{
   if(_timer3->timer3_register_mode==TIMER3_RW_REG_8BIT_MODE )
   {
       TIMER3_RW_REG_8BIT_MODE_set();
   }
   else if(_timer3->timer3_register_mode==TIMER3_RW_REG_16BIT_MODE )
   {
       TIMER3_RW_REG_16BIT_MODE_set();
   }
   else{/*no thing*/}
}   
static inline void Timer3_Preload_Value(const timer3_t* _timer3)
{     
       TMR3H=(_timer3->timer3_preload_value)>>8;
       TMR3L=(uint8)(_timer3->timer3_preload_value);
}