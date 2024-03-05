#include <reg51.h>
#include "display.h"

void Timer0Init(void);		//1毫秒@12.000MHz
void Timer1Init(void);		//50毫秒@12.000MHz
void display_service();

unsigned char sec_cnt = 20;
unsigned char sec = 60;
void main()
{
	
	Timer0Init();
	Timer1Init();
	EA = 1;
	while(1)
	{
		display_service();
	}
}

void display_service()
{
	LEDBUF[7] = 23;
	LEDBUF[6] = 23;
	LEDBUF[5] = 23;
	LEDBUF[4] = 23;
	LEDBUF[3] = 23;
	LEDBUF[2] = 23;
	LEDBUF[1] = sec/10;
	LEDBUF[0] = sec%10;
	
}
void Timer0Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = (65536-1000)%256;		//设置定时初始值
	TH0 = (65536-1000)/256;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	ET0 = 1;
	TR0 = 1;		//定时器0开始计时
}



void Timer1Init(void)		//50毫秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = (65536-50000)%256;		//设置定时初始值
	TH1 = (65536-50000)/256;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	ET1 = 1;
	TR1 = 1;		//定时器1开始计时
}


void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TR0 = 1;

}

void timer1_ISR(void) interrupt 3
{
	TR1 = 0;
	sec_cnt--;
	if(sec_cnt == 0)
	{
		sec_cnt = 20;
		sec--;
		if(sec == 0)
		{
			sec = 60;
		}
	}
	TL1 = (65536-50000)%256;		//设置定时初始值
	TH1 = (65536-50000)/256;		//设置定时初始值
	TR1 = 1;

}