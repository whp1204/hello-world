#include "key.h"
#include "sys.h" 
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//KEY��������	   
//SEU
//�޸�����:2014/02/27
//�汾��V1.0
//All rights reserved								  
////////////////////////////////////////////////////////////////////////////////// 


//������ʼ������
/****************************************************************************
* ��    �ƣ�void KEY_Init(void)
* ��    �ܣ�������ʼ������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷������� 
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
****************************************************************************/
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|
	                       RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA B C Eʱ��
	//��ʼ�� KEY ��������(ALL ���� )
	
 	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_12;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PB8 PB9 PB12���ó����룬Ĭ������	  
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB.8,9,12
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2| GPIO_Pin_3|GPIO_Pin_4|
	                               GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_14|GPIO_Pin_15;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PC 0~7,14,15 ���ó����룬Ĭ������	  
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC.0~7,14,15
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PE2,3���ó����룬Ĭ������	  
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE.2,3

}

/****************************************************************************
* ��    �ƣ�u8 KEY_Scan(u8 mode)
* ��    �ܣ�����������
* ��ڲ�������
* ���ڲ��������ذ���ֵ
* ˵    ����
* ���÷�����mode:0,��֧��������;1,֧��������;
//ע��˺�������Ӧ���ȼ�,KEY1

//0��û���κΰ�������

//1��KEY0����   KEY_MENU_MODE
//2��KEY4����   KEY_MENU_UP
//3��KEY2����   KEY_MENU_DOWN
//4, KEY3����   KEY_MENU_ENTEROK
//5��KEY1����   KEY_MENU_RETURN

//6��KEY7����   KEY_CH1_START
//7��KEY5����   KEY_CH1_STOP
//8, KEY8����   KEY_CH1_UP
//9��KEY6����   KEY_CH1_DOWN

//10 KEY9����   KEY_CH2_START
//11 KEY12����  KEY_CH2_STOP
//12 KEY10����  KEY_CH2_UP
//13 KEY11����  KEY_CH2_DOWN
****************************************************************************/
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־

	if(mode)key_up=1;  //֧������		  

	if(key_up&&(KEY0==1||KEY1==1||KEY2==1||KEY3==1||KEY4==1||
		          KEY5==1||KEY6==1||KEY7==1||KEY8==1||KEY9==1||
	            KEY10==1||KEY11==1||KEY12==1))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		
		if(KEY0==1)return       KEY_MENU_MODE;
		else if(KEY4==1)return  KEY_MENU_UP;
		else if(KEY2==1)return  KEY_MENU_DOWN;			
		else if(KEY3==1)return  KEY_MENU_ENTEROK;	
		else if(KEY1==1)return  KEY_MENU_RETURN;	
		
		else if(KEY7==1)return  KEY_CH1_START;	
		else if(KEY5==1)return  KEY_CH1_STOP;	
		else if(KEY8==1)return  KEY_CH1_UP;	
		else if(KEY6==1)return  KEY_CH1_DOWN;	
	
		else if(KEY9==1)return  KEY_CH2_START;	
		else if(KEY12==1)return KEY_CH2_STOP;	
		else if(KEY10==1)return KEY_CH2_UP;
		else if(KEY11==1)return KEY_CH2_DOWN;		
	}
	else if(KEY1==0&&KEY2==0&&KEY3==0&&KEY4==0&&
		      KEY5==0&&KEY6==0&&KEY7==0&&KEY8==0&&
	        KEY9==0&&KEY10==0&&KEY11==0&&KEY12==0)	key_up=1; 	    
 	return 0;// �ް�������
}
