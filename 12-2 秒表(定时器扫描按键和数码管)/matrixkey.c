#include <REGX52.H>
#include "DELAY.H" 
unsigned char Key_KeyNumber;



unsigned char Key(void)
{
	unsigned char Temp;
	Temp=Key_KeyNumber;
//	Key_KeyNumber=0;
	return Temp;
}



unsigned char matrixkey_GetState()
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













