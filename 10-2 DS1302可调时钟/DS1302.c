#include <REGX52.H>

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

// DS1302Ҫ��д��ʱ�ӣ��ٶ���������ʾ��LCD1602��

//д�ĵ�ַ��0x01���Ƕ��ĵ�ַ
#define DS1302_Second  0x80			   //д����
#define DS1302_Minute  0x82			   //д�����
#define DS1302_Hour    0x84			   //д��Сʱ
#define DS1302_Date    0x86			   //д����
#define DS1302_Month   0x88			   //д����
#define DS1302_Day     0x8a			   //д������
#define DS1302_Year    0x8c			   //д����
#define DS1302_WP      0x8e			   //�رձ���



signed char DS1302_Time[]={21,5,20,15,50,50,4};	  //�ꡢ�¡��ա�ʱ���֡��롢����



//��ʼ��
void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}
//д��ָ������Ա
void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;					//һ���������ڴ�ԼΪ1us�����Բ�Ҫ����ʱ
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;					//һ���������ڴ�ԼΪ1us�����Բ�Ҫ����ʱ
		DS1302_SCLK=0;
	}
	DS1302_CE=0;	 
}

//��������
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i,Data=0x00;
	Command|=0x01;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;					//һ���������ڴ�ԼΪ1us�����Բ�Ҫ����ʱ
		DS1302_SCLK=1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data=Data|(0x01<<i);}	   //������յ��ˣ��Ͱ�Data��1��Ҳ����Data���ǽ��յ�������		
	}
	DS1302_CE=0;
	DS1302_IO=0;	 	//д��һ��Ҫ��0����Ȼ�Ứ��
	return Data;
}

//������д�뵽DS1302
void DS1302_SetTime(void)
{	
	DS1302_WriteByte(DS1302_WP,0x00);	//�ر�д����						 //������������DS1302��ΪBCD�������������
	DS1302_WriteByte(DS1302_Year,DS1302_Time[0]/10*16+DS1302_Time[0]%10);	//д����   //Ҫת����BCD����ȥ
	DS1302_WriteByte(DS1302_Month,DS1302_Time[1]/10*16+DS1302_Time[1]%10);	//д����   //Ҫת����BCD����ȥ
	DS1302_WriteByte(DS1302_Date,DS1302_Time[2]/10*16+DS1302_Time[2]%10);	 //д����   //Ҫת����BCD����ȥ
	DS1302_WriteByte(DS1302_Hour,DS1302_Time[3]/10*16+DS1302_Time[3]%10);	 //д��Сʱ   //Ҫת����BCD����ȥ
	DS1302_WriteByte(DS1302_Minute,DS1302_Time[4]/10*16+DS1302_Time[4]%10);	 //д�����   //Ҫת����BCD����ȥ
	DS1302_WriteByte(DS1302_Second,DS1302_Time[5]/10*16+DS1302_Time[5]%10);	 //д����   //Ҫת����BCD����ȥ
	DS1302_WriteByte(DS1302_Day,DS1302_Time[6]/10*16+DS1302_Time[6]%10);	 //д������   //Ҫת����BCD����ȥ
	DS1302_WriteByte(0x8f,0x00);	//��д����					
}


//����DS1302������
void DS1302_ReadTime(void)
{
	unsigned char Temp;						//������ʱ��
	Temp=DS1302_ReadByte(DS1302_Year);      //�������Ѿ��Զ���1�ˣ���1�Ƕ���ָ��
	DS1302_Time[0]=Temp/16*10+Temp%16;		//DS1302ΪBCD�룬ȡ������Ҫ���ʮ������
	Temp=DS1302_ReadByte(DS1302_Month);      //�������Ѿ��Զ���1�ˣ���1�Ƕ���ָ��
	DS1302_Time[1]=Temp/16*10+Temp%16;		//DS1302ΪBCD�룬ȡ������Ҫ���ʮ������
	Temp=DS1302_ReadByte(DS1302_Date);      //�������Ѿ��Զ���1�ˣ���1�Ƕ���ָ��
	DS1302_Time[2]=Temp/16*10+Temp%16;		//DS1302ΪBCD�룬ȡ������Ҫ���ʮ������
	Temp=DS1302_ReadByte(DS1302_Hour);      //�������Ѿ��Զ���1�ˣ���1�Ƕ���ָ��
	DS1302_Time[3]=Temp/16*10+Temp%16;		//DS1302ΪBCD�룬ȡ������Ҫ���ʮ������
	Temp=DS1302_ReadByte(DS1302_Minute);      //�������Ѿ��Զ���1�ˣ���1�Ƕ���ָ��
	DS1302_Time[4]=Temp/16*10+Temp%16;		//DS1302ΪBCD�룬ȡ������Ҫ���ʮ������
	Temp=DS1302_ReadByte(DS1302_Second);      //�������Ѿ��Զ���1�ˣ���1�Ƕ���ָ��
	DS1302_Time[5]=Temp/16*10+Temp%16;		//DS1302ΪBCD�룬ȡ������Ҫ���ʮ������
	Temp=DS1302_ReadByte(DS1302_Day);      //�������Ѿ��Զ���1�ˣ���1�Ƕ���ָ��
	DS1302_Time[6]=Temp/16*10+Temp%16;		//DS1302ΪBCD�룬ȡ������Ҫ���ʮ������

}














