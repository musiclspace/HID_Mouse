/****************************************************************************************
 * All Rights Reserved
 * Pico
 ****************************************************************************************
 * @File    user_dfu.c
 *
 * @Author  Solen Liu
 *
 * @Brief   This file provide functions to boot into application 
 *
 * @Date    2020/02/04  
 *
 *****************************************************************************************/
#include "user_dfu.h"
typedef void (*pFunction)(void);
/**
  * @brief  Boot Into Application From Bootloader
  */
void BootApp(void)
{
    pFunction Jump_To_Application;
    uint32_t JumpAddress;    
    if (((*(__IO uint32_t*)APPLICATION_ADDRESS) & 0x2FFE0000 ) == 0x20000000)
    {  
        JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
        Jump_To_Application = (pFunction) JumpAddress;
        __set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
        Jump_To_Application();
    }
}
#if (defined STM32F072xB)
/**
  * @brief  Interrupt Vector Offset in Application
  */
 void IAP_Set(void)
{
    uint32_t i = 0;
    /* Relocate by software the vector table to the internal SRAM at 0x20000000 ***/  
    /* Copy the vector table from the Flash (mapped at the base of the application
       load address 0x08006000) to the base address of the SRAM at 0x20000000.     */       
    for(i = 0; i < 48; i++)
    {
        *((uint32_t*)(0x20000000 + (i << 2)))=*(__IO uint32_t*)(APPLICATION_ADDRESS + (i<<2));
    }
    /* Enable the SYSCFG peripheral clock*/ 
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN;
    /* Remap SRAM at 0x00000000 */
    Memory_Remap(SYSCFG_MemoryRemap_SRAM);
}    
/**
  * @brief  Memory_Remap
  */
void Memory_Remap(uint32_t SYSCFG_MemoryRemap)
{
    uint32_t tmpctrl = 0;
    /* Check the parameter */
    assert_param(IS_SYSCFG_MEMORY_REMAP(SYSCFG_MemoryRemap));
    /* Get CFGR1 register value */
    tmpctrl = SYSCFG->CFGR1;
    /* Clear MEM_MODE bits */
    tmpctrl &= (uint32_t) (~SYSCFG_CFGR1_MEM_MODE);
    /* Set the new MEM_MODE bits value */
    tmpctrl |= (uint32_t) SYSCFG_MemoryRemap;
    /* Set CFGR1 register with the new memory remap configuration */
    SYSCFG->CFGR1 = tmpctrl;
}
#endif
