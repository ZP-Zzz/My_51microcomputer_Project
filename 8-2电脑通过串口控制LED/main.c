#include <REGX52.H>
#include "DELAY.H"
#include "UART.H" 


void main()
{
	UART_Init();
	while(1)
	{

	}
}

void UART_Routine() interrupt 4
{
	 if(RI==1)    //RIΪ�����жϱ�־λ
	 {	
	 	P2=SBUF;				//������Ƭ�����͵ı���
		UART_SendByte(SBUF);	//��Ƭ������Է����ֽ�
		RI=0;
	 }
}






