#include <REGX52.H>
#include "LCD1602.H"
#include "delay.H"  

 void main()
 {
 	LCD_Init();

 	while(1)
	{
		LCD_ShowChar(1,1,0x25);	 //��ʾ�ٷֺ�
//		LCD_ShowString(1,1,"123456");
//		LCD_ShowNum(1,1,123,4);
//		LCD_ShowSignedNum(1,1,-1000,6);
//		LCD_ShowHexNum(1,1,0x85,2);
//		LCD_ShowBinNum(1,1,0xa5,8);
//		LCD_ShowChar(1,1,0xdf);  //��ʾ�¶ȷ���
//		LCD_ShowChar(1,2,'C');  //��ʾ�¶ȷ���


//		LCD_ShowString(1,5,"HT  Love  ZP");
//	  	LCD_WriteCommand(0x18);		  //д������һλָ���Ϊ��while�����һֱִ������
//		delay(80);

	}
}