#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//LED驱动代码	   
//SEU
//修改日期:2014/02/27
//版本：V1.0
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 							  

/****************************************************************************
* 名    称：void LED_Init(void)
* 功    能：LED 初始化
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
//初始化PA11,PA12,PB5,PE0为输出口.使能PA PB PE 口时钟	    
//LED IO初始化

// H:灭
// L:亮

// #define LED_CH1_Detect  LED3
// #define LED_CH1_Stim    LED1
// #define LED_CH2_Detect  LED0
// #define LED_CH2_Stim    LED2
****************************************************************************/
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);	 //使能PA PB PE 端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12;				 //端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化PA12,PA11
 GPIO_SetBits(GPIOA,GPIO_Pin_11|GPIO_Pin_12);						 //PA12,PA11 输出高,LED灭
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化PB5
 GPIO_SetBits(GPIOB,GPIO_Pin_5);						 //PB5输出高,LED灭

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //根据设定参数初始化PE0
 GPIO_SetBits(GPIOE,GPIO_Pin_0);						 //PE0输出高,LED灭
}
 
