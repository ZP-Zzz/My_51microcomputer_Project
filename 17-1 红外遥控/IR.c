#include <REGX52.H>
#include "timer0.H"
#include "INT0.H" 

/*IR_State=0��ʾ����״̬
  IR_State=1��ʾ����Start״̬����repeat״̬
  IR_State=2��ʾ��ʼ����   32bit���ݽ���   ����32��
*/

unsigned int IR_Time;
unsigned char IR_State;
unsigned char IR_Data[4];
unsigned char IR_pData;
unsigned char IR_DataFlag,IR_RepeatFlag,IR_Address,IR_Command;


void IR_Init(void)
{
	Timer0Init();
	Int0_Init();
}


unsigned char IR_GetDataFlag(void)
{
	if(IR_DataFlag)
	{
		IR_DataFlag=0;
		return 1;
	}
	return 0;
}




unsigned char IR_GetRepeatFlag(void)
{
	if(IR_RepeatFlag)
	{
		IR_RepeatFlag=0;
		return 1;
	}
	return 0;
}



unsigned char IR_GetAddress(void)
{
	return IR_Address;
}

unsigned char IR_GetCommand(void)
{
	return IR_Command;
}



void Int0_Routine(void) interrupt 0
{
	if(IR_State==0)				//״̬0������״̬
	{
		Timer0_SetCounter(0);	//��ʱ��������0
		Timer0_Run(1);			//��ʱ������
		IR_State=1;				//��״̬Ϊ1
	}
	else if(IR_State==1)		//״̬1���ȴ�Start�źŻ�Repeat�ź�
	{
		IR_Time=Timer0_GetCounter();	//��ȡ��һ���жϵ��˴��жϵ�ʱ��
		Timer0_SetCounter(0);	//��ʱ��������0
		//�����ʱΪ13.5ms������յ���Start�źţ��ж�ֵ��12MHz������Ϊ13500����11.0592MHz������Ϊ12442��
		if(IR_Time>13500-500 && IR_Time<13500+500)
		{
			IR_State=2;			//��״̬Ϊ2
		}
		//�����ʱΪ11.25ms������յ���Repeat�źţ��ж�ֵ��12MHz������Ϊ11250����11.0592MHz������Ϊ10368��
		else if(IR_Time>11250-500 && IR_Time<11250+500)
		{
			IR_RepeatFlag=1;	//���յ�����֡��־λΪ1
			Timer0_Run(0);		//��ʱ��ֹͣ
			IR_State=0;			//��״̬Ϊ0
		}
		else					//���ճ���
		{
			IR_State=1;			//��״̬Ϊ1
		}
	}
	else if(IR_State==2)		//״̬2����������
	{
		IR_Time=Timer0_GetCounter();	//��ȡ��һ���жϵ��˴��жϵ�ʱ��
		Timer0_SetCounter(0);	//��ʱ��������0
		//�����ʱΪ1120us������յ�������0���ж�ֵ��12MHz������Ϊ1120����11.0592MHz������Ϊ1032��
		if(IR_Time>1120-500 && IR_Time<1120+500)
		{
			IR_Data[IR_pData/8]&=~(0x01<<(IR_pData%8));	//���ݶ�Ӧλ��0
			IR_pData++;			//����λ��ָ������
		}
		//�����ʱΪ2250us������յ�������1���ж�ֵ��12MHz������Ϊ2250����11.0592MHz������Ϊ2074��
		else if(IR_Time>2250-500 && IR_Time<2250+500)
		{
			IR_Data[IR_pData/8]|=(0x01<<(IR_pData%8));	//���ݶ�Ӧλ��1
			IR_pData++;			//����λ��ָ������
		}
		else					//���ճ���
		{
			IR_pData=0;			//����λ��ָ����0
			IR_State=1;			//��״̬Ϊ1
		}
		if(IR_pData>=32)		//������յ���32λ����
		{
			IR_pData=0;			//����λ��ָ����0
			if((IR_Data[0]==~IR_Data[1]) && (IR_Data[2]==~IR_Data[3]))	//������֤
			{
				IR_Address=IR_Data[0];	//ת������
				IR_Command=IR_Data[2];
				IR_DataFlag=1;	//���յ�����֡��־λΪ1
			}
			Timer0_Run(0);		//��ʱ��ֹͣ
			IR_State=0;			//��״̬Ϊ0
		}
	}
}






























