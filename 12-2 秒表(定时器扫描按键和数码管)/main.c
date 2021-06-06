#include <REGX52.H>
#include "delay.H"
#include "matrixkey.H"
#include "Timer0.H"
#include "Nixie.H"

unsigned char KeyNum;
unsigned char Temp;

void main()
{
	Timer0Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Nixie_SetBuf(1,KeyNum);
			Nixie_SetBuf(2,KeyNum);
			Nixie_SetBuf(3,KeyNum);
		}
	}  
}



void Timer0_Routine() interrupt 1	//����T0��������������ʲô(�ж��ӳ���)
{
	static unsigned int T0count1,T0count2;    //�޷���intΪ0~65535
	TL0 = 0x18;			//���¸���ֵ�������ٴ�64535��ʼ	
	TH0 = 0xFC;
	T0count1++;
	if(T0count1>=20)
	{
		T0count1=0;
		Key_Loop();	
	}
	T0count2++;
	if(T0count2>=2)
	{
		T0count2=0;
		Nixie_Loop();	
	}

}










