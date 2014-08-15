#include "sys.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "switch.h"
#include "usart.h"


// #include "wkup.h"
// #include "wdg.h"

//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//MAIN����  ����MENB-II ��֤��Ӳ��ģ��--LED,KEY,SWITCH��BEEPӲ���Ƿ���ȷ  
//SEU
//�޸�����:2014/04/10
//�汾��V1.1
//All rights reserved	

//��֤������
//1.Switch ʹ�ܿ��ƵƵ�״̬ enable(0) /disable (1)  

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////ȫ������()��������/////////////////////////////////////////////////////////////

////////////////////////////////////////////ȫ��flag��������/////////////////////////////////////////////////////////////

/////////////////////////////////////////////�Ӻ�������//////////////////////////////////////////////////////////////////

/////////////////////////////////////////////MAIN FUNCTION	/////////////////////////////////////////////////////////////
 int main(void)
 {	
		u8 t;
	  delay_init();	    	 //��ʱ������ʼ��	  
		NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ�(0,1,2,3)��2λ��Ӧ���ȼ�(0,1,2,3)
		LED_Init();		//LED�˿ڳ�ʼ��
		KEY_Init();   //������ʼ��
		BEEP_Init();  //��������ʼ���˿�
	  SWITCH_Init();
	 
	while(1)
	{
		t=KEY_Scan(0);		//�õ���ֵ
		if(t)
		{
			switch(t)
			{				 
				case KEY_MENU_MODE:	//
					BEEP=1;
					break;
				case KEY_MENU_UP:	//
					BEEP=0;
					break;
				case KEY_MENU_DOWN:	// 
					LED_CH1_Detect=0;
					break;
				case KEY_MENU_ENTEROK:	//
           LED_CH1_Stim=0;
					break;
				case KEY_MENU_RETURN:	//
          LED_CH2_Detect=0;
					break;				
				case KEY_CH1_START:	//
          LED_CH2_Stim=0;
					break;				
				case KEY_CH1_STOP:	//
           LED_CH1_Detect=1;
					break;
				case KEY_CH1_UP:	//
           LED_CH1_Stim=1;
					break;				
				case KEY_CH1_DOWN:	//
          LED_CH2_Detect=1;
					break;	

				case KEY_CH2_START:	//
           LED_CH2_Stim=1;
					break;				
				
				case KEY_CH2_STOP:	//
           LED0=!LED0;
				   LED1=!LED1;
					break;
				case KEY_CH2_UP:	//
           LED2=!LED2;
				   LED3=!LED3;
					break;				
				case KEY_CH2_DOWN:	//
					LED0=!LED0;
				  LED1=!LED1;
           LED2=!LED2;
				   LED3=!LED3;				  
					break;	
			
			}
		}
		else
		{
			 delay_ms(10); 
		}
  }
}
