#ifndef __SWITCH_H
#define __SWITCH_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//SWITCH(����˫��)��������	   
//SEU
//�޸�����:2014/02/27
//�汾��V1.0
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  	 

//#define SWITCH PCin(13)	//PC13   Enable/Disable Output Stimiulation Pulse
// H: Disable Output
// L: Enable Output

#define SWITCH  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//��ȡSWITCH��λ

void SWITCH_Init(void);//IO��ʼ��
		    
#endif
