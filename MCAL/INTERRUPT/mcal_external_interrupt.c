/* 
 * File:   mcal_external_interrupt.c
 * Author: ahmed radwan
 *
 * Created on August 5, 2022, 8:10 PM
 */
#include"mcal_external_interrupt.h"

static void (*INT0_Interrupt_Handler)(void)=NULL;
static void (*INT1_Interrupt_Handler)(void)=NULL;
static void (*INT2_Interrupt_Handler)(void)=NULL;

static void (*RB4_Interrupt_Handler_Low)(void)=NULL;
static void (*RB4_Interrupt_Handler_High)(void)=NULL;
static void (*RB5_Interrupt_Handler_Low)(void)=NULL;
static void (*RB5_Interrupt_Handler_High)(void)=NULL;
static void (*RB6_Interrupt_Handler_Low)(void)=NULL;
static void (*RB6_Interrupt_Handler_High)(void)=NULL;
static void (*RB7_Interrupt_Handler_Low)(void)=NULL;
static void (*RB7_Interrupt_Handler_High)(void)=NULL;


static Std_returnType INT0_Set_Interrupt_Handler(void (*INT_Interrupt_Handler)(void));
static Std_returnType INT1_Set_Interrupt_Handler(void (*INT_Interrupt_Handler)(void));
static Std_returnType INT2_Set_Interrupt_Handler(void (*INT_Interrupt_Handler)(void));
static Std_returnType interrupt_INTx_Set_Interrupt_Handler(const interrupt_INTx_t* int_obj);

static Std_returnType interrupt_INTx_enable (const interrupt_INTx_t*int_obj);
static Std_returnType interrupt_INTx_disable (const interrupt_INTx_t*int_obj);
static Std_returnType interrupt_INTx_clear_flag (const interrupt_INTx_t* int_obj);
static Std_returnType interrupt_INTx_priority_int (const interrupt_INTx_t* int_obj);
static Std_returnType interrupt_INTx_ege_int (const interrupt_INTx_t* int_obj);
static Std_returnType interrupt_INTx_pin_int (const interrupt_INTx_t* int_obj);





static Std_returnType interrupt_RBx_enable (const interrupt_RBx_t* int_obj);
static Std_returnType interrupt_RBx_disable (const interrupt_RBx_t* int_obj);
static Std_returnType interrupt_RBx_priority_int (const interrupt_RBx_t* int_obj);
static Std_returnType interrupt_RBx_pin_int (const interrupt_RBx_t* int_obj);
static Std_returnType interrupt_RBx_Set_Interrupt_Handler(const interrupt_RBx_t* int_obj);

/****************************************------------- INTX section--------------*******************************************/
/**
 * 
 * @param int_obj
 * @return 
 */
Std_returnType interrupt_INTx_init ( const interrupt_INTx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
      
        /*disable the external interrupt*/
        ERRORSTATUS=interrupt_INTx_disable(int_obj);
        /*clear interrupt flag*/
        ERRORSTATUS=interrupt_INTx_clear_flag(int_obj);
        /*configure external interrupt edge*/
        ERRORSTATUS=interrupt_INTx_ege_int(int_obj);
#if Interrupt_priority_Levels_Enable ==Interrupt_FEATURE_ENABLE
         /*configure external interrupt priority*/
        ERRORSTATUS=interrupt_INTx_priority_int(int_obj);
#endif
         /*configure external interrupt I/O pin*/
        ERRORSTATUS=interrupt_INTx_pin_int(int_obj);
        /*set the external interrupt call back function*/
        ERRORSTATUS=interrupt_INTx_Set_Interrupt_Handler(int_obj);
         /*enable the external interrupt*/
        ERRORSTATUS=interrupt_INTx_enable(int_obj);
    }
     
     return ERRORSTATUS;
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_returnType interrupt_INTx_deinit ( const interrupt_INTx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
     if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        interrupt_INTx_disable(int_obj);
    }
     
     return ERRORSTATUS;    
}

