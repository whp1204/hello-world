#ifndef __WKUP_H
#define __WKUP_H	 
#include "sys.h"
 
//////////////////////////////////////////////////////////////////////////////////	 
//EWY_PRJ
//待机唤醒 代码	   
//修改日期:2014/3/8
//All rights reserved	
//SEU
//////////////////////////////////////////////////////////////////////////////////								  
					    
#define WKUP_KD PAin(0)			//PA0 检测是否外部WK_UP按键按下

////////////////////////////extern 全局变量///////////////////
extern u8 ReadOK_Flag;
extern u8 Send_Flag;
extern u8 KeyPress_Flag;

////////////////////////////extern main.c中的子函数////////////////////
//读取所有数据  
//ERROR(0):读取耳温数据错误
//SUCCESS(1):读取耳温数据正确
extern u8 ALLData_Read(void);
//发送8字节数据(报头、耳温和温湿度数据、报尾)到ZIGBEE
extern void Data_ZigbeeSend(void);

////////////////////////////////函数声明//////////////////////////
u8 Check_WKUP(void);  			//检测WKUP脚的信号
void WKUP_Init(void); 			//PA0 WKUP唤醒初始化
void Sys_Enter_Standby(void);	//系统进入待机模式
#endif


