#include <REGX52.H>
#include "timer0.h"
#include "Uart.h"

sbit SG_PWM=P0^0;							//�źſ�������
unsigned char count=0;					     //�ƴ�  ����ֵΪ0
unsigned char PWM_count=0;                  //0--0�ȣ�2--45�ȣ�4--90�ȣ�6--135�ȣ�8--180��

void main()
{
  Timer0_Init();
  Uart_Init();
  while(1)
  {
//	  if(P1_0==0)PWM_count=0;	  //���ת��0��
//	  if(P1_1==0)PWM_count=2;	  //���ת��45��
//    if(P1_2==0)PWM_count=4;	  //���ת��90��
//	  if(P1_3==0)PWM_count=6;else PWM_count=0;	  //���ת��135��			(else PWM_count=0;�����ֻ��������һ���ϣ������и���)
//	  if(P1_4==0)PWM_count=8;	  //���ת��180��
   }
}

void Timer0() interrupt 1      //�ر�ע��˴���0--�ⲿ�ж�0��1--��ʱ���ж�0��2--�ⲿ�ж�1��3--��ʱ���ж�1��4--���п��ж�1
{
  TR0=0;
  TL0 = 0x33;		
  TH0 = 0xFF;			 //���¸�������ֵΪ0.5ms
  

  if(count<=PWM_count)
  {									
    SG_PWM=1;
  }
  else
  {
    SG_PWM=0;
  }
  count++;						  //�ƴΣ�ÿ0.5�����1
  if(count>=40)
  {
    count=0;
  }
  TR0=1;
}
void UART_Routine()  interrupt 4
{	
	if(RI==1)
	{	
	  P1 =SBUF;					   //���͵�����SBUF������P2
	 if(P1==0X01)				   //0x01���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=0;
	 }
	 if(P1==0X02)				   //0x02���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=1;
	 }
	 if(P1==0X03)				   //0x03���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=2;
	 }
	 if(P1==0X04)				   //0x03���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=3;
	 }
	 if(P1==0X05)				   //0x03���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=4;
	 }
	 if(P1==0X06)				   //0x03���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=5;
	 }
	 if(P1==0X07)				   //0x03���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=6;
	 }
	 if(P1==0X08)				   //0x03���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=7;
	 }
	 if(P1==0X09)				   //0x03���ֵ����ͨ�������������༭ģʽ����
	 {
	   PWM_count=8;
	 }

	  RI=0;
	}
}