/****************************************-------------helper for INTX--------------*******************************************/
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_returnType interrupt_INTx_enable (const interrupt_INTx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
    #if Interrupt_priority_Levels_Enable ==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
    #else
        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
    #endif
         switch(int_obj->INTsource)
        {        
            case interrupt_external_INT0:
                EXI_INT0_Interrupt_Enable();
                 ERRORSTATUS=E_OK;
                break;
            case interrupt_external_INT1:
                EXI_INT1_Interrupt_Enable();
                 ERRORSTATUS=E_OK;
                break;  
            case interrupt_external_INT2:
                EXI_INT2_Interrupt_Enable();
                ERRORSTATUS=E_OK;
                break;
            default:
                ERRORSTATUS=E_NOK;
                    
        }   
    }
     
     return ERRORSTATUS;    
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_returnType interrupt_INTx_disable(const interrupt_INTx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
         switch(int_obj->INTsource)
        {        
            case interrupt_external_INT0:
                EXI_INT0_Interrupt_Disable();
                 ERRORSTATUS=E_OK;
                break;
            case interrupt_external_INT1:
                EXI_INT1_Interrupt_Disable();
                 ERRORSTATUS=E_OK;
                break;  
            case interrupt_external_INT2:
                EXI_INT2_Interrupt_Disable();
                ERRORSTATUS=E_OK;
                break;
            default:
                ERRORSTATUS=E_NOK;
                    
        }   
    }
     
     return ERRORSTATUS;    
}
/**
 * 
 * @param int_obj
 * @return 
 */
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
static Std_returnType interrupt_INTx_priority_int (const interrupt_INTx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
                switch(int_obj->INTsource)
        {        
                    // INT0 always high priority
            case interrupt_external_INT1:
                if(INTERRUPT_HIGH_priority==int_obj->priority)
                {
                    EXI_INT1_High_priority_set();
                }
                else if(INTERRUPT_LOW_priority==int_obj->priority)
                {
                    EXI_INT1_Low_priority_set();
                }
                 ERRORSTATUS=E_OK;
                break;  
            case interrupt_external_INT2:
                if(INTERRUPT_HIGH_priority==int_obj->priority)
                {
                    EXI_INT2_High_priority_set();
                }
                else if(INTERRUPT_LOW_priority==int_obj->priority)
                {
                    EXI_INT2_Low_priority_set();
                }
                 ERRORSTATUS=E_OK;
                break;
            default:
                ERRORSTATUS=E_NOK;
                    
        }  
    }
     
     return ERRORSTATUS;    
}
#endif
static Std_returnType interrupt_INTx_ege_int (const interrupt_INTx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
          if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        switch(int_obj->INTsource)
        {        
            case interrupt_external_INT0:
                if(INTERRUPT_RISING_EDGE==int_obj->ege)
                {
                    EXI_INT0_Rising_Edge_set();
                }
                else if(INTERRUPT_FALING_EDGE==int_obj->ege)
                {
                    EXI_INT0_Faling_Edge_set();
                }
                 ERRORSTATUS=E_OK;
                break;
            case interrupt_external_INT1:
                if(INTERRUPT_RISING_EDGE==int_obj->ege)
                {
                    EXI_INT1_Rising_Edge_set();
                }
                else if(INTERRUPT_FALING_EDGE==int_obj->ege)
                {
                    EXI_INT1_Faling_Edge_set();
                }
                 ERRORSTATUS=E_OK;
                break;  
            case interrupt_external_INT2:
                if(INTERRUPT_RISING_EDGE==int_obj->ege)
                {
                    EXI_INT2_Rising_Edge_set();
                }
                else if(INTERRUPT_FALING_EDGE==int_obj->ege)
                {
                    EXI_INT2_Faling_Edge_set();
                }
                ERRORSTATUS=E_OK;
                break;
            default:
                ERRORSTATUS=E_NOK;
                    
        }
    }
     
     return ERRORSTATUS;    
}
static Std_returnType interrupt_INTx_pin_int (const interrupt_INTx_t* int_obj)
{
     Std_returnType ERRORSTATUS =E_OK;
          if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
              gpio_pin_direction_initialize(&(int_obj->pin));
    }
     
     return ERRORSTATUS;   
}

static Std_returnType interrupt_INTx_clear_flag (const interrupt_INTx_t* int_obj)
{
     Std_returnType ERRORSTATUS =E_OK;
          if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        switch(int_obj->INTsource)
        {        
            case interrupt_external_INT0:
                EXI_INT0_Interrupt_Flag_clear();
                 ERRORSTATUS=E_OK;
                break;
            case interrupt_external_INT1:
                EXI_INT1_Interrupt_Flag_clear();
                 ERRORSTATUS=E_OK;
                break;  
            case interrupt_external_INT2:
               EXI_INT2_Interrupt_Flag_clear();
                ERRORSTATUS=E_OK;
                break;
            default:
                ERRORSTATUS=E_NOK;
                    
        }
    }
     
     return ERRORSTATUS;   
}

/*********************************callback section for INTX*********************************************/
/**
 * 
 * @param INT_Interrupt_Handler
 * @return 
 */
