#include <REGX52.H>
void Delayms(int ms)		//@12.000MHz
{
	while(ms)
	{
		unsigned char i, j;	
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
		if(P3_1==0)
		{
			Delayms(20);
			while(P3_1==0);
			Delayms(20);
			//��ʱ��P2Ϊ1111 1111ȫ��
			P2--;   //ÿ�μ�һ
		}	
	}
}
