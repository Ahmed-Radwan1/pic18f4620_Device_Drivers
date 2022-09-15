/* 
 * File:   mcal_ccp1.c
 * Author: ahmed radwan
 *
 * Created on September 1, 2022, 4:48 AM
 */

#include"mcal_ccp1.h"


static void (*CCP1_InterruptHandler)(void);
static Std_returnType CCP1_Capture_compare_Mode_Timer_Select(const ccp1_t *_ccp_obj);
Std_returnType CCP1_Init(const ccp1_t *_ccp_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_ccp_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /*ccp1 disable*/
        CCP1_SET_MODE(CCP1_MODULE_DISABLE);
        /*chose the mode*/

        if(CCP1_CAPTURE_MODE_SELECTED==_ccp_obj->ccp1_mode)
        {
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_CAPTURE_MODE_SELECTED)

          switch(_ccp_obj->ccp1_mode_variant)
          {
              case CCP1_CAPTURE_MODE_1_FALLING_EDGE :
                  CCP1_SET_MODE(CCP1_CAPTURE_MODE_1_FALLING_EDGE);
                  break;
              case CCP1_CAPTURE_MODE_1_RISING_EDGE:
                  CCP1_SET_MODE(CCP1_CAPTURE_MODE_1_RISING_EDGE);
                  break;
              case CCP1_CAPTURE_MODE_4_RISING_EDGE:
                  CCP1_SET_MODE(CCP1_CAPTURE_MODE_4_RISING_EDGE);
                  break; 
                  
              case CCP1_CAPTURE_MODE_16_RISING_EDGE:
                  CCP1_SET_MODE(CCP1_CAPTURE_MODE_16_RISING_EDGE);
                  break;  
              default:
              ERRORSTATUS=E_NOK;    
          }  
          CCP1_Capture_compare_Mode_Timer_Select(_ccp_obj);

#endif 
        }
        else if(CCP1_COMPARE_MODE_SELECTED==_ccp_obj->ccp1_mode)
        {
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_COMPARE_MODE_SELECTED)

          switch(_ccp_obj->ccp1_mode_variant)
          {
              case CCP1_COMPARE_MODE_SET_PIN_LOW :
                  CCP1_SET_MODE(CCP1_COMPARE_MODE_SET_PIN_LOW);
                  break;
              case CCP1_COMPARE_MODE_SET_PIN_HIGH:
                  CCP1_SET_MODE(CCP1_COMPARE_MODE_SET_PIN_HIGH);
                  break;
              case CCP1_COMPARE_MODE_TOGGLE_ON_MATCH:
                  CCP1_SET_MODE(CCP1_COMPARE_MODE_TOGGLE_ON_MATCH);
                  break; 
                  
              case CCP1_COMPARE_MODE_GEN_SW_INTERRUPT:
                  CCP1_SET_MODE(CCP1_COMPARE_MODE_GEN_SW_INTERRUPT);
                  break;            
              case CCP1_COMPARE_MODE_GEN_EVENT:
                  CCP1_SET_MODE(CCP1_COMPARE_MODE_GEN_EVENT);
                  break;
              default:
              ERRORSTATUS=E_NOK; 
          }
          CCP1_Capture_compare_Mode_Timer_Select(_ccp_obj);
#endif 

        }
        else if(CCP1_PWM_MODE_SELECTED==_ccp_obj->ccp1_mode)
        {
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_PWM_MODE_SELECTED)

            CCP1_SET_MODE(CCP1_PWM_MODE);
            
            /*initialize the PWM frequency */
            // the +1 add here because the prescaler and the postscaler in timer 2 configuration start from 0 not from 1
            PR2=(uint8)((_XTAL_FREQ/(4*((_ccp_obj->ccp_timer2.timer2_postscaler_value)+1)*((_ccp_obj->ccp_timer2.timer2_prescaler_value)+1)*(_ccp_obj->PWM1_frequancy)))-1);
             /*configure timer2*/  
            ERRORSTATUS= Timer2_Init(&(_ccp_obj->ccp_timer2));
#endif            

        } 
         else{/*nothing*/}
        
        /*configure the direction of the pin to be output or input*/
        ERRORSTATUS=gpio_pin_initialize(&(_ccp_obj->ccp1_pin));
        /*set the interrupt configuration*/
#if CCP1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
        CCP1_Interrupt_Disable();
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
        if(INTERRUPT_HIGH_priority==_ccp_obj->CCP1_priority)
        {
           CCP1_Interrupt_High_priority_set();
        }
            else if(INTERRUPT_LOW_priority==_ccp_obj->CCP1_priority)
            {
                CCP1_Interrupt_Low_priority_set();
            }
            else{/*no thing*/}

