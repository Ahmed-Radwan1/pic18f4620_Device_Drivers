/* 
 * File:   ecu_led.h
 * Author: ahmed radwan
 *
 * Created on June 28, 2022, 4:24 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*include section*/
#include"../../MCAL/GPIO/hal_gpio.h"
#include"ecu_led_cfg.h"

/*macros declarations section*/


/*data types  section*/

typedef enum {
    LED_OFF=0,
    LED_ON        
}led_status_t;
typedef struct {
  uint8 port_name:3;  
  uint8 pin:3; 
  uint8 led_status:1; 
  uint8 reserved:1; 
}led_t;           
/*function declarations section*/

Std_returnType led_initialize(const led_t *led);

Std_returnType led_turn_on(const led_t *led);

Std_returnType led_turn_off(const led_t *led);

Std_returnType led_turn_toggle(const led_t *led);
#endif	/* ECU_LED_H */

