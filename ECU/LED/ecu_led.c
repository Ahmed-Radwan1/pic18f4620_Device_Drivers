/* 
 * File:   ecu_led.h
 * Author: ahmed radwan
 *
 * Created on June 28, 2022, 4:24 AM
 */
#include "ecu_led.h"

/**
 * @brief initialize  the assigned pin to be output to control on the led
 * @param led pinter to led module configuration
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_returnType led_initialize(const led_t *led)
{
    Std_returnType ERRORSTATUS =E_OK;
    pin_config_t pin_opj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=GPIO_DIRECTION_OUTPUT,
        .logic=led->led_status                   
    };
      if ( NULL==led)
     {
        ERRORSTATUS=E_NOK;
     }
      else
     {
         ERRORSTATUS= gpio_pin_initialize(&pin_opj);
        
     }
     return ERRORSTATUS;   
}
/**
 * @brief turn the led on
 * @param led pinter to led module configuration
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_returnType led_turn_on(const led_t *led)
{
    Std_returnType ERRORSTATUS =E_OK;
        pin_config_t pin_opj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=GPIO_DIRECTION_OUTPUT,
        .logic=led->led_status                   
    };
      if ( NULL==led)
     {
        ERRORSTATUS=E_NOK;
     }
      else
     {
         ERRORSTATUS= gpio_pin_write_logic (&pin_opj,GPIO_HIGH );
     
     }
     return ERRORSTATUS;      
}
/**
 * @brief turn the led off
 * @param led pinter to led module configuration
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_returnType led_turn_off(const led_t *led)
{
    Std_returnType ERRORSTATUS =E_OK;
        pin_config_t pin_opj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=GPIO_DIRECTION_OUTPUT,
        .logic=led->led_status                   
    };
      if ( NULL==led)
     {
        ERRORSTATUS=E_NOK;
     }
      else
     {
        ERRORSTATUS=  gpio_pin_write_logic (&pin_opj,GPIO_LOW );
     
     }
     return ERRORSTATUS;      
}
/**
 * @brief toggle the status of the led 
 * @param led
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_returnType led_turn_toggle(const led_t *led)
{
    Std_returnType ERRORSTATUS =E_OK;
        pin_config_t pin_opj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=GPIO_DIRECTION_OUTPUT,
        .logic=led->led_status                   
    };
      if ( NULL==led)
     {
        ERRORSTATUS=E_NOK;
     }
      else
     {
       ERRORSTATUS= gpio_pin_toggle_logic  (&pin_opj);
     
     }
     return ERRORSTATUS;      
}
