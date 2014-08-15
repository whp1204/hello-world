#include "key.h"
#include "sys.h" 
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//MENB-II
//KEY驱动代码	   
//SEU
//修改日期:2014/02/27
//版本：V1.0
//All rights reserved								  
////////////////////////////////////////////////////////////////////////////////// 


//按键初始化函数
/****************************************************************************
* 名    称：void KEY_Init(void)
* 功    能：按键初始化函数
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
//#define KEY15 PEin(3)	//PE3     RESERVED
//#define KEY14 PEin(2)	//PE2     RESERVED
//#define KEY13 PAin(0)	//PA0     RESERVED

//#define KEY12 PCin(7)	//PC7     CH2 输出 停止键
//#define KEY11 PCin(6)	//PC6     CH2 输出 减小键
//#define KEY10 PCin(5)	//PC5     CH2 输出 增大键
//#define KEY9  PCin(4)	//PC4     CH2 输出 开始键

//#define KEY8 PCin(3)	//PC3     CH1 输出 增大键
//#define KEY7 PCin(2)	//PC2     CH1 输出 开始键
//#define KEY6 PCin(1)	//PC1     CH1 输出 减小键
//#define KEY5 PCin(0)	//PC0     CH1 输出 停止键

//#define KEY4 PCin(15)	//PC15    MENU 向上选择键
//#define KEY3 PCin(14)	//PC14    MENU 确认 OK 键
//#define KEY2 PBin(12)	//PB12    MENU 向下选择键
//#define KEY1 PBin(9)	//PB9     MENU 返回    键
//#define KEY0 PBin(8)	//PB8 		MENU 模式    键	
****************************************************************************/
void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|
	                       RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA B C E时钟
	//初始化 KEY 下拉输入(ALL 输入 )
	
 	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_12;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PB8 PB9 PB12设置成输入，默认下拉	  
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB.8,9,12
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2| GPIO_Pin_3|GPIO_Pin_4|
	                               GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_14|GPIO_Pin_15;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PC 0~7,14,15 设置成输入，默认下拉	  
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC.0~7,14,15
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PE2,3设置成输入，默认下拉	  
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE.2,3

}

/****************************************************************************
* 名    称：u8 KEY_Scan(u8 mode)
* 功    能：按键处理函数
* 入口参数：无
* 出口参数：返回按键值
* 说    明：
* 调用方法：mode:0,不支持连续按;1,支持连续按;
//注意此函数有响应优先级,KEY1

//0，没有任何按键按下

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
****************************************************************************/
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志

	if(mode)key_up=1;  //支持连按		  

	if(key_up&&(KEY0==1||KEY1==1||KEY2==1||KEY3==1||KEY4==1||
		          KEY5==1||KEY6==1||KEY7==1||KEY8==1||KEY9==1||
	            KEY10==1||KEY11==1||KEY12==1))
	{
		delay_ms(10);//去抖动 
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
 	return 0;// 无按键按下
}
