#ifndef __WKUP_H
#define __WKUP_H	 
#include "sys.h"
 
//////////////////////////////////////////////////////////////////////////////////	 
//EWY_PRJ
//�������� ����	   
//�޸�����:2014/3/8
//All rights reserved	
//SEU
//////////////////////////////////////////////////////////////////////////////////								  
					    
#define WKUP_KD PAin(0)			//PA0 ����Ƿ��ⲿWK_UP��������

////////////////////////////extern ȫ�ֱ���///////////////////
extern u8 ReadOK_Flag;
extern u8 Send_Flag;
extern u8 KeyPress_Flag;

////////////////////////////extern main.c�е��Ӻ���////////////////////
//��ȡ��������  
//ERROR(0):��ȡ�������ݴ���
//SUCCESS(1):��ȡ����������ȷ
extern u8 ALLData_Read(void);
//����8�ֽ�����(��ͷ�����º���ʪ�����ݡ���β)��ZIGBEE
extern void Data_ZigbeeSend(void);

////////////////////////////////��������//////////////////////////
u8 Check_WKUP(void);  			//���WKUP�ŵ��ź�
void WKUP_Init(void); 			//PA0 WKUP���ѳ�ʼ��
void Sys_Enter_Standby(void);	//ϵͳ�������ģʽ
#endif


