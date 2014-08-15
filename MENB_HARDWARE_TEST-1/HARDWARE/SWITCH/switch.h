#ifndef __SWITCH_H
#define __SWITCH_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//SWITCH(单刀双掷)驱动代码	   
//SEU
//修改日期:2014/02/27
//版本：V1.0
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  	 

//#define SWITCH PCin(13)	//PC13   Enable/Disable Output Stimiulation Pulse
// H: Disable Output
// L: Enable Output

#define SWITCH  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//读取SWITCH电位

void SWITCH_Init(void);//IO初始化
		    
#endif
