#include <REGX52.H>
//�ж�һ����������ȷ�������أ��簴���������Ĳ���ʱ�źŵȡ�
//��ʱ��0��ʼ����1����
void Timer0Init(void)		//1����@12.000MHz
{

	TMOD &= 0xF0;	//���ö�ʱ��ģʽ
	TMOD |= 0x01;	//���ö�ʱ��ģʽ
	TL0 = 0;		//���ö�ʱ��ʼֵ0
	TH0 = 0;		//���ö�ʱ��ʼֵ0
	TF0 = 0;		//���TF0��־
	TR0 = 0;		//��ʱ��0����ʼ��ʱ
}

void Timer0_SetCounter(unsigned int Value)	 //����ʱ����ֵ
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned int Timer0_GetCounter(void)	  //��ʱʱ��
{
	return (TH0<<8)|TL0;
}


void Timer0_Run(unsigned int Flag)		 //�Ƿ�����ʼ��ʱ
{
	TR0 = Flag;	
}






//1��=1000����ms=1000 000΢���s

/*��ʱ���жϺ���ģ�壨�Ƶ�һ����˸��
void Timer0_Routine() interrupt 1	//����T0��������������ʲô(�ж��ӳ���)
{
	static unsigned int T0count;    //�޷���intΪ0~65535
	TL0 = 0x18;			//���¸���ֵ�������ٴ�64535��ʼ	
	TH0 = 0xFC;
	T0count++;
	if(T0count>=1000)
	{
		T0count=0;
		P2_0=~P2_0;	
	}

}
*/

