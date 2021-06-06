#include <REGX52.H>
#include "TIMER1.H"

sbit Motor=P1^0;

unsigned char Counter,Compare;

void Motor_Init()
{
	Timer1_Init();
}


void Motor_SetSpeed(unsigned char Speed)
{
	Compare=Speed;
}





void Timer1_Routine() interrupt 3	//����T0��������������ʲô(�ж��ӳ���)
{
	TL1 = 0x9C;		//���ö�ʱ��ʼֵ
	TH1 = 0xFF;		//���ö�ʱ��ʼֵ
	Counter++;
	if(Counter>=100)
		Counter=0;
	if(Counter<Compare)
	{
		Motor=1;			  //��1ת
	}
	else
	{
		Motor=0;
	}

}






