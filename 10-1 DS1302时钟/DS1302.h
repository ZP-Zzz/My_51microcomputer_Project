
#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_Init(void);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_WriteByte(unsigned char Command,Data);
void DS1302_ReadTime(void);
void DS1302_SetTime(void);
extern unsigned char DS1302_Time[];	  //�ꡢ�¡��ա�ʱ���֡��롢����


#endif