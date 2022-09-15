/* 
 * File:   mcal_usart.c
 * Author: ahmed radwan
 *
 * Created on September 7, 2022, 1:34 PM
 */
#include"mcal_usart.h"
static void  EUSART_Baud_Rate_Calculation(const usart_t *_eusart);
static void  EUSART_ASYNC_TX_Init(const usart_t *_eusart);
static void  EUSART_ASYNC_RX_Init(const usart_t *_eusart);
#if  EUSART_TX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
static void(*EUSART_TX_Interrupt_Handler)(void);
#endif
#if  EUSART_RX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
static void(*EUSART_RX_Interrupt_Handler)(void);
static void(*EUSART_RX__Framing_Interrupt_Handler)(void);
static void(*EUSART_RX__Overrun_Interrupt_Handler)(void);
#endif


/**
 * initialize EUSART module 
 * @param _eusart
 * @return 
 */
Std_returnType EUSART_ASYNC_Init(const usart_t *_eusart)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_eusart)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
      RCSTAbits.SPEN=EUSART_MODULE_DISABLE;
      EUSART_Baud_Rate_Calculation(_eusart);
      RCSTAbits.SPEN=EUSART_MODULE_ENABLE;
      TRISCbits.TRISC7=1;
      TRISCbits.TRISC6=1;
      EUSART_ASYNC_TX_Init(_eusart);
      EUSART_ASYNC_RX_Init(_eusart);
      TXSTA1bits.TXEN=1;
      RCSTAbits.CREN=1;
         
    }
    return ERRORSTATUS;
    
}
/**
 * deinitialize EUSART module 
 * @param _eusart
 * @return 
 */
Std_returnType EUSART_ASYNC_DeInit(const usart_t *_eusart)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_eusart)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        RCSTAbits.SPEN=EUSART_MODULE_DISABLE;
    }
    return ERRORSTATUS;    
}
/**
 * transmit Byte in Blocking mode
 * @param _data
 * @return 
 */
Std_returnType EUSART_ASYNC_WriteByteBlocking(uint8 _data)
{
    Std_returnType ERRORSTATUS =E_OK;
    while(!TXSTA1bits.TRMT){}
#if  EUSART_TX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
     EUSART_TX_Interrupt_Enable();
#endif
    TXREG= _data; 
    return ERRORSTATUS;    

       
}
/**
 * transmit string in Blocking mode
 * @param _data: pointer to the string
 * @param str_len: the length of the string will be transmited 
 * @return 
 */

Std_returnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data, uint16 str_len)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_data)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
    for(uint16 string_count=0;string_count<str_len;string_count++)
    {
        EUSART_ASYNC_WriteByteBlocking(_data[string_count]);
    }
    }
        return ERRORSTATUS;
}

Std_returnType EUSART_ASYNC_WriteByteNonBlocking(uint8 _data)
{
    Std_returnType ERRORSTATUS =E_OK;
    if(TXSTA1bits.TRMT){}
#if  EUSART_TX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
    EUSART_TX_Interrupt_Enable();
#endif
    TXREG= _data; 
    return ERRORSTATUS;   
}
Std_returnType EUSART_ASYNC_WriteStringNonBlocking(uint8 *_data, uint16 str_len)
{
     Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_data)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
    for(uint16 string_count=0;string_count<str_len;string_count++)
    {
        EUSART_ASYNC_WriteByteNonBlocking(_data[string_count]);
    }
    }
        return ERRORSTATUS; 
}
/**
 * read byte in Blocking mode
 * @param _data :pointer to the location will receive the byte
 * @return 
 */
Std_returnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_data)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
      while(!PIR1bits.RCIF){}
      *_data=RCREG;
    }
    return ERRORSTATUS;    
}
/**
 * read byte in non Blocking mode
 * @param _data :pointer to the location will receive the byte
 * @return 
 */
Std_returnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==_data)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
       if(1==PIR1bits.RCIF)
       {
         *_data=RCREG;  
       }
       else
       {
         ERRORSTATUS =E_NOK;
       }
    }
    return ERRORSTATUS;  
}
Std_returnType EUSART_ASYNC_RX_Restart(void)
{
    RCSTAbits.CREN=0;
    RCSTAbits.CREN=1;

}

/**
 *  configure the mode of baud rate generator and configure the value which will store in SPBRG & SPBRGH
 * @param _eusart
 */
