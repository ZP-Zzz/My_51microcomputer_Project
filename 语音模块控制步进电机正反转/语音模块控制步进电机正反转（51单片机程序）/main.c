#include <REGX52.H>
#include "delaytime10us.h"
#include "motorrun.h"

sbit key=P2^0;

void main()
{
	while(1)
	{
	    if(key==0)
		{
		 	MotorRun(4096/2,1,100);
		}
		else
		{
			MotorRun(4096/2,0,100);				//	nangle=4096ΪһȦ��	drct=0Ϊ��ʱ��ת����drct=1Ϊ˳ʱ��ת����  speedת��75`400��
		}
		delay(50000);		//ֹͣ  ��ʱ500ms
	}
}

