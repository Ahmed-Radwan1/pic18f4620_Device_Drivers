/* 
 * File:   ecu_dc_motor.h
 * Author: ahmed radwan
 *
 * Created on July 21, 2022, 12:28 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H


/*include section*/
#include"ecu_dc_motor_cfg.h"
#include"../../MCAL/GPIO/hal_gpio.h"
 

/*macros declarations section*/


/*data types  section*/
typedef enum {
    DC_MOTOR_OFF=0,
    DC_MOTOR_ON        
}dc_motor_status_t;
typedef enum {
    DC_MOTOR_PIN1=0,
    DC_MOTOR_PIN2       
}dc_motor_pins_t;
typedef struct {
    pin_config_t dc_motor_pin[2];
}dc_motor_t;  

/*function declarations section*/
Std_returnType dc_motor_initialize(const dc_motor_t *_dc_motor);
Std_returnType dc_motor_clockwise(const dc_motor_t *_dc_motor);
Std_returnType dc_motor_unticlockwise(const dc_motor_t *_dc_motor);
Std_returnType dc_motor_stop(const dc_motor_t *_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

