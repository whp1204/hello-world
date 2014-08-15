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
//MAIN函数  测试MENB-II 验证板硬件模块--LED,KEY,SWITCH和BEEP硬件是否正确  
//SEU
//修改日期:2014/04/10
//版本：V1.1
//All rights reserved	

//验证程序功能
//1.Switch 使能控制灯的状态 enable(0) /disable (1)  

//1，KEY0按下   KEY_MENU_MODE  
//2，KEY4按下   KEY_MENU_UP
//3，KEY2按下   KEY_MENU_DOWN
//4, KEY3按下   KEY_MENU_ENTEROK
//5，KEY1按下   KEY_MENU_RETURN

//6，KEY7按下   KEY_CH1_START
//7，KEY5按下   KEY_CH1_STOP
//8, KEY8按下   KEY_CH1_UP
//9，KEY6按下   KEY_CH1_DOWN

//10 KEY9按下   KEY_CH2_START
//11 KEY12按下  KEY_CH2_STOP
//12 KEY10按下  KEY_CH2_UP
//13 KEY11按下  KEY_CH2_DOWN
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////全局数据()变量声明/////////////////////////////////////////////////////////////

////////////////////////////////////////////全局flag变量声明/////////////////////////////////////////////////////////////

/////////////////////////////////////////////子函数声明//////////////////////////////////////////////////////////////////

/////////////////////////////////////////////MAIN FUNCTION	/////////////////////////////////////////////////////////////
 int main(void)
 {	
		u8 t;
	  delay_init();	    	 //延时函数初始化	  
		NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级(0,1,2,3)，2位响应优先级(0,1,2,3)
		LED_Init();		//LED端口初始化
		KEY_Init();   //按键初始化
		BEEP_Init();  //蜂鸣器初始化端口
	  SWITCH_Init();
	 
	while(1)
	{
		t=KEY_Scan(0);		//得到键值
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
