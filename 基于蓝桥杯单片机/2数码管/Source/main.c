#include <reg51.h>
#include "display.h"

void Timer0_Init(void);
void display_Service();
void main()
{
	Timer0_Init();

	while(1)
	{
		display_Service();
	}
}

void display_Service()
{
	LEDBUF[7] = 7;
	LEDBUF[6] = 6;
	LEDBUF[5] = 5;
	LEDBUF[4] = 4;
	LEDBUF[3] = 3;
	LEDBUF[2] = 2;
	LEDBUF[1] = 1;
	LEDBUF[0] = 0;
}
void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//定时器0开始计时
}



void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TR0 = 1;

}