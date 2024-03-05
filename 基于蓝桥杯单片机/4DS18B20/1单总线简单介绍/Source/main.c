#include <reg51.h>
#include "OneWire.h"
#include "display.h"
#include "delay.h"

void Timer0_Init(void);		//100΢��@11.0592MHz
void main()
{	
	unsigned char ack;
	Delayxms(10);
	Timer0_Init();
	ack = OneWireRst();
	while(1)
	{
		LEDBUF[7] = 23;
		LEDBUF[6] = 23;
		LEDBUF[5] = 23;
		LEDBUF[4] = 23;
		LEDBUF[3] = 23;
		LEDBUF[2] = 23;
		LEDBUF[1] = 23;
		LEDBUF[0] = ack;
	}
}
void Timer0_Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0xA4;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}
void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	
	display();
	TL0 = 0xA4;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	TR0 = 1;
}
