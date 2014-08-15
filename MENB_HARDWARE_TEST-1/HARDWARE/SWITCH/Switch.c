#include "switch.h"
#include "sys.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//SWITCH(单刀双掷)驱动代码	   
//SEU
//修改日期:2014/02/27
//版本：V1.0
//All rights reserved										  
////////////////////////////////////////////////////////////////////////////////// 
								    
/****************************************************************************
* 名    称：void SWITCH_Init(void) 
* 功    能：switch初始化函数
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 

//初始   SWITCH-->GPIOC.13
// H: Disable Output
// L: Enable Output
****************************************************************************/
void SWITCH_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//使能PORTE时钟	
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;//PC13
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC13
}

