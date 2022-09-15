/* 
 * File:   ecu_kaypad.h
 * Author: ahmed radwan
 *
 * Created on July 23, 2022, 2:02 AM
 */

#ifndef ECU_KAYPAD_H
#define	ECU_KAYPAD_H

/*include section*/
#include"../../MCAL/GPIO/hal_gpio.h"
#include"ecu_keypad_cnfg.h"
/*macros declarations section*/

#define KEYPAD_ROWS_NO   4
#define KEYPAD_COLUMS_NO 4
/*data types  section*/
typedef struct{
    pin_config_t keypad_rows_pins[KEYPAD_ROWS_NO]; 
    pin_config_t keypad_colums_pins[KEYPAD_COLUMS_NO]; 
}keypad_t;

/*function declarations section*/

Std_returnType keypad_initialize(const keypad_t*_keypad);
Std_returnType keypad_get_value(const keypad_t*_keypad,uint8* value);



#endif	/* ECU_KAYPAD_H */

