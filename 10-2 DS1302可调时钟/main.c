#include <REGX52.H>
#include "LCD1602.H"
#include "DS1302.H"
#include "delay.H"
#include "matrixkey.H"
#include "Timer0.H"

unsigned char KeyNum,Mode,TimeSelect,TimeFlag;


void TimeShow(void)
{
	DS1302_ReadTime();	  
	LCD_ShowNum(1,1,DS1302_Time[0],2);		  //��
	LCD_ShowNum(1,4,DS1302_Time[1],2);		  //��
	LCD_ShowNum(1,7,DS1302_Time[2],2);		  //��
	LCD_ShowNum(2,1,DS1302_Time[3],2);		  //ʱ
	LCD_ShowNum(2,4,DS1302_Time[4],2);		  //��
	LCD_ShowNum(2,7,DS1302_Time[5],2);		  //��
}


void TimeSet(void)
{
	if(KeyNum==2)
	{
		TimeSelect++;
		if(TimeSelect>5) TimeSelect=0;
	}
	if(KeyNum==3)
	{
		DS1302_Time[TimeSelect]++;
		if(DS1302_Time[0]>99){DS1302_Time[0]=0;}
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}
		if(DS1302_Time[1]==1||DS1302_Time[1]==3||DS1302_Time[1]==5||DS1302_Time[1]==8||DS1302_Time[1]==10||DS1302_Time[1]==12||DS1302_Time[1]==7)
		{
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}			 
		}					
		else if(DS1302_Time[1]==4||DS1302_Time[1]==6||DS1302_Time[1]==9||DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
			}
			else
			{
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
			}
		}
		if(DS1302_Time[3]>23){DS1302_Time[3]=0;}
		if(DS1302_Time[4]>59){DS1302_Time[4]=0;}
		if(DS1302_Time[5]>59){DS1302_Time[5]=0;}

	}
	if(KeyNum==4)
	{
		DS1302_Time[TimeSelect]--;
		if(DS1302_Time[0]<0){DS1302_Time[0]=99;}
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}
		if(DS1302_Time[1]==1||DS1302_Time[1]==3||DS1302_Time[1]==5||DS1302_Time[1]==8||DS1302_Time[1]==10||DS1302_Time[1]==12||DS1302_Time[1]==7)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=31;}
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}			 
			 
		}					
		else if(DS1302_Time[1]==4||DS1302_Time[1]==6||DS1302_Time[1]==9||DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=30;}
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]<1){DS1302_Time[2]=29;}
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
			}
			else
			{
				if(DS1302_Time[2]<1){DS1302_Time[2]=28;}
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
			}
		}
		if(DS1302_Time[3]<0){DS1302_Time[3]=23;}
		if(DS1302_Time[4]<0){DS1302_Time[4]=59;}
		if(DS1302_Time[5]<0){DS1302_Time[5]=59;}
	}
	if(TimeSelect==0&&TimeFlag==1){LCD_ShowString(1,1,"  ");}
	else {LCD_ShowNum(1,1,DS1302_Time[0],2);}
	if(TimeSelect==1&&TimeFlag==1){LCD_ShowString(1,4,"  ");}
	else {LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(TimeSelect==2&&TimeFlag==1){LCD_ShowString(1,7,"  ");}
	else {LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(TimeSelect==3&&TimeFlag==1){LCD_ShowString(2,1,"  ");}
	else {LCD_ShowNum(2,1,DS1302_Time[3],2);}
	if(TimeSelect==4&&TimeFlag==1){LCD_ShowString(2,4,"  ");}
	else {LCD_ShowNum(2,4,DS1302_Time[4],2);}
	if(TimeSelect==5&&TimeFlag==1){LCD_ShowString(2,7,"  ");}
	else {LCD_ShowNum(2,7,DS1302_Time[5],2);}				
}


 
void main()
{
	LCD_Init();
	DS1302_Init();
	Timer0Init();
	DS1302_SetTime();	   //ֻ��Ҫ��һ�Σ�����б��õ�Դ������ͻ��Լ���ʼ��
	LCD_ShowString(1,3,"-");
	LCD_ShowString(1,6,"-");
	LCD_ShowString(2,3,":");
	LCD_ShowString(2,6,":");

	while(1)
	{
		KeyNum=matrixkey();
		if(KeyNum==1)
		{
			if(Mode==0){Mode=1;}
			else if(Mode==1){Mode=0;DS1302_SetTime();}	
		}
		switch(Mode)
		{
			case 0:TimeShow();break;
			case 1:TimeSet();break;
		}
	}
}


void Timer0_Routine() interrupt 1	//����T0��������������ʲô(�ж��ӳ���)
{
	static unsigned int T0count;    //�޷���intΪ0~65535
	TL0 = 0x18;			//���¸���ֵ�������ٴ�64535��ʼ	
	TH0 = 0xFC;
	T0count++;
	if(T0count>=500)
	{
		T0count=0;
		TimeFlag=!TimeFlag;	   //��ʱ����1��Ϊ������0��1֮���л�����־λ��
	}

}















