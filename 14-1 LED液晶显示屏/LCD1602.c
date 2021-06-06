#include <REGX52.H>
#include "delay.H" 

sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^7;

#define LCD_Datapart P0


void LCD_WriteCommand(unsigned char Command)	  //����д���õ�ָ��
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_Datapart=Command;
	LCD_E=1;	//������Ϊ���뼶��Ӧ����ʱһ�£���ȡ������
	delay(1);
	LCD_E=0;
	delay(1); 	//�½���Ϊ���뼶��Ӧ����ʱһ�£���ȡ������
}


void LCD_WriteData(unsigned char Data)				//�û������ַ�������
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_Datapart=Data;
	LCD_E=1;	//������Ϊ���뼶��Ӧ����ʱһ�£���ȡ������
	delay(1);
	LCD_E=0;
	delay(1); 	//�½���Ϊ���뼶��Ӧ����ʱһ�£���ȡ������	
}

void LCD_Init(void)
{
	LCD_WriteCommand(0x38);							//��ʼ������0x38  ��λ���ݽӿڣ�������ʾ��5*7����
	LCD_WriteCommand(0x0c);							//          0x0c  ��ʾ�������أ���˸��
	LCD_WriteCommand(0x06);							//          0x06  ���ݶ�д�����󣬹���Զ���1�����治��
	LCD_WriteCommand(0x01);							//          0x01  ����
													
												
}



																	  

//��ʾһ���ַ�-----------------------------------------------------------------------------------------------------
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char)	 
{
	 if(Line==1)
	 {
	 	 LCD_WriteCommand(0x80+(Column-1));	  //��ʾ�ַ�  0x80+��ַ ���ù��λ��(1000 0000��������һ����ַ���õ�ָ��)
	 }
	 if(Line==2)
	 {
	 	 LCD_WriteCommand(0x80+(Column-1)+0x40);  //��ʾ�ַ�  0x80|��ַ ���ù��λ��(1000 0000��������һ����ַ���õ�ָ��)
	 }
	 LCD_WriteData(Char);     //��ʾ�ַ�	//��������											   
											   
}





//�ַ�������-----------------------------------------------------------------------------------------------------
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char String[])  
{
	 unsigned char i;
	 if(Line==1)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1));	 
	 }
	 if(Line==2)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1)+0x40); 
	 }
	 for(i=0;String[i]!='\0';i++)	  //�������һλ��־λ'\0'�����������
	 {
	 	LCD_WriteData(String[i]);		 //��������
	 }
	
}


//x��y�η�����-----------------------------------------------------------------------------------------------------
int LCD_Pow(int X,int Y)
{
	 unsigned char i;
	 int result=1;
	 for(i=0;i<Y;i++)
	 {
	 	  result*=X;
	 }
	 return result;
}


//��ʾ����
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)  
{
	 unsigned char i;
	 if(Line==1)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1));	 
	 }
	 if(Line==2)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1)+0x40); 
	 }
	 for(i=Length;i>0;i--)
	 {													   //	 Number/100%10;	��		i=3		 10^(3-1)
		LCD_WriteData(0x30+Number/LCD_Pow(10,i-1)%10);	  //	 Number/10%10;	ʮ		i=2		 10^(2-1)
		//�����0x30��Ϊ�˵õ�����������ASCLL��ֵ		  //	 Number/1%10; 	��		i=1		 10^(1-1)
	 }
	
}




//��ʾ������������-----------------------------------------------------------------------------------------------------
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length)
{
	 unsigned char i;  
	 if(Line==1)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1));	 
	 }
	 if(Line==2)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1)+0x40); 
	 }
	 if(Number>=0)
	 {
	 	 LCD_WriteData('+');

	 }
	 else
	 {
	 	 LCD_WriteData('-');
		 Number=-Number;
	 }
	 for(i=Length;i>0;i--)
	 {													   //	 Number/100%10;	��		i=3		 10^(3-1)
		LCD_WriteData(0x30+Number/LCD_Pow(10,i-1)%10);	  //	 Number/10%10;	ʮ		i=2		 10^(2-1)
		//�����0x30��Ϊ�˵õ�����������ASCLL��ֵ		  //	 Number/1%10; 	��		i=1		 10^(1-1)
	 }
 }


//��ʾ16������-----------------------------------------------------------------------------------------------------
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	 unsigned char i,SingleNumber;  

	 if(Line==1)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1));	 
	 }
	 if(Line==2)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1)+0x40); 
	 }
	 for(i=Length;i>0;i--)
	 {	
	 	SingleNumber=Number/LCD_Pow(16,i-1)%16;
		if(SingleNumber<10)
		{
			LCD_WriteData(0x30+Number/LCD_Pow(16,i-1)%16); //�����0x30��Ϊ�˵õ�����������ASCLL��ֵ
		}												   
		else
		{
			LCD_WriteData('A'+SingleNumber-10);
		}	  
				
	  }
 }



//��ʾ2������-----------------------------------------------------------------------------------------------------
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	 unsigned char i;  
	 if(Line==1)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1));	 
	 }
	 if(Line==2)
	 {
	 	 LCD_WriteCommand(0x80|(Column-1)+0x40); 
	 }
	 for(i=Length;i>0;i--)
	 {													   
		LCD_WriteData(0x30+Number/LCD_Pow(2,i-1)%2);	
		//�����0x30��Ϊ�˵õ�����������ASCLL��ֵ		  
	 }
}

















