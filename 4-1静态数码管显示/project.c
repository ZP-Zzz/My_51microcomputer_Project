//#include <REGX52.H>
//void main()
//{
//
//	while(1)
//	{
//		P0=0x30;		//p0�ڹ涨�������֣��ߵ�ƽ�����͵�ƽ��
//		P2_4=1;			 //p2����138�������涨���ĸ�λ�õ��������
//		P2_3=0;
//		P2_2=0;	
//	}
//}


#include <REGX52.H>
unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //����ܵ�����

void NiXie(char Location,Number)	  //NiXieΪ�����,Location������һ�����������Number��������
{
	switch(Location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=shumaguan[Number];	
}



void main()
{
	while(1)
	{
		NiXie(3,3);
	}
}










