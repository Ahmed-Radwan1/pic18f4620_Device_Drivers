/* 
 * File:   ecu_relay.c
 * Author: radwan
 *
 * Created on July 17, 2022, 6:33 AM
 */
#include"ecu_relay.h"

Std_returnType relay_initialize(const relay_t *relay)
{
    Std_returnType ERRORSTATUS =E_OK;
    if ( NULL==relay)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        pin_config_t relay_opj={
        .port=relay->relay_port,
        .pin=relay->relay_pin,
        .direction=GPIO_DIRECTION_OUTPUT,
        .logic=relay->relay_status
        }; 
        
          ERRORSTATUS = gpio_pin_initialize(&relay_opj);
    }
     
    return ERRORSTATUS;
}
Std_returnType relay_turn_on(const relay_t *relay)
{
    Std_returnType ERRORSTATUS =E_OK;
    
    if ( NULL==relay)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        pin_config_t relay_opj={
        .port=relay->relay_port,
        .pin=relay->relay_pin,
        .direction=GPIO_DIRECTION_OUTPUT,
        .logic=relay->relay_status
        }; 
      ERRORSTATUS=gpio_pin_write_logic(&relay_opj, GPIO_HIGH);
            
    }
     
    return ERRORSTATUS;
}

Std_returnType relay_turn_off(const relay_t *relay)
{
            Std_returnType ERRORSTATUS =E_OK;
    if ( NULL==relay)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
         pin_config_t relay_opj={
        .port=relay->relay_port,
        .pin=relay->relay_pin,
        .direction=GPIO_DIRECTION_OUTPUT,
        .logic=relay->relay_status
        }; 
        ERRORSTATUS=gpio_pin_write_logic(&relay_opj,GPIO_LOW);
            
    }
     
    return ERRORSTATUS;
}