static void  EUSART_Baud_Rate_Calculation(const usart_t *_eusart)
{
    float32 Baudrate_temp=0;
    switch(_eusart->baudrate_gen_gonfig)
    {
       
        case BAUDRATE_ASYN_8BIT_lOW_SPEED:
            TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH=EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16=EUSART_08BIT_BAUDRATE_GEN;
            Baudrate_temp= ((_XTAL_FREQ/(float32)_eusart->baudrate)/64)-1;
            break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16=EUSART_08BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH=EUSART_ASYNCHRONOUS_HIGH_SPEED;
            Baudrate_temp= ((_XTAL_FREQ/(float32)_eusart->baudrate)/16)-1;
            break;
        case BAUDRATE_ASYN_16BIT_lOW_SPEED:
            TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16=EUSART_16BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH=EUSART_ASYNCHRONOUS_LOW_SPEED;
            Baudrate_temp= ((_XTAL_FREQ/(float32)_eusart->baudrate)/16)-1;
            break;          
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16=EUSART_16BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH=EUSART_ASYNCHRONOUS_HIGH_SPEED;
            Baudrate_temp= ((_XTAL_FREQ/(float32)_eusart->baudrate)/4)-1;
            break;
        case BAUDRATE_SYN_8BIT:
            TXSTAbits.SYNC=EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16=EUSART_08BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH=EUSART_ASYNCHRONOUS_LOW_SPEED;            
            Baudrate_temp= ((_XTAL_FREQ/(float32)_eusart->baudrate)/4)-1;
            break; 
        case BAUDRATE_SYN_16BIT:
            TXSTAbits.SYNC=EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16=EUSART_16BIT_BAUDRATE_GEN;
            TXSTAbits.BRGH=EUSART_ASYNCHRONOUS_HIGH_SPEED;
            Baudrate_temp= ((_XTAL_FREQ/(float32)_eusart->baudrate)/4)-1;            
            break; 
        default: 
            break;
    }
    SPBRG=(uint8)((uint32)Baudrate_temp);
    SPBRGH=(uint8)(((uint32)Baudrate_temp)>>8);
}
static void  EUSART_ASYNC_TX_Init(const usart_t *_eusart)
{
    if(EUSART_ASYNCHRONOUS_TX_ENABLE==_eusart->usart_tx_cfg.usart_tx_enable)
    {
        
                               /******************9bit set**********************/

      if(_eusart->usart_tx_cfg.usart_tx_9bit_enable==EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE)
      {
          TXSTAbits.TX9=EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE;
      }
      else if(_eusart->usart_tx_cfg.usart_tx_9bit_enable==EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE)
      {
          TXSTAbits.TX9=EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE;         
      }
      else{/*nothing*/}
    }
       
      if(_eusart->usart_tx_cfg.usart_tx_interrupt_enable==EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE)
      {
                 /*interrupt set*/    
#if  EUSART_TX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
       EUSART_TX_Interrupt_Disable();
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
        if(INTERRUPT_HIGH_priority==_eusart->usart_tx_cfg.usart_tx_int_priority)
        {
            EUSART_TX_Interrupt_High_priority_set();
        }
        else if(INTERRUPT_LOW_priority==_eusart->usart_tx_cfg.usart_tx_int_priority)
        {
            EUSART_TX_Interrupt_Low_priority_set();
        }
            else{/*no thing*/}

#else

        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
#endif 
        EUSART_TX_Interrupt_Enable();

        EUSART_TX_Interrupt_Handler=_eusart->EUSART_TxDefaultInterruptHandler;
 
#endif 
          
      }
      else if(_eusart->usart_tx_cfg.usart_tx_interrupt_enable==EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE)
      {
          EUSART_TX_Interrupt_Disable();
      }
      else{/*nothing*/}
      

}
static void  EUSART_ASYNC_RX_Init(const usart_t *_eusart)
{
    if(EUSART_ASYNCHRONOUS_RX_ENABLE==_eusart->usart_rx_cfg.usart_rx_enable)
    {
       
      if(_eusart->usart_rx_cfg.usart_rx_interrupt_enable==EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE)
      {
                 /*interrupt set*/    
#if  EUSART_RX_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
       EUSART_RX_Interrupt_Disable();
#if Interrupt_priority_Levels_Enable==Interrupt_FEATURE_ENABLE
        Interrupt_poriority_Level_Enable();
        Interrupt_Global_Iinterrupt_High_Enable();
        Interrupt_Global_Iinterrupt_Low_Enable();
        if(INTERRUPT_HIGH_priority==_eusart->usart_rx_cfg.usart_rx_int_priority)
        {
            EUSART_RX_Interrupt_High_priority_set();
        }
        else if(INTERRUPT_LOW_priority==_eusart->usart_rx_cfg.usart_rx_int_priority)
        {
            EUSART_RX_Interrupt_Low_priority_set();
        }
            else{/*no thing*/}

#else

        Interrupt_Global_Iinterrupt_Enable();
        Interrupt_Peripheral_Interrupt_Enable();
#endif 
        EUSART_RX_Interrupt_Enable();

        EUSART_RX_Interrupt_Handler=_eusart->EUSART_RxDefaultInterruptHandler;
        EUSART_RX__Framing_Interrupt_Handler=_eusart->EUSART_FramingErrorHandler;
        EUSART_RX__Overrun_Interrupt_Handler=_eusart->EUSART_OverrunErrorHandler;
 
#endif 
          
      }
      else if(_eusart->usart_rx_cfg.usart_rx_interrupt_enable==EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE)
      {
          EUSART_RX_Interrupt_Disable();
      }
      else{/*nothing*/}
                        /******************9bit set**********************/
      if(_eusart->usart_rx_cfg.usart_rx_9bit_enable==EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE)
      {
          RCSTAbits.RX9=EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE;
      }
      else if(_eusart->usart_rx_cfg.usart_rx_9bit_enable==EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE)
      {
          RCSTAbits.RX9=EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE;         
      }
      else{/*nothing*/}
    }    
}
void EUSART_TX_ISR(void)
{
    EUSART_TX_Interrupt_Disable();
    if(EUSART_TX_Interrupt_Handler)
    {
        EUSART_TX_Interrupt_Handler();
    }
    else{/* nothing*/}
}
void EUSART_RX_ISR(void)
{
    if(EUSART_RX_Interrupt_Handler)
    {
        
        EUSART_RX_Interrupt_Handler();
        uint16 temp_read=RCREG;//to clear the interrupt flag
    }
    else{/* nothing*/}    
    if(EUSART_RX__Framing_Interrupt_Handler)
    {
        EUSART_RX__Framing_Interrupt_Handler();
    }
    else{/* nothing*/} 
    if(EUSART_RX__Overrun_Interrupt_Handler)
    {
        EUSART_RX__Overrun_Interrupt_Handler();
    }
    else{/* nothing*/} 
}
