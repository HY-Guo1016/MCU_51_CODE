#include <reg51.h>
#include "E2PROM.h"
#include "I2C.h"
#include "display.h"
void display_service();
void Timer0_Init(void);
#define Timers_cnt 200
#define Start_E2PROM  0xAA

unsigned char buf[3];
unsigned int Count;

void main()
{
	Timer0_Init();
	EEPRead(0x50,0x00,buf,3);
	if(buf[0]!=Start_E2PROM)
	{
		buf[0] = Start_E2PROM;
		buf[1] = 1;
		buf[2] = 0;
	}
	else
	{
		buf[1]++;
		if(buf[1] == Timers_cnt)
		{
			buf[1] = 0;
			buf[2]++;
			if(buf[2]==Timers_cnt)
			{
				buf[1] = 1;
				buf[2] = 0;
			}
		}
	}
	EEPWrite(0x50,0x00,buf,3);
	Count = buf[2]*	Timers_cnt+buf[1];
	while(1)
	{
		display_service();
	}
}

void display_service()
{
	LEDBUF[3] = Count/1000;
	LEDBUF[2] = Count/100%10;
	LEDBUF[1] = Count/10%10;
	LEDBUF[0] = Count%10;
}

void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;
	EA =1;
	TR0 = 1;				//定时器0开始计时
}
void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TR0 = 1;
}