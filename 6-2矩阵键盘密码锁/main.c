#include <REGX52.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "matrixkey.H"

int pass;
char NUM,count;
void main()
{

	LCD_Init();
	LCD_ShowString(1,1,"Pass world:");
	
	while(1)
	{
		NUM=matrixkey();
		if(NUM)
		{
			if(NUM<=10)		  //���1��10�İ�ť���£���������
			{
				if(count<4)		  //������λ�Ͳ�������
				{
					pass*=10;
					pass+=NUM%10;
					count++;	  //�ƴ�
				}
			}
			LCD_ShowNum(2,2,pass,4);
		

			if(NUM==11)	  //ȷ�ϼ�
			{
				 if(pass==1234)			//����������1234����ʾok
				 {
					LCD_ShowString(1,13,"OK ");
					pass=0;						  //��������
					count=0;					  //��������
					LCD_ShowNum(2,2,pass,4);	 //������ʾ
				 }
				 else
				 {
				 	LCD_ShowString(1,13,"err");	    
					pass=0;							//��������
					count=0;						//��������
					LCD_ShowNum(2,2,pass,4);	  //������ʾ
				 }
			}

			  if(NUM==12)
			  {
			   		pass=0;							//��������
					count=0;						//��������
					LCD_ShowNum(2,2,pass,4);	  //������ʾ	
			  }

		
		}

	}
}