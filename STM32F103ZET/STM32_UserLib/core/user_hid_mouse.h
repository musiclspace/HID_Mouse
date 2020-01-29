/***************************************************************************************
 * All Rights Reserved
 * STM32 UserLib
 ***************************************************************************************
 * @File    user_hid_mouse.h
 *
 * @Author  Solen Liu <solen.pico@gmail.com>
 *
 * @Brief   
 *          
 * @Date    2020/01/20 
 *
 ***************************************************************************************/
#ifndef __USER_HID_MOUSE_H
#define __USER_HID_MOUSE_H
#include "user_config.h"
void user_hid_mouse_move(uint8_t x_move, uint8_t y_move);
void user_hid_mouse_left_press(void);
void user_hid_mouse_left_release(void);

#endif
