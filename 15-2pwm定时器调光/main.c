#include <REGX52.H>
#include "delay.H"
#include "TIMER0.H"
#include "NIXIE.H"
#include "matrixkey.H"   
//����pwm�ķ���
unsigned char Counter,Compare,Key,Speed,i;		  //����ռ�ձ�ֻҪ����Compare��ֵ�Ϳ���
sbit LED=P2^0;

void main()
{
	Timer0Init();
	Compare=10;
	while(1)
	{

	}
}




void Timer0_Routine() interrupt 1	//����T0��������������ʲô(�ж��ӳ���)
{
	TL0 = 0x9C;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	Counter++;
	if(Counter>=100)
		Counter=0;
	if(Counter<Compare)
	{
		LED=0;
	}
	else
	{
		LED=1;
	}

}







