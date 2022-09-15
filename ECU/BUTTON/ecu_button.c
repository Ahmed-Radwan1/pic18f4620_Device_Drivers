/* 
 * File:   ecu_button.h
 * Author: radwan
 *
 * Created on July 16, 2022, 3:29 AM
 */
#include"ecu_button.h"

/**
 * 
 * @param btn
 * @return 
 */
Std_returnType button_initialize(const button_t*btn)
{
     Std_returnType ERRORSTATUS =E_OK;
     if ( NULL==btn)
    {
        ERRORSTATUS=E_NOK;
    }
     else
     {
       ERRORSTATUS= gpio_pin_direction_initialize(&(btn->button_pin)); 
        
     }
     
       return ERRORSTATUS;  
}


/**
 * 
 * @param btn
 * @param btn_state
 * @return 
 */
Std_returnType button_read_state(const button_t*btn,button_state_t*btn_state)
{
    Std_returnType ERRORSTATUS =E_OK;
    logic_t button_logic_status=GPIO_LOW;
     if ( NULL==btn|| NULL==btn_state)
    {
        ERRORSTATUS=E_NOK;
    }
     else
     {
         ERRORSTATUS= gpio_pin_read_logic(&(btn->button_pin),&button_logic_status);
         if(BUTTON_ACTIVE_HIGH==btn->button_conection)
         {
             if(GPIO_HIGH==button_logic_status)
             {
                *btn_state=BUTTON_PRESSED;
             }
             else
             {
                 *btn_state=BUTTON_RELASED;
  
             }
         }
         else if(BUTTON_ACTIVE_LOW==btn->button_conection)
         {
             if(GPIO_LOW==button_logic_status)
             {
                 *btn_state=BUTTON_PRESSED;
             }
             else
             {
                 *btn_state=BUTTON_RELASED;
  
             }
         }
         else{/*no thing*/}
         
         ERRORSTATUS=E_OK;
     }
       return ERRORSTATUS; 
}
