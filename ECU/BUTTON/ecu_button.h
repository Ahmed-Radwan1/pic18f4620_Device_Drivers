/* 
 * File:   ecu_button.c
 * Author: radwan
 *
 * Created on July 16, 2022, 3:29 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*****************************include section****************************/

#include"ecu_button_cfg.h"
#include"../../MCAL/GPIO/hal_gpio.h"



/********************** macros declarations section************************/


/*data types  section*/
typedef enum{
    BUTTON_PRESSED=0,
    BUTTON_RELASED
}button_state_t;
typedef enum{
     BUTTON_ACTIVE_HIGH=0,
     BUTTON_ACTIVE_LOW
    
}button_active_t;

typedef struct {
  
  pin_config_t button_pin;
  button_state_t button_state;
  button_active_t button_conection;
  
}button_t;

/*function declarations section*/
Std_returnType button_initialize(const button_t*btn);
Std_returnType button_read_state(const button_t*btn,button_state_t*btn_state);

#endif	/* ECU_BUTTON_H */

