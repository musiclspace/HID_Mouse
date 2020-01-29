/* **************************************************************************************
 * All Rights Reserved
 * STM32 UserLib
 * **************************************************************************************
 * Name : user_define.h
 *
 * Description : Common Define Types
 *
 * Author : Solen Liu  
 *
 * Date : 2019/04/22
 *
 * ************************************************************************************** */
 #ifndef USER_DEFINE_H
 #define USER_DEFINE_H
 #if (defined STM32F401xC)
 #include "stm32f4xx_hal.h"
 #elif ((defined STM32F103xE) || (defined STM32F103xC)) 
 #include "stm32f1xx_hal.h"
 #elif (defined STM32F072xB)
 #include "stm32f0xx_hal.h"
 #endif
 
  
 
 #endif
