#include <reg51.h>
#include "display.h"

void Timer0Init(void);
void EX0_Init(void);
void EX1_Init(void);
void display_service();
void Delay10ms();
long num = 0000;

void main()
{
	EX0_Init();
	EX1_Init();
	Timer0Init();
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
	LEDBUF[3] = num/1000%10;
	LEDBUF[2] = num/100%10;
	LEDBUF[1] = num/10%10;
	LEDBUF[0] = num%10;
}

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	ET0 = 1;         //打开定时计数器中断0
	TR0 = 1;		//定时器0开始计时
}

void timer_ISR(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TR0 = 1;
}

void EX0_Init(void)
{
	IT0 = 1;//下降沿触发
	EX0 = 1;
}

void EX0_ISR(void) interrupt 0
{
	EX0 = 0;
	Delay10ms();
	num++;
	if(num > 9999)
		num = 0;
	EX0 = 1;
}

void EX1_Init(void)
{
	IT1 = 1;//下降沿触发
	EX1 = 1;
}

void EX1_ISR(void) interrupt 2
{
	EX1 = 0;
	Delay10ms()	;
	num--;
	if(num < 0)
		num = 9999;
	EX1 = 1;
}
void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}
