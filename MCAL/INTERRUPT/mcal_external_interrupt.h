/* 
 * File:   mcal_external_interrupt.h
 * Author: ahmed radwan
 *
 * Created on August 5, 2022, 8:10 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H


/********************************include section********************************/

#include"mcal_interrupt_config.h"

/********************************macros declarations section********************************/

#if  External_Interrupt_INTx_Feature_Enable == Interrupt_FEATURE_ENABLE 

/***************************INT0*********************************/

#define EXI_INT0_Interrupt_Disable() (INTCONbits.INT0E=0)// clear the iterrupt enable for the external interrupt INT0
#define EXI_INT0_Interrupt_Enable()  (INTCONbits.INT0E=1)// set the iterrupt enable for the external interrupt INT0

#define EXI_INT0_Interrupt_Flag_clear() (INTCONbits.INT0IF=0)// clear the iterrupt flag for the external interrupt INT0


#define EXI_INT0_Rising_Edge_set()      (INTCON2bits.INTEDG0=1)// set the ege detect of the external interrupt INT0 positive edge
#define EXI_INT0_Faling_Edge_set()      (INTCON2bits.INTEDG0=0)// set the ege detect of the external interrupt INT0 negative edge

/***************************INT1*********************************/

#define EXI_INT1_Interrupt_Disable() (INTCON3bits.INT1E=0)// clear the iterrupt enable for the external interrupt INT1
#define EXI_INT1_Interrupt_Enable()  (INTCON3bits.INT1E=1)// set the iterrupt enable for the external interrupt INT1

#define EXI_INT1_Interrupt_Flag_clear() (INTCON3bits.INT1F=0)// clear the iterrupt flag for the external interrupt INT1


#define EXI_INT1_Rising_Edge_set()      (INTCON2bits.INTEDG1=1)// set the ege detect of the external interrupt INT1 positive edge
#define EXI_INT1_Faling_Edge_set()      (INTCON2bits.INTEDG1=0)// set the ege detect of the external interrupt INT1 negative edge

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define EXI_INT1_High_priority_set() (INTCON3bits.INT1P=1)//set the external interrupt INT1 to be high priority
#define EXI_INT1_Low_priority_set() (INTCON3bits.INT1P=0)//set the external interrupt INT1 to be low priority

#endif

/***************************INT2*********************************/

#define EXI_INT2_Interrupt_Disable() (INTCON3bits.INT2E=0)// clear the iterrupt enable for the external interrupt INT2
#define EXI_INT2_Interrupt_Enable()  (INTCON3bits.INT2E=1)// set the iterrupt enable for the external interrupt INT2

#define EXI_INT2_Interrupt_Flag_clear() (INTCON3bits.INT2F=0)// clear the iterrupt flag for the external interrupt INT2


#define EXI_INT2_Rising_Edge_set()      (INTCON2bits.INTEDG2=1)// set the ege detect of the external interrupt INT2 positive edge
#define EXI_INT2_Faling_Edge_set()      (INTCON2bits.INTEDG2=0)// set the ege detect of the external interrupt INT2 negative edge


#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define EXI_INT2_High_priority_set() (INTCON3bits.INT2P=1)//set the external interrupt INT1 to be high priority
#define EXI_INT2_Low_priority_set() (INTCON3bits.INT2P=0)//set the external interrupt INT1 to be low priority

#endif

#endif



#if External_Interrupt_OnChange_Feature_Enable == Interrupt_FEATURE_ENABLE


#define EXI_RBx_Interrupt_Disable() (INTCONbits.RBIE=0)// clear the iterrupt enable for the external on change interrupt RBx
#define EXI_RBx_Interrupt_Enable()  (INTCONbits.RBIE=1)// set the iterrupt enable for the external on change interrupt RBx

#define EXI_RBx_Interrupt_Flag_clear() (INTCONbits.RBIF=0)// clear the iterrupt flag for the external on change interrupt RBx

#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE

#define EXI_RBx_High_priority_set() (INTCON2bits.RBIP=1)//set the external interrupt RBx to be high priority
#define EXI_RBx_Low_priority_set() (INTCON2bits.RBIP=0)//set the external interrupt RBx to be low priority

#endif

#endif

/********************************data types  section********************************/
typedef enum{
   interrupt_external_INT0=0,
   interrupt_external_INT1,        
   interrupt_external_INT2        
}interrupt_INT_source_t;

typedef enum{
   INTERRUPT_FALING_EDGE=0,
   INTERRUPT_RISING_EDGE
}interrupt_INTx_edge_t;


typedef struct{
    void (*EXT_Interrupt_handeler) (void);
    pin_config_t pin;
    interrupt_INT_source_t INTsource;
    interrupt_INTx_edge_t ege;
    interrupt_priority_cfg priority;
} interrupt_INTx_t;

typedef struct{
    void (*EXT_Interrupt_Handeler_High) (void);
    void (*EXT_Interrupt_Handeler_Low) (void);
    pin_config_t pin;
    interrupt_priority_cfg  priority;
} interrupt_RBx_t;


/*******************************function declarations section*************************************/
Std_returnType interrupt_INTx_init ( const interrupt_INTx_t* int_obj);
Std_returnType interrupt_INTx_deinit ( const interrupt_INTx_t* int_obj);

Std_returnType interrupt_RBx_init ( const interrupt_RBx_t* int_obj);
Std_returnType interrupt_RBx_deinit ( const interrupt_RBx_t* int_obj);




#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

