/* 
 * File:   ecu_relay.h
 * Author: radwan
 *
 * Created on July 17, 2022, 6:33 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H


/*include section*/
#include"../../MCAL/GPIO/hal_gpio.h"
#include"relay_cnfg.h"
/*macros declarations section*/


/*data types  section*/

typedef enum {
    RELAY_OFF=0,
    RELAY_ON        
}RELAY_status_t;
typedef struct {
  uint8 relay_port:3;  
  uint8 relay_pin:3; 
  uint8 relay_status:3; 
  uint8 reserved:1; 
}relay_t;           
/*function declarations section*/

Std_returnType relay_initialize(const relay_t *relay);

Std_returnType relay_turn_on(const relay_t *relay);

Std_returnType relay_turn_off(const relay_t *relay);

#endif	/* ECU_LED_H */




