#include "beep.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//BEEP驱动代码	   
//SEU
//修改日期:2014/02/27
//版本：V1.0
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  


/****************************************************************************
* 名    称：void BEEP_Init(void)
* 功    能：蜂鸣器初始化
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
//初始化PC0为输出口.并使能这个口的时钟		    
//蜂鸣器初始化
//BEEP PEout(1)	蜂鸣器
//H: 响
//L:不响
****************************************************************************/
void BEEP_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //使能GPIOE端口时钟
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //BEEP-->PE.1 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //速度为50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);	 //根据参数初始化GPIOE.1
 
 GPIO_ResetBits(GPIOE,GPIO_Pin_1);//OUTPUT 0，关闭BEEP

}
