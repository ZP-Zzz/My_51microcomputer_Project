#include <REGX52.H>
#include <INTRINS.H>



void delay(int ms)		//@12.000MHz
{
	while(ms)
	{
	 	unsigned char i, j;
		i = 2;
		j = 239;
		do
			{
				while (--j);
			} 
			while (--i);
		ms--;
	}	
}

void main()
{	
	while(1)
	{
		P2_1=0;	   //ֻ�����һ��1111 1110
		delay(20);  //��ʱ
		P2_1=~P2_1; //ȫ��1111 1111
		delay(20);  //��ʱ	
	}
}