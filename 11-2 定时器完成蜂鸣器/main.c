#include <REGX52.H>
#include "Timer0.H"
sbit Buzzer=P1^5;



void main()
{
	Timer0Init();
	while(1)
	{
		
	}
} 


//ÿ1ms����һ���ж�
void Timer0_Routine() interrupt 1	//����T0��������������ʲô(�ж��ӳ���)
{
	TL0 = 0x18;			//���¸���ֵ�������ٴ�64535��ʼ	
	TH0 = 0xFC;
	Buzzer=~Buzzer;			 //����500Hz�ķ�תƵ��
}