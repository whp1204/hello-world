#include "switch.h"
#include "sys.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//SWITCH(����˫��)��������	   
//SEU
//�޸�����:2014/02/27
//�汾��V1.0
//All rights reserved										  
////////////////////////////////////////////////////////////////////////////////// 
								    
/****************************************************************************
* ��    �ƣ�void SWITCH_Init(void) 
* ��    �ܣ�switch��ʼ������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 

//��ʼ   SWITCH-->GPIOC.13
// H: Disable Output
// L: Enable Output
****************************************************************************/
void SWITCH_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//ʹ��PORTEʱ��	
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;//PC13
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC13
}