static Std_returnType INT0_Set_Interrupt_Handler(void (*Interrupt_Handler)(void))
{
     Std_returnType ERRORSTATUS =E_OK;
      if (Interrupt_Handler==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        INT0_Interrupt_Handler=Interrupt_Handler;
        ERRORSTATUS=E_OK;
    }
     return ERRORSTATUS;
}
/**
 * 
 * @param INT_Interrupt_Handler
 * @return 
 */
static Std_returnType INT1_Set_Interrupt_Handler(void (*Interrupt_Handler)(void))
{
     Std_returnType ERRORSTATUS =E_OK;
      if (Interrupt_Handler==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        INT1_Interrupt_Handler=Interrupt_Handler;
        ERRORSTATUS=E_OK;
    }
     return ERRORSTATUS;    
}
/**
 * 
 * @param INT_Interrupt_Handler
 * @return 
 */
static Std_returnType INT2_Set_Interrupt_Handler(void (*Interrupt_Handler)(void))
{
     Std_returnType ERRORSTATUS =E_OK;
      if (Interrupt_Handler==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        INT2_Interrupt_Handler=Interrupt_Handler;
        ERRORSTATUS=E_OK;
    }
     return ERRORSTATUS;    
}

static Std_returnType interrupt_INTx_Set_Interrupt_Handler(const interrupt_INTx_t* int_obj)
{
     Std_returnType ERRORSTATUS =E_OK;
      if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        switch(int_obj->INTsource)
        {        
            case interrupt_external_INT0:
               ERRORSTATUS=INT0_Set_Interrupt_Handler(int_obj->EXT_Interrupt_handeler);
                break;
            case interrupt_external_INT1:
                ERRORSTATUS=INT1_Set_Interrupt_Handler(int_obj->EXT_Interrupt_handeler);
                break;  
            case interrupt_external_INT2:
               ERRORSTATUS=INT2_Set_Interrupt_Handler(int_obj->EXT_Interrupt_handeler);
                break;
            default:
                ERRORSTATUS=E_NOK;
                    
        }
    }
     
     return ERRORSTATUS; 
}
/*********************************end of callback section for INTX*********************************************/
/****************************************-------------INTx->ISR--------------*******************************************/

void INT0_ISR(void)
{
    EXI_INT0_Interrupt_Flag_clear();
    if(INT0_Interrupt_Handler){INT0_Interrupt_Handler();}
    
}
void INT1_ISR(void)
{
    EXI_INT1_Interrupt_Flag_clear();
    if(INT1_Interrupt_Handler){INT1_Interrupt_Handler();}
    
}

void INT2_ISR(void)
{
    EXI_INT2_Interrupt_Flag_clear();
    if(INT2_Interrupt_Handler){INT2_Interrupt_Handler();}
    
}
/****************************************-------------end of INTx->ISR--------------*******************************************/
/****************************************-------------end of helper function for INTX--------------*******************************************/
/****************************************-------------End INTX section--------------*******************************************/


/****************************************------------- RBX section--------------*******************************************/
/**
 * 
 * @param int_obj
 * @return 
 */   
Std_returnType interrupt_RBx_init ( const interrupt_RBx_t* int_obj)
{
   Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
         /*disable the external interrupt*/
        ERRORSTATUS=interrupt_RBx_disable(int_obj);
        /*clear interrupt flag for RBx*/
        ERRORSTATUS=EXI_RBx_Interrupt_Flag_clear();
#if Interrupt_priority_Levels_Enable ==Interrupt_FEATURE_ENABLE
         /*configure external interrupt priority*/
        ERRORSTATUS=interrupt_RBx_priority_int(int_obj);
#endif
        /*configure external interrupt I/O pin*/
        ERRORSTATUS=interrupt_RBx_pin_int(int_obj);
        /*set the external interrupt call back function*/
        ERRORSTATUS=interrupt_RBx_Set_Interrupt_Handler(int_obj);
         /*enable the external interrupt*/
        ERRORSTATUS=interrupt_RBx_enable(int_obj);
    }
     
     return ERRORSTATUS;
}    

/**
 * 
 * @param int_obj
 * @return 
 */
Std_returnType interrupt_RBx_deinit ( const interrupt_RBx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
    ERRORSTATUS=interrupt_RBx_disable(int_obj);
    
    }
     
     return ERRORSTATUS;    
}

/****************************************-------------End of RBX section--------------*******************************************/


/****************************************-------------start of helper function for RBX--------------*******************************************/

static Std_returnType interrupt_RBx_enable (const interrupt_RBx_t* int_obj)
{
     Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
    #if Interrupt_priority_Levels_Enable ==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
    #else
        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
    #endif
         EXI_RBx_Interrupt_Enable();
    }
     return ERRORSTATUS;    
}
  
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_returnType interrupt_RBx_disable (const interrupt_RBx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
     EXI_RBx_Interrupt_Flag_clear();
     EXI_RBx_Interrupt_Disable();
    }
     
     return ERRORSTATUS;
     
}
/**
 * 
 * @param int_obj
 * @return 
 */
