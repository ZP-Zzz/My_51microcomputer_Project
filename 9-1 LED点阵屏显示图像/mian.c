#include <REGX52.H>
#include "delay.H" 

sbit RCK=P3^5;		 //RCLK
sbit SCK=P3^6;		 //SRCLK
sbit SER=P3^4;		 //SER


//74HC595д���ֽڣ�����D�ڵƣ�
void _74HC595_WriteByte(unsigned char Byte)	   //���ֲ��������ֿ�ͷ�����ԼӸ��»���
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&0x80;  //��Byte�����λ��ֵ��SER
		SCK=1;			   //��������ʹSER���봫��
		SCK=0;			   //���㣬Ϊ�´���׼��
		Byte=Byte<<1;
	}
	RCK=1;				  //�Ѱ�λByte�����͵�IO��
	RCK=0;				  //����


}

//LieΪ�У�HangDataΪһ���еƵ���
void MatrixLED_ShowColumn(unsigned char Lie,HangData)
{
	_74HC595_WriteByte(HangData);
	P0=~(0x80>>Lie);	
}


void main()
{
	SCK=0;   //��ʼ������
	RCK=0;	  //��ʼ��������

	while(1)
	{
		unsigned char TableL[] = {0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3C,}; //Ц����HangData����
		unsigned char j;
		for(j=0;j<8;j++)		  //8��
		{
			MatrixLED_ShowColumn(j,TableL[j]);
			delay(1);			   //��Ӱ����
			P0=0xff;

		}		
	}
}