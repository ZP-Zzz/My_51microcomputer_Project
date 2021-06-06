#include <REGX52.H>
#include "delay.H" 
unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7F,0x39,0x3F,0x79,0x71};
void display(unsigned char i);
unsigned char Key(void);
unsigned char matrixkey();
void Key_Loop(void); 
void Init_time0(void);

unsigned char KeyNum,Key_KeyNumber;


void main()
{	
	Init_time0();
	while(1)
	{	
		KeyNum=Key();
		if(KeyNum)
		{
			display(KeyNum);
//			Nixie_SetBuf(2,KeyNum);
//			Nixie_SetBuf(3,KeyNum);
		}

	}
}

						


unsigned char matrixkey_GetState()		   //������̵�ѡ��
{
	unsigned char keynumber=0;	  
	P1_7=0;		   //��һ�и��ߵ�ƽ
	if(P1_3==0){keynumber=1;}	 //�жϵ�һ�еĵڼ���
	if(P1_2==0){keynumber=2;}
	if(P1_1==0){keynumber=3;}	  //��while�ж�ȥ�����¼�һ������Key_Loop���ö�ʱ��ÿ20ms����һ��
	if(P1_0==0){keynumber=4;}
	return keynumber;	
}


void Key_Loop(void)
{
	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=matrixkey_GetState();
	if(LastState==1&&NowState==0){Key_KeyNumber=1;}
	if(LastState==2&&NowState==0){Key_KeyNumber=2;}  
	if(LastState==3&&NowState==0){Key_KeyNumber=3;}  
	if(LastState==4&&NowState==0){Key_KeyNumber=4;}    
}

unsigned char Key(void)
{
	unsigned char Temp;
	Temp=Key_KeyNumber;
//	Key_KeyNumber=0;
	return Temp;
}



void display(unsigned char i)		 //����ܵ���ʾ
{
	P2_4=1;
	P2_3=1;
	P2_2=1;
	P0=shumaguan[i];
	delay(2);
	P2_4=1;									   
	P2_3=1;
	P2_2=0;
	P0=shumaguan[i];
	delay(2);															
	P2_4=1;
	P2_3=0;
	P2_2=1;
	P0=shumaguan[i];
	delay(2);
	P2_4=1;
	P2_3=0;							   
	P2_2=0;
	P0=shumaguan[i];								
	delay(2);	
}




void Init_time0(void)
{
 	TMOD |= 0x01;         
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
  	EA=1;             //���жϴ�
  	ET0=1;            //��ʱ��T0�����ж�
  	TR0=1;            //��ʱ��T0��ʼ����
}




void Interrupt_handler_time0(void) interrupt 1
{
	static unsigned int T0count1;    //�޷���intΪ0~65535
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
   	T0count1++;
	if(T0count1>=20)
	{
		T0count1=0;
		Key_Loop();	
	}

}













