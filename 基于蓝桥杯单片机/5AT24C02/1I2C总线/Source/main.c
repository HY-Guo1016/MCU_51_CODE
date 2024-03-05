#include <reg51.h>
#include "I2C.h"
#include "display.h"
#include "E2PROM.h"
void Timer0_Init(void);		//1毫秒@11.0592MHz
void display_service();
void Delay10ms();		//@11.0592MHz
unsigned char dat;
void main()
{

	Timer0_Init();
	dat = EEPReadByte(0x50,0x21);
	Delay10ms();
	dat = dat+1;
	EEPWriteByte(0x50,0x21,dat);
	Delay10ms();
	while(1)
	{
		display_service();
	}
}

void display_service()
{
	LEDBUF[7] = dat/16;
	LEDBUF[6] = dat%16;
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


void Delay10ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 117;
	j = 184;
	do
	{
		while (--j);
	} while (--i);
}
