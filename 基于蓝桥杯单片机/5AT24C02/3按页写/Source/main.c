#include <reg51.h>
#include "I2C.h"
#include "display.h"
#include "E2PROM.h"
#include "delay.h"
void Timer0_Init(void);		//1毫秒@11.0592MHz
void display_service();
unsigned char BUF[8];
unsigned char i=0;
void main()
{

	Timer0_Init();
	EEPRead(0x50,0x20,BUF,8);
	for(i=0;i<sizeof(BUF);i++)
	{
		BUF[i] = BUF[i]+1;
	}
	E2PROMWritePage(0x50,0x20,BUF,8);
	while(1)
	{
		display_service();
	}
}

void display_service()
{
	LEDBUF[7] = BUF[7]%16;
	LEDBUF[6] = BUF[6]%16;
	LEDBUF[5] = BUF[5]%16;
	LEDBUF[4] = BUF[4]%16;
	LEDBUF[3] = BUF[3]%16;
	LEDBUF[2] = BUF[2]%16;
	LEDBUF[1] = BUF[1]%16;
	LEDBUF[0] = BUF[0]%16;
}

void Timer0_Isr(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TR0 = 1;
}

void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
	EA = 1;
}
