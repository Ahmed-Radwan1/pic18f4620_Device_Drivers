/* 
 * File:   ecu_seven_segment.h
 * Author: ahmed radwan
 *
 * Created on July 22, 2022, 4:54 AM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H



/*include section*/
#include"../../MCAL/GPIO/hal_gpio.h"
#include"ecu_seven_segment_cnfg.h"
/*macros declarations section*/


/*data types  section*/

typedef enum {
    COMMON_ANODE=0,
    COMMON_CATHOD       
}seven_segment_type_t;


typedef enum {
    SEVEN_SEGMENT_PIN0=0,
    SEVEN_SEGMENT_PIN1,
    SEVEN_SEGMENT_PIN2,
    SEVEN_SEGMENT_PIN3
            
}seven_segment_pins;


typedef struct {
pin_config_t seven_segment_Pins[4];
seven_segment_type_t seven_segment_type;
}seven_segment_t;           



/*function declarations section*/

Std_returnType seven_segment_initialize(const seven_segment_t *segment);
Std_returnType seven_segment_write_number(const seven_segment_t *segment,uint8 number);



#endif	/* ECU_SEVEN_SEGMENT_H */

