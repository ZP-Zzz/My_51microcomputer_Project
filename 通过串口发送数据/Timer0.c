#include <REGX52.H>
//�ж�һ����������ȷ�������أ��簴���������Ĳ���ʱ�źŵȡ�
//��ʱ��0��ʼ����1����
void Timer0Init(void)		//1����@12.000MHz
{

	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0=1;          //�ж��������     	  ������T0�жϣ�
	EA=1;           //						  �������жϣ�
	PT0=0;			//���ȼ�����             ���ͼ������ȼ�����Ĭ��Ҳ�ǵͼ���
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

//�������������

/*
unsigned char Counter,Compare,Key,Speed,i;		  //����ռ�ձ�ֻҪ����Compare��ֵ�Ϳ���
sbit Motor=P1^0;

void main()
{
	Timer0Init();

	while(1)
	{
		Key=matrixkey();
		if(Key==1)
		{
			Speed++;
			if(Speed==4)
				Speed=0;
			if(Speed==0){Compare=0;}
			if(Speed==1){Compare=50;}
			if(Speed==2){Compare=70;}
			if(Speed==3){Compare=100;}
		}
		Nixie(1,Speed);	
	} 
	
}
//100΢��Ķ�ʱ��0
void Timer0_Routine() interrupt 1	//����T0��������������ʲô(�ж��ӳ���)
{
	TL0 = 0x9C;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	Counter++;
	if(Counter>=100)
		Counter=0;
	if(Counter<Compare)
	{
		Motor=1;			  //��1ת
	}
	else
	{
		Motor=0;
	}

}












*/