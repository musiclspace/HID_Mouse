/***************************************************************************************
 * All Rights Reserved
 * STM32 UserLib
 ***************************************************************************************
 * @File    user_hid_mouse.c
 *
 * @Author  Solen Liu <solen.pico@gmail.com>
 *
 * @Brief   mouse apis
 *          
 * @Date    2020/01/20 
 *
 ***************************************************************************************/
#include "user_hid_mouse.h"
#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h"
extern USBD_HandleTypeDef hUsbDeviceFS;

/*
 * buffer[0]  |  bit 0 - Left  Button
 *            |  bit 1 - Right Button
 * buffer[1]  |  Cursor Movement X axis (Signed from -127 to 127)
 * buffer[2]  |  Cursor Movement Y axis (Signed from -127 to 127)
 * buffer[3]  |  Wheel Vertical Movement
 *
    Origin----------  X 
	|
	|
	|
	|
	|
	
	Y
 */

/**
  * @brief  hid mouse move 
  * @param  x_move - x axis steps / y_move - y axis steps
  */
void user_hid_mouse_move(uint8_t x_move, uint8_t y_move)
{
    uint8_t mouse_buf[4];
	mouse_buf[0] = 0;
	mouse_buf[1] = x_move;
	mouse_buf[2] = y_move;
	mouse_buf[3] = 0;
	USBD_HID_SendReport(&hUsbDeviceFS,mouse_buf,4);
}	
/**
  * @brief  hid mouse single click start ; delay for 100ms and then send release msg
  */
void user_hid_mouse_left_press(void)
{
	uint8_t mouse_buf[4];
	mouse_buf[0] = 1;
	mouse_buf[1] = 0;
	mouse_buf[2] = 0;
	mouse_buf[3] = 0;
	USBD_HID_SendReport(&hUsbDeviceFS,mouse_buf,4);
}
/**
  * @brief  hid mouse single click ends
  */
void user_hid_mouse_left_release(void)
{
	uint8_t mouse_buf[4];
	mouse_buf[0] = 0;
	mouse_buf[1] = 0;
	mouse_buf[2] = 0;
	mouse_buf[3] = 0;
	USBD_HID_SendReport(&hUsbDeviceFS,mouse_buf,4);
}           

