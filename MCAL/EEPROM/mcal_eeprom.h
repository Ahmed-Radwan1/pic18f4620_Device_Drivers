/* 
 * File:   mcal_eeprom.h
 * Author: ahmed radwan
 *
 * Created on August 16, 2022, 9:37 PM
 */

#ifndef MCAL_EEPROM_H
#define	MCAL_EEPROM_H

#/********************************include section********************************/

#include"../INTERRUPT/mcal_internal_interrupt.h"
#include "../mcal_std_types.h"
#include"../std_libraries.h"

/********************************macros declarations section********************************/
/*Flash Program or Data EEPROM Memory Select bit*/
#define  ACCESS_FLASH_PROGRAM_MEMORY 1
#define  ACCESS_DATA_EEPROM_MEMORY    0
/*Flash Program/Data EEPROM or Configuration Select bit*/
#define  ACCESS_CONFIGURATIONS_registers 1
#define  ACCESS_FLASH_PROGRAM_OR_DATA_EEPROM_memory 0
/* Flash Program/Data EEPROM Write Enable bit*/
#define ALLOWS_WRITE_CYCLES_TO_FLASH_EEPROM   1
#define INHIBITS_WRITE_CYCLES_TO_FLASH_EEPROM 0
/*Write Control bit*/
#define Initiates_DATA_EEPROM_ERASE_WRITE_CYCLES 1
#define WRITE_CYCLES_DONE 0
 /*Read Control bit*/
#define Initiates_DATA_EEPROM_READ_CYCLE 1
#define READ_CYCLE_DONE 0

/********************************macros functio n section********************************/


/********************************data types  section********************************/



/*******************************function declarations section*************************************/
Std_returnType Data_EEPROM_Write_Byte ( const uint16 address,uint8 data);
Std_returnType Data_EEPROM_Read_Byte  ( const uint16 address,uint8* data);


#endif	/* MCAL_EEPROM_H */

