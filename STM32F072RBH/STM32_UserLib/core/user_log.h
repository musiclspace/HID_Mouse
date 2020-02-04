/****************************************************************************************
 * All Rights Reserved
 * STM32 UserLib
 ****************************************************************************************
 * @File    user_log.h
 *
 * @Author  Solen Liu
 *
 * @Brief   usart print log
 *
 * @Date    2020/01/02  
 *
 *****************************************************************************************/
#ifndef USER_LOG_H
#define USER_LOG_H
#include "user_config.h"

#define LOG_EN 1
#define LOG_UART_HANDLE huart2
#define LOG_BUFFER_SIZE 100
extern UART_HandleTypeDef LOG_UART_HANDLE;

 
void pr_msg(char* fmt,...);
#if LOG_EN
#define pr_info(format,...)   pr_msg("[INFO] "format"",##__VA_ARGS__)
#else
#define pr_info(format,...)
#endif
#define pr_err(format,...)    pr_msg("[ERROR] FILE: %s, FUNCTION: %s, LINE: %d: "format"", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif
void usb_dbg_msg(char* fmt,...);
void pr_write(char* fmt,...);
