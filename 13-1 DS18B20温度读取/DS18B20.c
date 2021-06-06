#include <REGX52.H>
#include "LCD1602.H"
#include "DS18B20 One Wire.H"

//0xcc����ROMָ��
//0x44�¶�ת��ָ��
//0xbe��ָ��
//0x4eд�ݴ���ָ��
//0x48��TH��TL�����üĴ��������ݿ�����EEPROM		�����õ�ֵ����EEPROM��

void DS18B20_ConvertT(void)		//��ʼ�¶ȱ任	  PPT����
{
	OneWire_Init();
	LCD_ShowNum(1,14,OneWire_Init(),2);		//OneWire_Init()����ֵΪ0��ʾ�дӻ���Ӧ
	OneWire_SendByte(0xcc);
	OneWire_SendByte(0x44);
}


float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	int Temp1,Temp2;	 //TempҪ��16λ
	float T;	  
	OneWire_Init();
	OneWire_SendByte(0xcc);
	OneWire_SendByte(0xbe);
	TLSB=OneWire_ReceiveByte();
	TMSB=OneWire_ReceiveByte();
//	LCD_ShowBinNum(1,1,TMSB,8);
//	LCD_ShowBinNum(1,9,TLSB,8);
//	Temp=(TMSB<<8)|TLSB;
	Temp1=TMSB;			  //��TLSB��TMSBһ���ŵ�Temp��
	Temp2=Temp1<<8;
	Temp2=Temp2|TLSB;		  //�����еĹ���������һ��һ��Temp=(TMSB<<8)|TLSB;
	T=Temp2/16.0;
	return T;
}



















 