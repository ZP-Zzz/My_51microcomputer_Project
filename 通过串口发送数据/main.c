#include <REGX52.H>
#include <STDIO.H>
#include "delay.H"
#include "timer0.H"  

unsigned char i=0x00;



void main()
{	
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xF3;		//���ö�ʱ��ʼֵ
	TH1 = 0xF3;		//���ö�ʱ����ֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ


	while(1)
	{
		TI=1;
		printf("��������\n");		  //��ʹ��printf��putsʱ��Ӧ��TI=1
		if(TI==1)
		{
			TI=0;		
		}
		delay(1000);
	}



//	while(1)
//	{
//		SBUF='a';	//���������ַ�
//		SBUF=i;
//		if(TI==1)
//		{
//			TI=0;		
//		}
////		i++;		
//		delay(1000);
//	}
}



