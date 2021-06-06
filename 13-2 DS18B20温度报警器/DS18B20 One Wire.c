#include <REGX52.H>


sbit OneWire_PQ=P3^7;

//��ʼ��
unsigned char OneWire_Init(void)	
{	
	unsigned char i,AckBit;			//AckBitΪӦ��λ
	EA=0;										/*EA�жϵĴ򿪺͹ر���Ҫ��Ϊ��ʹ��ʱ�����������ݴ������ʱ*/				   
	OneWire_PQ=1;
	OneWire_PQ=0;
	i = 247;while (--i);		//��ʱ500us
	OneWire_PQ=1;
	i = 32;while (--i);			//��ʱ70us(15-60us)
	AckBit=	OneWire_PQ;		   //Ӧ������ݸ�Ӧ��λ
	i = 247;while (--i);		//��ʱ500us
	EA=1;
	return  AckBit;			   //�ӻ��������Ӧ�˾���0��û�и�����1
}


//����һλ
void OneWire_SendBit(unsigned char Bit)
{   
	unsigned char i;
	EA=0;
	OneWire_PQ=0;
	i = 4;while (--i);	  //��ʱ13us����
	OneWire_PQ=Bit;
	i = 24;while (--i);	  //��ʱ50us����
	OneWire_PQ=1;
	EA=1;
}

//����һλ
unsigned char OneWire_ReceiveBit(void)
{
	
	unsigned char Bite,i; 
	EA=0;
	OneWire_PQ=0;
	i = 2;while (--i);	   //5us����ʱ
	OneWire_PQ=1;
	i = 2;while (--i);	   //5us����ʱ
	Bite=OneWire_PQ;
	i = 24;while (--i);	  //��ʱ50us����
	EA=1;
	return Bite;
}



//����һ���ֽ�
void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&0x01<<i);
	}	
}



//����һ���ֽ�
unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit()){Byte=Byte|(0x01<<i);}
	}
	return Byte;	
}












