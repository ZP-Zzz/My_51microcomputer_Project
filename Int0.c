#include <REGX52.H>

void Int0_Init(void)
{
	IT0=1;		  //�ⲿ�жϴ�������ʽ  1Ϊ�½��� 0Ϊ�͵�ƽ
	IE0=0;		  //�ⲿ�ж������־λ�������жϣ��Զ���1��
	EX0=1;		  //�ⲿ�ж�����λ
	EA=1;		  //���ж�
	PX0=1;		  //�ж����ȼ�
	
}




/* 
void Int0_Routine(void) interrupt 0
{
	Num++;	
}
*/
