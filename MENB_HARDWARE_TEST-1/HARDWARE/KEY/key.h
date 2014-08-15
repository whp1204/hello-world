#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//KEY��������	   
//SEU
//�޸�����:2014/02/27
//�汾��V1.0
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  	 
//#define KEY15 PEin(3)	//PE3     RESERVED
//#define KEY14 PEin(2)	//PE2     RESERVED
//#define KEY13 PAin(0)	//PA0     RESERVED

//#define KEY12 PCin(7)	//PC7     CH2 ��� ֹͣ��
//#define KEY11 PCin(6)	//PC6     CH2 ��� ��С��
//#define KEY10 PCin(5)	//PC5     CH2 ��� �����
//#define KEY9  PCin(4)	//PC4     CH2 ��� ��ʼ��

//#define KEY8 PCin(3)	//PC3     CH1 ��� �����
//#define KEY7 PCin(2)	//PC2     CH1 ��� ��ʼ��
//#define KEY6 PCin(1)	//PC1     CH1 ��� ��С��
//#define KEY5 PCin(0)	//PC0     CH1 ��� ֹͣ��

//#define KEY4 PCin(15)	//PC15    MENU ����ѡ���
//#define KEY3 PCin(14)	//PC14    MENU ȷ�� OK ��
//#define KEY2 PBin(12)	//PB12    MENU ����ѡ���
//#define KEY1 PBin(9)	//PB9     MENU ����    ��
//#define KEY0 PBin(8)	//PB8 		MENU ģʽ    ��	 

////////////////////////////MENU����������/////////////////////////////////////////////
#define KEY0  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//��ȡ����key0    MENU ģʽ    ��
#define KEY1  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//��ȡ����key1    MENU ����    ��
#define KEY2  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)//��ȡ����key2   MENU ����ѡ���
#define KEY3  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)//��ȡ����key3   MENU ȷ�� OK ��
#define KEY4  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)//��ȡ����key4   MENU ����ѡ���

////////////////////////////CH1���ư���������/////////////////////////////////////////
#define KEY5  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)//��ȡ����key5    CH1 ��� ֹͣ��
#define KEY6  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)//��ȡ����key6    CH1 ��� ��С��
#define KEY7  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)//��ȡ����key7    CH1 ��� ��ʼ��
#define KEY8  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)//��ȡ����key8    CH1 ��� �����
////////////////////////////CH2���ư���������/////////////////////////////////////////
#define KEY9   GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)//��ȡ����key9   CH2 ��� ��ʼ��
#define KEY10  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)//��ȡ����key10  CH2 ��� �����
#define KEY11  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)//��ȡ����key11  CH2 ��� ��С��
#define KEY12  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)//��ȡ����key12  CH2 ��� ֹͣ��


////////////////////////////BACKUP����������/////////////////////////////////////////
#define KEY13  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����key13   RESERVED
#define KEY14  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//��ȡ����key14   RESERVED
#define KEY15  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����key15   RESERVED


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


void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8);  	//����ɨ�躯��	//typedef uint8_t u8				    
#endif
