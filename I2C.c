#include <REGX52.H>


sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;


//�����ź�
void I2C_Start(void)
{
	I2C_SCL=1;
	I2C_SDA=1;
	I2C_SDA=0;
	I2C_SCL=0;
}



//ֹͣ�ź�
void I2C_Stop(void)
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
}




//����һ���ֽ�
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}

//����һ���ֽ�
unsigned char I2C_ReceiveByte(void)
{
	unsigned char i,Byte;
	I2C_SDA=1;    //�����ڽ���֮ǰ����Ҫ�ͷ�SDA����1
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA){Byte=Byte|(0x80>>i);}
		I2C_SCL=0;
	}
	return Byte;
}



//����Ӧ���ź�
void I2C_SendAck(unsigned char AckByte)   //Ӧ��һλ0��1  0ָӦ��1ָ��Ӧ��
{
	I2C_SDA=AckByte;
	I2C_SCL=1;
	I2C_SCL=0;
}



//����Ӧ���ź�
unsigned char I2C_ReceiveAck(void)
{
	unsigned char AckBit;
	I2C_SDA=1;               //�����ڽ���֮ǰ����Ҫ�ͷ�SDA����1
	I2C_SCL=1;
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return 	AckBit;
}













