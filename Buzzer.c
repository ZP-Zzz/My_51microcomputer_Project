#include <REGX52.H>
#include "delay.H" 
sbit Buzzer=P1^5;

unsigned int i;

void Buzzer_Time(unsigned int ms)		//����������ٺ���



{
	for(i=0;i<ms;i++)				  //ֻ�мӸ�ѭ������ʱ��������������
	{
		Buzzer=!Buzzer;
		delay(1);
	}

}

