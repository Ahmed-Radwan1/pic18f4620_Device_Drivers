/* 
 * File:   ecu_keypad_cnfg.h
 * Author: ahmed radwan
 *
 * Created on July 23, 2022, 2:06 AM
 */

#include"ecu_kaypad.h"
/**
 * 
 * @param _keypad
 * @return 
 */
uint8 keypad_matrix[KEYPAD_ROWS_NO][KEYPAD_COLUMS_NO]={
                        {'7','8','9','/'},
                        {'4','5','6','*'},
                        {'1','2','3','-'},
                        {'#','0','=','+'}
                    };
Std_returnType keypad_initialize(const keypad_t*_keypad)
{
     Std_returnType ERRORSTATUS =E_OK;
     if (NULL==_keypad)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
         uint8 l_counter=ZERO_INIT;
         for(l_counter=ZERO_INIT;l_counter<KEYPAD_ROWS_NO;l_counter++)
         {
         ERRORSTATUS=gpio_pin_initialize(&(_keypad->keypad_rows_pins[l_counter]));
         }
         
          for(l_counter=ZERO_INIT;l_counter<KEYPAD_COLUMS_NO;l_counter++)
         {
         ERRORSTATUS=gpio_pin_initialize(&(_keypad->keypad_colums_pins[l_counter]));
         }    
         
    }
     return ERRORSTATUS;   
}
/**
 * 
 * @param _keypad
 * @param value
 * @return 
 */
Std_returnType keypad_get_value(const keypad_t*_keypad,uint8* value)
{
     Std_returnType ERRORSTATUS =E_OK;
     if ((NULL==_keypad)||(NULL==value))
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
       uint8 l_rows_counter=ZERO_INIT;
       uint8 l_colums_counter=ZERO_INIT;
       uint8 l_counter=ZERO_INIT;
       logic_t l_colum_logic=ZERO_INIT;
       for(l_rows_counter=ZERO_INIT;l_rows_counter<KEYPAD_ROWS_NO;l_rows_counter++)
       {
            for(l_counter=ZERO_INIT;l_counter<KEYPAD_ROWS_NO;l_counter++)
            {
                gpio_pin_write_logic(&(_keypad->keypad_rows_pins[l_counter]),GPIO_LOW);// to be sure all rows is low
            }
           gpio_pin_write_logic(&(_keypad->keypad_rows_pins[l_rows_counter]),GPIO_HIGH);//set only row high
           for(l_colums_counter=ZERO_INIT;l_colums_counter<KEYPAD_COLUMS_NO;l_colums_counter++) 
           {
              gpio_pin_read_logic(&(_keypad->keypad_colums_pins[l_colums_counter]),&l_colum_logic);// searching which colum
              if(l_colum_logic==1)
              {
                *value=keypad_matrix[l_rows_counter][l_colums_counter];
              }
            
           }
       }    
    }
     return ERRORSTATUS; 
}
