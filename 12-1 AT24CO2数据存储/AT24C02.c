#include <REGX52.H>
#include "i2c.H"
#define	AT24C02_Address 0xa0   //Ĭ��д����0xa0


//д�ֽ�	WordAddressΪ0~255 
void AT24C02_WriteByte(unsigned char WordAddress,Data)		
{
	I2C_Start();					//��ʼ
	I2C_SendByte(AT24C02_Address);  //���ʹӻ���ַ��д
	I2C_ReceiveAck();				//����Ӧ��
	I2C_SendByte(WordAddress);      //�����ֵ�ַ
	I2C_ReceiveAck();				//����Ӧ��
	I2C_SendByte(Data);             //��������
	I2C_ReceiveAck();				//����Ӧ��
	I2C_Stop();						//����

}
 
//���ֽ�
unsigned char AT24C02_ReadByte(unsigned char WordAddress)		  
{
	unsigned char Data;
	I2C_Start();					//��ʼ
	I2C_SendByte(AT24C02_Address);  //���ʹӻ���ַ��д
	I2C_ReceiveAck();				//����Ӧ��
	I2C_SendByte(WordAddress);      //�����ֵ�ַ
	I2C_ReceiveAck();				//����Ӧ��
	I2C_Start();					//��ʼ
	I2C_SendByte(AT24C02_Address|0x01);  //���ʹӻ���ַ����	   ��Ϊ0xa1
	I2C_ReceiveAck();				//����Ӧ��
	Data=I2C_ReceiveByte();			 //��������
	I2C_SendAck(1);                  //������Ӧ��
	I2C_Stop();						//����
	return Data;	
}







