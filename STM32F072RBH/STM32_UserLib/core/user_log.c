/****************************************************************************************
 * All Rights Reserved
 * STM32 UserLib
 ****************************************************************************************
 * @File    user_log.c
 *
 * @Author  Solen Liu
 *
 * @Brief   usart print log
 *
 * @Date    2020/01/02  
 *
 *****************************************************************************************/
 #include "user_log.h"
 #include "stdarg.h"          
 #include "stdio.h"          
 #include "string.h"    
 static uint8_t USART_TX_BUF[LOG_BUFFER_SIZE];

/**
  * @brief  print logs from UART-TX
  * @param  parameters same to printf  "<format>", <data>
  */
 void pr_msg(char* fmt,...)
 {
    uint8_t ENTER[]="\r\n";
    va_list ap;
    va_start(ap,fmt);
    vsprintf((char*)USART_TX_BUF,fmt,ap);
    va_end(ap);
    HAL_UART_Transmit(&LOG_UART_HANDLE, USART_TX_BUF, strlen((const char*)USART_TX_BUF), 200);
    HAL_UART_Transmit(&LOG_UART_HANDLE, ENTER, sizeof(ENTER), 200);
 }
/**
  * @brief  limited to print USB Logs
  * @param  parameters same to printf  "<format>", <data>
  */
 void usb_dbg_msg(char* fmt,...)
 {
    //if(g_hmd_private.USB_DBG_LEVEL == 0x01)
    {
       va_list ap;
       va_start(ap,fmt);
       vsprintf((char*)USART_TX_BUF,fmt,ap);
       va_end(ap);
       HAL_UART_Transmit(&LOG_UART_HANDLE, USART_TX_BUF, strlen((const char*)USART_TX_BUF), 200);
    }
 }
/**
  * @brief  print logs from UART-TX without "\r\n" ending
  * @param  parameters same to printf  "<format>", <data>
  */
 void pr_write(char* fmt,...)
 {
    va_list ap;
    va_start(ap,fmt);
    vsprintf((char*)USART_TX_BUF,fmt,ap);
    va_end(ap);
    HAL_UART_Transmit(&LOG_UART_HANDLE, USART_TX_BUF, strlen((const char*)USART_TX_BUF), 200);
 }
