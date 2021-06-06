#include <REGX52.H>
#include "Timer0.H" 
#include "KEY.H"
#include <INTRINS.H>

unsigned char KeyNum,LEDMode;  
void main()
{
	P2=0xfe;
	Timer0Init();		   
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			if(KeyNum==1)
			{	
				LEDMode++;
				if(LEDMode>=2)LEDMode=0;
			}
		}		
	}
}


void Timer0_Routine() interrupt 1	//����T0��������������ʲô(�ж��ӳ���)
{
	static unsigned int T0count;
	TL0 = 0x18;			//���¸���ֵ�������ٴ�64535��ʼ	
	TH0 = 0xFC;
	T0count++;
	if(T0count>=500)
	{
		T0count=0;
		if(LEDMode==0)P2=_crol_(P2,1);
		if(LEDMode==1)P2=_cror_(P2,1);	
	}

}





//void Timer0Init(void)		//1����@12.000MHz
//{
//
//	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
//	TMOD |= 0x01;		//���ö�ʱ��ģʽ
//	TL0 = 0x18;		//���ö�ʱ��ʼֵ
//	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
//	TF0 = 0;		//���TF0��־
//	TR0 = 1;		//��ʱ��0��ʼ��ʱ
//	ET0=1;          //�ж��������     	  ������T0�жϣ�
//	EA=1;           //						  �������жϣ�
//	PT0=0;			//���ȼ�����             ���ͼ������ȼ�����Ĭ��Ҳ�ǵͼ���
//}




