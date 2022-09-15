/* 
 * File:   ecu_layer_init.h
 * Author: ahmed radwan
 *
 * Created on July 23, 2022, 3:40 AM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

/*include section*/

#include "../MCAL/device_config.h"
#include "../MCAL/GPIO/hal_gpio.h"
#include "LED/ecu_led.h"
#include "BUTTON/ecu_button.h"
#include "RELAY/ecu_relay.h"
#include "DC_MOTOR/ecu_dc_motor.h"
#include "SEVEN_SEGMENT/ecu_seven_segment.h"
#include "KEY_PAD/ecu_kaypad.h"
#include "CHAR_LCD/ecu_char_lcd.h"

/*macros declarations section*/



/*data types  section*/

/*function declarations section*/
void ecu_layer_initialize(void);
#endif	/* ECU_LAYER_INIT_H */

