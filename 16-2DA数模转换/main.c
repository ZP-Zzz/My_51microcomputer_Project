#include <REGX52.H>
#include "delay.H"
#include "TIMER0.H"
//#include "NIXIE.H"
//#include "matrixkey.H"   
//����pwm�ķ���
unsigned char Counter,Compare,i;		  //����ռ�ձ�ֻҪ����Compare��ֵ�Ϳ���
sbit DA=P2^1;

void main()
{
	Timer0Init();

	while(1)
	{

		 for(i=0;i<100;i++)
		 {
		 	 Compare=i;
			 delay(10);
		 }
		 for(i=100;i>0;i--)
		 {
		 	 Compare=i;
			 delay(10);
		 }
	
	
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
		DA=1;			  
	}
	else
	{
		DA=0;
	}

}







