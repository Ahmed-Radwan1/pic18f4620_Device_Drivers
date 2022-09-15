/* 
 * File:   ecu_dc_motor.c
 * Author: ahmed radwan
 *
 * Created on July 21, 2022, 12:28 AM
 */
#include"ecu_dc_motor.h"

Std_returnType dc_motor_initialize(const dc_motor_t *_dc_motor)
{
   Std_returnType ERRORSTATUS =E_OK;
   if(NULL==_dc_motor)
   {
       ERRORSTATUS =E_NOK;
   }
   else
   {
      ERRORSTATUS= gpio_pin_initialize(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN1]));
      ERRORSTATUS= gpio_pin_initialize(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN2]));

   }
   return ERRORSTATUS;
}
Std_returnType dc_motor_clockwise(const dc_motor_t *_dc_motor)
{
   Std_returnType ERRORSTATUS =E_OK;
   if(NULL==_dc_motor)
   {
       ERRORSTATUS =E_NOK;
   }
   else
   {
      ERRORSTATUS=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN1]), GPIO_HIGH);
      ERRORSTATUS=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN2]), GPIO_LOW);

   }
   return ERRORSTATUS;
}
Std_returnType dc_motor_unticlockwise(const dc_motor_t *_dc_motor)
{
      Std_returnType ERRORSTATUS =E_OK;
   if(NULL==_dc_motor)
   {
       ERRORSTATUS =E_NOK;
   }
   else
   {
      ERRORSTATUS=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN2]), GPIO_HIGH);
      ERRORSTATUS=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN1]), GPIO_LOW);

   }
   return ERRORSTATUS; 
}
Std_returnType dc_motor_stop(const dc_motor_t *_dc_motor)
{
      Std_returnType ERRORSTATUS =E_OK;
   if(NULL==_dc_motor)
   {
       ERRORSTATUS =E_NOK;
   }
   else
   {
      ERRORSTATUS=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN2]), GPIO_LOW);
      ERRORSTATUS=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN1]), GPIO_LOW);

   }
   return ERRORSTATUS;     
}