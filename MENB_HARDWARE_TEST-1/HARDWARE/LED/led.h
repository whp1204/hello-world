#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//LED驱动代码	   
//SEU
//修改日期:2014/02/27
//版本：V1.0
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PAout(11)// PA11   CH2 detection status indicator
#define LED1 PAout(12)// PA12   CH1 stimulation status indicator
#define LED2 PBout(5)// PB5	    CH2 stimulation status indicator
#define LED3 PEout(0)// PE0     CH1 detection status indicator

#define LED_CH1_Detect  LED3
#define LED_CH1_Stim    LED1
#define LED_CH2_Detect  LED0
#define LED_CH2_Stim    LED2

// H:灭
// L:亮
void LED_Init(void);//初始化

		 				    
#endif
