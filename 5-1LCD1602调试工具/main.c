#include <REGX52.H>
#include "LCD1602.H"
#include "delay.H"
void main()
{
	int NUM=0;
//	LCD_Init();   //�ϵ�֮ǰ��ʼ��һ��
//	LCD_ShowChar(1,1,'A');
//	LCD_ShowString(1,3,"HT LOVE YOU");    //���еڼ�����ʼ��ʾ�ַ���
//	LCD_ShowNum(2,2,123,3);
//	LCD_ShowHexNum(2,6,0xA8,2);		//��ʾʮ��������
//	LCD_ShowBinNum(2,9,0xA8,8);		//��ʾ��������
	LCD_Init();
	while(1)
	{				
	   
	   NUM++;
	   delay(10);
	   LCD_ShowNum(2,5,NUM,4);
	
			
	}
}