# HID_Mouse
USB HID Mouse
## 一，前言
   USB Device HID Mouse功能， 实现基本的单击，移动功能
   
* 目标平台： STM32F103ZET
* CubeMX版本： STM32CubeMX 5.5.0
* CubeMX FW版本：STM32Cube_FW_F1_V1.8.0
## 二，硬件连接
   ![硬件连接](https://img-blog.csdnimg.cn/20200129151108803.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L211c2ljYWxzcGFjZQ==,size_16,color_FFFFFF,t_70) 
   USB Device 很多硬件，包括官方的开发板上会有一个使能管脚，注意此管脚的选通。F1系列MCU的DP管脚内置上拉，因此外部直连即可。
## 三，代码配置
   ![Cube配置](https://img-blog.csdnimg.cn/20200129151557224.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L211c2ljYWxzcGFjZQ==,size_16,color_FFFFFF,t_70)
   时钟配置后，选择USB Device , 标准HID即可，然后直接生成代码，就可以直接使用。
   设备为指针，指定按键占用3 Bit ,  X Y 的偏移量分别占用 8 Bit (有符号)
   对应鼠标上报的HID消息格式如下

   buffer[0]  |  bit 0 - Left  Button
              |  bit 1 - Right Button
   buffer[1]  |  Cursor Movement X axis (Signed from -127 to 127)
   buffer[2]  |  Cursor Movement Y axis (Signed from -127 to 127)
   buffer[3]  |  Wheel Vertical Movement
  
    Origin----------  X 
	|
	|
	|
	|
	|
	
	Y
 */
## 四，测试移动和点击
   代码中默认为循环单击，移动功能调用
user_hid_mouse_move

[CSDN 博客链接](https://blog.csdn.net/musicalspace/article/details/104107035) 
