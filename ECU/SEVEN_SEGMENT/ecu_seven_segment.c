/* 
 * File:   ecu_seven_segment.c
 * Author: ahmed radwan
 *
 * Created on July 22, 2022, 4:54 AM
 */
#include"ecu_seven_segment.h"

/**
 * 
 * @param segment
 * @return 
 */
Std_returnType seven_segment_initialize(const seven_segment_t *segment)
{
     Std_returnType ERRORSTATUS =E_OK;
          if ( NULL==segment)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
         ERRORSTATUS=gpio_pin_initialize(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN0]));
         ERRORSTATUS=gpio_pin_initialize(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN1]));
         ERRORSTATUS=gpio_pin_initialize(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN2]));
         ERRORSTATUS=gpio_pin_initialize(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN3]));   
    }
     return ERRORSTATUS;   
}

/**
 * 
 * @param segment
 * @param number
 * @return 
 */
Std_returnType seven_segment_write_number(const seven_segment_t *segment,uint8 number)
{
        Std_returnType ERRORSTATUS =E_OK;
          if (( NULL==segment)||(9<number))
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        ERRORSTATUS=gpio_pin_write_logic(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN0]), number&0x01);
        ERRORSTATUS=gpio_pin_write_logic(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN1]),(number>>1)&0x01);
        ERRORSTATUS=gpio_pin_write_logic(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN2]),(number>>2)&0x01);
        ERRORSTATUS=gpio_pin_write_logic(&(segment->seven_segment_Pins[SEVEN_SEGMENT_PIN3]),(number>>3)&0x01);  
    }
     return ERRORSTATUS;  
}