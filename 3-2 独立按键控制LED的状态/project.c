#include <REGX52.H>


void Delayms(int ms)		//@12.000MHz
{
	unsigned char i, j;
	while(ms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		ms--;
	}
}



void main()
{
	while(1)
	{
		if(P3_1==0)				 //�жϰ����İ���
		{
			Delayms(100);   //�������� һ���Լ100ms
			if(P3_1==0)	 //�ٴ��жϰ����Ƿ���
				{
					P2_0=~P2_0;	  //led״̬ȡ��
				}
			while(P3_1==1)				   //��ⰴ���Ƿ��ɿ�
		 		{
					continue;
				}
		}	
	}
}