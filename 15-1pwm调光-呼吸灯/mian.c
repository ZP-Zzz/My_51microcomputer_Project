#include <REGX52.H>
//#include "delay.H" 

sbit LED=P2^0;

void del(unsigned int t)		 //����ʱ
{
	while(t--);
}

void main()
{	unsigned char time,z;    //�ⶨ��time�����ķǳ��죬�ٶ���һ��i�����ӻ��仯		
	while(1)
	{
		for(time=0;time<100;time++)
		{
			for(z=0;z<20;z++)
			{
				LED=0;
				del(time);
				LED=1;
				del(100-time);				 
			}

		}
		 for(time=100;time>0;time--)
		{
			for(z=0;z<20;z++)
			{
				LED=0;
				del(time);
				LED=1;
				del(100-time);
			}

		}
	}

//		LED=0;
//		LED=1;
//		LED=1;
//		LED=1;
//		LED=1;
//		LED=1;
//		LED=1;
//		LED=1;		 //��һ������7�����Ʊ䰵�������PWM�Ļ���ԭ��
	
}