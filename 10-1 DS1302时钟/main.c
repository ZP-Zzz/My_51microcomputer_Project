#include <REGX52.H>
#include "LCD1602.H"
#include "DS1302.H"
#include "delay.H"
 
void main()
{
	LCD_Init();
	DS1302_Init();
	DS1302_SetTime();	   //ֻ��Ҫ��һ�Σ�����б��õ�Դ������ͻ��Լ���ʼ��
	LCD_ShowString(1,3,"-");
	LCD_ShowString(1,6,"-");
	LCD_ShowString(2,3,"-");
	LCD_ShowString(2,6,"-");

	while(1)
	{
		DS1302_ReadTime();	  //����while��һֱ����
		LCD_ShowNum(1,1,DS1302_Time[0],2);		  //��
		LCD_ShowNum(1,4,DS1302_Time[1],2);		  //��
		LCD_ShowNum(1,7,DS1302_Time[2],2);		  //��
		LCD_ShowNum(2,1,DS1302_Time[3],2);		  //ʱ
		LCD_ShowNum(2,4,DS1302_Time[4],2);		  //��
		LCD_ShowNum(2,7,DS1302_Time[5],2);		  //��
	}
}

















