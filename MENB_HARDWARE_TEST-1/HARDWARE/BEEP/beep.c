#include "beep.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//BEEP��������	   
//SEU
//�޸�����:2014/02/27
//�汾��V1.0
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  


/****************************************************************************
* ��    �ƣ�void BEEP_Init(void)
* ��    �ܣ���������ʼ��
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
//��ʼ��PC0Ϊ�����.��ʹ������ڵ�ʱ��		    
//��������ʼ��
//BEEP PEout(1)	������
//H: ��
//L:����
****************************************************************************/
void BEEP_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��GPIOE�˿�ʱ��
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //BEEP-->PE.1 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ٶ�Ϊ50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);	 //���ݲ�����ʼ��GPIOE.1
 
 GPIO_ResetBits(GPIOE,GPIO_Pin_1);//OUTPUT 0���ر�BEEP

}
