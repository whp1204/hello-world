#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//LED��������	   
//SEU
//�޸�����:2014/02/27
//�汾��V1.0
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 							  

/****************************************************************************
* ��    �ƣ�void LED_Init(void)
* ��    �ܣ�LED ��ʼ��
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
//��ʼ��PA11,PA12,PB5,PE0Ϊ�����.ʹ��PA PB PE ��ʱ��	    
//LED IO��ʼ��

// H:��
// L:��

// #define LED_CH1_Detect  LED3
// #define LED_CH1_Stim    LED1
// #define LED_CH2_Detect  LED0
// #define LED_CH2_Stim    LED2
****************************************************************************/
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��PA PB PE �˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12;				 //�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��PA12,PA11
 GPIO_SetBits(GPIOA,GPIO_Pin_11|GPIO_Pin_12);						 //PA12,PA11 �����,LED��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��PB5
 GPIO_SetBits(GPIOB,GPIO_Pin_5);						 //PB5�����,LED��

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //�����趨������ʼ��PE0
 GPIO_SetBits(GPIOE,GPIO_Pin_0);						 //PE0�����,LED��
}
 
