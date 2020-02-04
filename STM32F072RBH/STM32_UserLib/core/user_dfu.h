/****************************************************************************************
 * All Rights Reserved
 * Pico
 ****************************************************************************************
 * @File    user_dfu.h
 *
 * @Author  Solen Liu
 *
 * @Brief   This file provide functions to boot into application
 *
 * @Date    2019/10/31  
 *
 *****************************************************************************************/
#ifndef USER_DFU_H
#define USER_DFU_H
#include "user_config.h"

#define APPLICATION_ADDRESS                  0x8006000

#if (defined STM32F072xB)
#define SYSCFG_MemoryRemap_SRAM              ((uint8_t)0x03)
#define FLASH_BUSY_STATE                     (FLASH->SR & FLASH_SR_BSY)// 1 BUSY 0 NOT BUSY

static void Memory_Remap(uint32_t SYSCFG_MemoryRemap);
void IAP_Set(void);
#endif

void BootApp(void);
#endif