#else

        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
#endif 
        CCP1_Interrupt_Flag_clear();
        CCP1_Interrupt_Enable();

        CCP1_InterruptHandler=_ccp_obj->CCP1_InterruptHandler;
       
       
#endif
    }

    return ERRORSTATUS;     
}
Std_returnType CCP1_DeInit(const ccp1_t *_ccp_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_ccp_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        CCP1_SET_MODE(CCP1_MODULE_DISABLE);
#if CCP1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
        CCP1_Interrupt_Disable();
#endif
    }
    return ERRORSTATUS;    
}
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_CAPTURE_MODE_SELECTED)
Std_returnType CCP1_IsCapturedDataReady(uint8 *_capture_status)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_capture_status)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        if(CCP1_CAPTURE_READY==PIR1bits.CCP1IF)
        {
         * _capture_status=  CCP1_CAPTURE_READY;
         CCP1_Interrupt_Flag_clear();//
        }
        else
        {
          * _capture_status=  CCP1_CAPTURE_NOT_READY;   
        }
    }
    return ERRORSTATUS;    
}
Std_returnType CCP1_Capture_Mode_Read_Value(uint16 *capture_value)
{
    CCP1_REG_T Capture_Temp_Value={.ccpr_16Bit=0};
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==capture_value)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        Capture_Temp_Value.ccpr_low=CCPR1L;
        Capture_Temp_Value.ccpr_high=CCPR1H;
        *capture_value=Capture_Temp_Value.ccpr_16Bit;
    }
    return ERRORSTATUS;       
}

#endif
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_COMPARE_MODE_SELECTED)
Std_returnType CCP1_IsCompareComplete(uint8 *_compare_status)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_compare_status)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        if(CCP1_COMPARE_READY==PIR1bits.CCP1IF)
        {
         * _compare_status=CCP1_COMPARE_READY;
         CCP1_Interrupt_Flag_clear();//
        }
        else
        {
          * _compare_status=CCP1_COMPARE_NOT_READY;   
        }
    }
    return ERRORSTATUS;       
}
Std_returnType CCP1_Compare_Mode_Set_Value(uint16 compare_value)
{
    Std_returnType ERRORSTATUS =E_OK;
     CCP1_REG_T Compare_Temp_Value={.ccpr_16Bit=compare_value};
        CCPR1L=Compare_Temp_Value.ccpr_low;
        CCPR1H=Compare_Temp_Value.ccpr_high;
    return ERRORSTATUS;       
}
#endif
#if (CCP1_CFG_SELECTED_MODE==CCP1_CFG_PWM_MODE_SELECTED)
Std_returnType CCP1_PWM_Set_Duty( const uint8 _duty)
{
    uint16 duty_temp=0;
     duty_temp=(uint16)((PR2+1)*(_duty/100.0)*4);   
     CCP1CONbits.DC1B=duty_temp&(0x0003);
     CCPR1L=(duty_temp>>2);                                    
}

Std_returnType CCP1_PWM_Start()
{
    CCP1CONbits.CCP1M=CCP1_PWM_MODE;    
}
Std_returnType CCP1_PWM_Stop()
{  
    CCP1CONbits.CCP1M=CCP1_MODULE_DISABLE;   
}

#endif
void CCP1_ISR(void)
{
   CCP1_Interrupt_Flag_clear();
    if(CCP1_InterruptHandler){CCP1_InterruptHandler();}
}
static Std_returnType CCP1_Capture_compare_Mode_Timer_Select(const ccp1_t *_ccp_obj)
{
    if(CCP1_CCP2_TIMER3==_ccp_obj->ccp_capture_compare_timer)
    {
        /* Timer3 is the capture/compare clock source for the CCP modules*/
        T3CONbits.T3CCP1=0;
        T3CONbits.T3CCP2=1;
    }
    else if(CCP1_TIMER1_CCP2_TIMER3==_ccp_obj->ccp_capture_compare_timer)
    {
        /* Timer3 is the capture/compare clock source for CCP2*/
        /*Timer1 is the capture/compare clock source for CCP1*/
        T3CONbits.T3CCP1=1;
        T3CONbits.T3CCP2=0;
    }
    else if(CCP1_CCP2_TIMER1==_ccp_obj->ccp_capture_compare_timer)
    {
        /*Timer1 is the capture/compare clock source for the CCP modules*/
        T3CONbits.T3CCP1=0;
        T3CONbits.T3CCP2=0; 
    }
    else{/*nothing*/}
}