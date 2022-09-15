/* 
 * File:   mcal_eeprom.c
 * Author: ahmed radwan
 *
 * Created on August 16, 2022, 9:37 PM
 */
#include"mcal_eeprom.h"
Std_returnType Data_EEPROM_Write_Byte ( const uint16 address,uint8 data)
{
   Std_returnType ERRORSTATUS =E_OK;
   
        uint8 global_int_stat;
        /*read the status of the interrupt*/
        global_int_stat=INTCONbits.GIE;
        /*write the address to EEADRH & EEADR*/
        EEADRH=(uint8)((address>>8)&0x03);
        EEADR=(uint8)(address&0xff);
        /*write the data to EEDATA REG*/
        EEDATA=data;
        /*clear EEPGD bit in EECON1 to access data memory*/
        EECON1bits.EEPGD=ACCESS_DATA_EEPROM_MEMORY;
        /*clear CFGS bit in EECON1 to access EEPROM*/
        EECON1bits.CFGS=ACCESS_FLASH_PROGRAM_OR_DATA_EEPROM_memory;
        /*set WREN bit in EECON1 to enable write operation*/
        EECON1bits.WREN=ALLOWS_WRITE_CYCLES_TO_FLASH_EEPROM;
        /*disable the interrupt*/
        INTCONbits.GIE=0;
        /*write 0x55h toEECON2*/
        EECON2=0x55;
        /*write 0xAAH toEECON2*/
        EECON2=0xAA;
        /*set WR bit in EECON1 to begin write operation*/
        EECON1bits.WR=Initiates_DATA_EEPROM_ERASE_WRITE_CYCLES;
        /*wait until write done*/
        while(EECON1bits.WR){}
        /*clear WREN bit in EECON1 to disable write operation*/
         EECON1bits.WREN=INHIBITS_WRITE_CYCLES_TO_FLASH_EEPROM;
        /*return the interrupt to the previous state*/
        INTCONbits.GIE=global_int_stat;
    return ERRORSTATUS;
}

Std_returnType Data_EEPROM_Read_Byte  ( const uint16 address,uint8* data)
{
   Std_returnType ERRORSTATUS =E_OK;
    /*write the address to EEADRH & EEADR*/
    EEADRH=(uint8)((address>>8)&0x03);
    EEADR=(uint8)(address&0xff);
   /*clear EEPGD bit in EECON1 to access data memory*/
    EECON1bits.EEPGD=ACCESS_DATA_EEPROM_MEMORY;
    /*clear CFGS bit in EECON1 to access EEPROM*/
    EECON1bits.CFGS=ACCESS_FLASH_PROGRAM_OR_DATA_EEPROM_memory;
    /*Initiates an EEPROM read cycle*/
    EECON1bits.RD=Initiates_DATA_EEPROM_READ_CYCLE;
    /*wait two instructions*/
    NOP();
    NOP();
    /*get the data*/
    *data=EEDATA;
    return ERRORSTATUS;
}