 /*
 * File:   application.h
 * Author: ahmed radwan
 *
 * Created on June 28, 2022, 5:22 AM
 */
//#include "../proc/pic18f4620.h"
#include "application.h"
#include "MCAL/I2C/mcal_i2c.h"
#include"ECU/SERVO_MOTOR_I2C/ecu_servo_motor_i2c.h"
void mssp_i2c_send_1_byte(uint8 slave_adrres,uint8 reg_aderres,uint8 data);


volatile uint32 master_counter=0;
int i=0;
volatile uint8 ack=6;
volatile uint8 slave_address;
void mssp_I2c_DefaultInterruptHandler(void);

mssp_i2c_t i2c_obj={
  .i2c_cfg.i2c_mode=  I2C_MSSP_MASTER_MODE,
  .i2c_cfg.i2c_mode_cfg=I2C_MASTER_MODE_DEFINED_CLOCK,
  .i2c_clock=100000,
  .i2c_cfg.i2c_SMBus_control=I2C_SMBus_DISABLE,
  .i2c_cfg.i2c_slew_rate=I2C_SLEW_RATE_DISABLE,
  .I2C_DefaultInterruptHandler=NULL,
  .I2C_Report_Receive_Overflow=NULL,
  .I2C_Report_Write_Collision=NULL
};

typedef union{
        
    struct {
        uint8_t read_write_bit : 1 ;
        uint8_t address : 6 ;
        uint8_t last_bit : 1 ;
    };
    uint8_t full_byte ;
}i2c_send_addr_t;

servo_driver_st s1_obj={
   .slave_address=SERVO_DRIVER_SLAVE_ADDRESS,
   .frequancy=ECU_SM_PRE_SCALE_REG_VAL,
   .mode_1_cfg=0x21,
   .mode_2_cfg=0x04   
};
#define delay 1000
uint8 angle=0;
uint8 storedata=0;
int main()
{
    application_intialize();

    for(int i=0;i<16;i++)
    {
        Servo_SetAngle(&i2c_obj,&s1_obj,i,angle);
        __delay_ms(delay);
        angle+=15;
    }
     while(1)
     {

//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,15);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,30);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,45);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,60);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,75);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,90);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,105);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,120);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,135);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,150);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,165);__delay_ms(delay);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_1,180);__delay_ms(delay);

        //        __delay_ms(250);
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_5,60);
//        __delay_ms(250);
//
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_9,90);
//        __delay_ms(250);
//
//        Servo_SetAngle(&i2c_obj,&s1_obj,servo_index_16,180);
//        __delay_ms(250);
     }    
    return 0;

}
void application_intialize(void)
{
    MSSP_I2C_Init(&i2c_obj);
    ServoDriver_Init(&i2c_obj,&s1_obj);
}


void mssp_I2c_DefaultInterruptHandler(void){
   master_counter++;

}
void mssp_i2c_send_1_byte(uint8 slave_adrres,uint8 reg_aderres,uint8 data)
{
    //start 
    MSSP_I2C_Master_Send_Start(&i2c_obj);
    //slave address 
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,slave_adrres,&ack);
    //control REG address
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,reg_aderres,&ack);
    //data
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,data,&ack);
    //stop
    MSSP_I2C_Master_Send_Stop(&i2c_obj);
}