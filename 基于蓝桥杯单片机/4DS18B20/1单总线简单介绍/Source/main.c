#include <reg51.h>
#include "OneWire.h"
#include "display.h"
#include "delay.h"

void Timer0_Init(void);		//100微秒@11.0592MHz
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
void Timer0_Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//定时器0开始计时
}
void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	
	display();
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TR0 = 1;
}
