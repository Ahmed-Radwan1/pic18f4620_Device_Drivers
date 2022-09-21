/* 
 * File:   application.c
 * Author: ahmed radwan
 *
 * Created on June 28, 2022, 5:22 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*include section*/

#include"MCAL/std_libraries.h"
#include"ECU/ecu_layer_init.h"
#include"MCAL/INTERRUPT/mcal_external_interrupt.h"
/*macros declarations section*/



/*data types  section*/
extern char_lcd_4bit_t lcd1;
extern char_lcd_8bit_t lcd2;

/*function declarations section*/
void application_intialize(void);
#endif	/* APPLICATION_H */

