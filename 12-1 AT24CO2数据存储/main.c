#include <REGX52.H>
#include "delay.H" 
#include "LCD1602.H" 
#include "matrixkey.H"
#include "i2c.H"
#include "AT24C02.H"   

void main()
{
	unsigned char KeyNum;
	unsigned int Num;				   //16λ����
	LCD_Init();
	LCD_ShowNum(1,1,Num,5);
//	AT24C02_WriteByte(1,2);			//��һ����ַд��
//	delay(10);
////	AT24C02_WriteByte(2,3);			//��һ����ַд��
////	delay(10);
//	Data=AT24C02_ReadByte(2);		   //����һ����ַ������
//	LCD_ShowNum(2,1,Data,3);			//��ʾ��ַ�����ݣ����粻��ʧд������ݣ�
	while(1)
	{
		KeyNum=matrixkey();
		if(KeyNum==1)				    //���������1��Num++
		{
			Num++;
			LCD_ShowNum(1,1,Num,5);
		}
		if(KeyNum==2)					//���������2��Num--
		{
			Num--;
			LCD_ShowNum(1,1,Num,5);
		}
		if(KeyNum==3)					//���������3����Num�ĵͰ�λ����AT24C02
		{
			AT24C02_WriteByte(0,Num%256);  //ȡNum�ĵͰ�λ
			delay(5);
			AT24C02_WriteByte(1,Num/256);  //ȡNum�ĸ߰�λ
			delay(5);
			LCD_ShowString(2,1,"Write Ok");
			delay(1000);
			LCD_ShowString(2,1,"         ");
		}
		if(KeyNum==4)
		{
			Num=AT24C02_ReadByte(0);           //��0λ�õ�����
			Num|=AT24C02_ReadByte(1)<<8;
			LCD_ShowNum(1,1,Num,5);
			LCD_ShowString(2,1,"Read Ok");
			delay(1000);
			LCD_ShowString(2,1,"         ");

		}
	}
}

























