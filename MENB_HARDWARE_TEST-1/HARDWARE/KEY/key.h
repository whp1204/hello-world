#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//KEY驱动代码	   
//SEU
//修改日期:2014/02/27
//版本：V1.0
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  	 
//#define KEY15 PEin(3)	//PE3     RESERVED
//#define KEY14 PEin(2)	//PE2     RESERVED
//#define KEY13 PAin(0)	//PA0     RESERVED

//#define KEY12 PCin(7)	//PC7     CH2 输出 停止键
//#define KEY11 PCin(6)	//PC6     CH2 输出 减小键
//#define KEY10 PCin(5)	//PC5     CH2 输出 增大键
//#define KEY9  PCin(4)	//PC4     CH2 输出 开始键

//#define KEY8 PCin(3)	//PC3     CH1 输出 增大键
//#define KEY7 PCin(2)	//PC2     CH1 输出 开始键
//#define KEY6 PCin(1)	//PC1     CH1 输出 减小键
//#define KEY5 PCin(0)	//PC0     CH1 输出 停止键

//#define KEY4 PCin(15)	//PC15    MENU 向上选择键
//#define KEY3 PCin(14)	//PC14    MENU 确认 OK 键
//#define KEY2 PBin(12)	//PB12    MENU 向下选择键
//#define KEY1 PBin(9)	//PB9     MENU 返回    键
//#define KEY0 PBin(8)	//PB8 		MENU 模式    键	 

////////////////////////////MENU按键区定义/////////////////////////////////////////////
#define KEY0  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//读取按键key0    MENU 模式    键
#define KEY1  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//读取按键key1    MENU 返回    键
#define KEY2  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)//读取按键key2   MENU 向下选择键
#define KEY3  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)//读取按键key3   MENU 确认 OK 键
#define KEY4  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)//读取按键key4   MENU 向上选择键

////////////////////////////CH1控制按键区定义/////////////////////////////////////////
#define KEY5  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)//读取按键key5    CH1 输出 停止键
#define KEY6  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)//读取按键key6    CH1 输出 减小键
#define KEY7  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)//读取按键key7    CH1 输出 开始键
#define KEY8  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)//读取按键key8    CH1 输出 增大键
////////////////////////////CH2控制按键区定义/////////////////////////////////////////
#define KEY9   GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)//读取按键key9   CH2 输出 开始键
#define KEY10  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)//读取按键key10  CH2 输出 增大键
#define KEY11  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)//读取按键key11  CH2 输出 减小键
#define KEY12  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)//读取按键key12  CH2 输出 停止键


////////////////////////////BACKUP按键区定义/////////////////////////////////////////
#define KEY13  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键key13   RESERVED
#define KEY14  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//读取按键key14   RESERVED
#define KEY15  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键key15   RESERVED


#define KEY_MENU_MODE	    1
#define KEY_MENU_UP       2
#define KEY_MENU_DOWN	    3
#define KEY_MENU_ENTEROK 	4
#define KEY_MENU_RETURN	  5

#define KEY_CH1_START	    6
#define KEY_CH1_STOP	    7
#define KEY_CH1_UP	      8
#define KEY_CH1_DOWN	    9

#define KEY_CH2_START	    10
#define KEY_CH2_STOP	    11
#define KEY_CH2_UP	      12
#define KEY_CH2_DOWN	    13

#define KEY_RESEVED_1     14
#define KEY_RESEVED_2     15
#define KEY_RESEVED_3     16


void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数	//typedef uint8_t u8				    
#endif