#if Interrupt_priority_Levels_Enable ==Interrupt_FEATURE_ENABLE
static Std_returnType interrupt_RBx_priority_int (const interrupt_RBx_t* int_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
          if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        switch(int_obj->priority)
        {
            case INTERRUPT_HIGH_priority:
                EXI_RBx_High_priority_set();
                break;
            case INTERRUPT_LOW_priority:
                EXI_RBx_Low_priority_set();
                break; 
            default:
              ERRORSTATUS= E_NOK; 
        }
    }
     
     return ERRORSTATUS;
}
#endif
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_returnType interrupt_RBx_pin_int (const interrupt_RBx_t* int_obj)
{
 Std_returnType ERRORSTATUS =E_OK;
    if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
       gpio_pin_direction_initialize(&(int_obj->pin));
    }
     
     return ERRORSTATUS; 
}
static Std_returnType interrupt_RBx_Set_Interrupt_Handler(const interrupt_RBx_t* int_obj)
{
         Std_returnType ERRORSTATUS =E_OK;
      if (int_obj==NULL)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        switch(int_obj->pin.pin)
        {        
            case GPIO_PIN4:
               ERRORSTATUS=RB4_Interrupt_Handler_Low=int_obj->EXT_Interrupt_Handeler_Low;
               ERRORSTATUS=RB4_Interrupt_Handler_High=int_obj->EXT_Interrupt_Handeler_High;
                break;
            case GPIO_PIN5:
               ERRORSTATUS=RB5_Interrupt_Handler_Low=int_obj->EXT_Interrupt_Handeler_Low;
               ERRORSTATUS=RB5_Interrupt_Handler_High=int_obj->EXT_Interrupt_Handeler_High;
                break;
            case GPIO_PIN6:
               ERRORSTATUS=RB6_Interrupt_Handler_Low=int_obj->EXT_Interrupt_Handeler_Low;
               ERRORSTATUS=RB6_Interrupt_Handler_High=int_obj->EXT_Interrupt_Handeler_High;
                break;
            case GPIO_PIN7:
               ERRORSTATUS=RB7_Interrupt_Handler_Low=int_obj->EXT_Interrupt_Handeler_Low;
               ERRORSTATUS=RB7_Interrupt_Handler_High=int_obj->EXT_Interrupt_Handeler_High;
                break;
            default:
                ERRORSTATUS=E_NOK;
                    
        }
    }
}
/****************************************-------------end of helper function for RBX--------------*******************************************/

/****************************************-------------start of ISR->RBX--------------*******************************************/
void RB4_ISR(uint8 RB4_source)
{
    EXI_RBx_Interrupt_Flag_clear();
    if(1==RB4_source)
    {
        if(RB4_Interrupt_Handler_High){RB4_Interrupt_Handler_High();}
    }
    else if(0==RB4_source)
    {
       if(RB4_Interrupt_Handler_Low){RB4_Interrupt_Handler_Low();}

    }
    else{/*nothing*/}
}
void RB5_ISR(uint8 RB5_source)
{
    EXI_RBx_Interrupt_Flag_clear();
     if(1==RB5_source)
    {
        if(RB5_Interrupt_Handler_High){RB5_Interrupt_Handler_High();}
    }
    else if(0==RB5_source)
    {
       if(RB5_Interrupt_Handler_Low){RB5_Interrupt_Handler_Low();}

    }
    else{/*nothing*/}   
}
void RB6_ISR(uint8 RB6_source)
{
    EXI_RBx_Interrupt_Flag_clear();
    if(1==RB6_source)
    {
        if(RB6_Interrupt_Handler_High){RB6_Interrupt_Handler_High();}
    }
    else if(0==RB6_source)
    {
       if(RB6_Interrupt_Handler_Low){RB6_Interrupt_Handler_Low();}

    }
    else{/*nothing*/}   
}
void RB7_ISR(uint8 RB7_source)
{
    EXI_RBx_Interrupt_Flag_clear();
    if(1==RB7_source)
    {
        if(RB7_Interrupt_Handler_High){RB7_Interrupt_Handler_High();}
    }
    else if(0==RB7_source)
    {
       if(RB7_Interrupt_Handler_Low){RB7_Interrupt_Handler_Low();}

    }
    else{/*nothing*/}    
}

/****************************************-------------end of ISR->RBX--------------*******************************************/


