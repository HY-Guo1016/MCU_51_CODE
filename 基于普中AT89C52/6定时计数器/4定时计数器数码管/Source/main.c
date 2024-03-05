#include <reg51.h>
#include "display.h"

void Timer0Init(void);
void display_Service();

unsigned int system_timer = 50000;
unsigned long num = 12345678;
unsigned int system_flag = 5000;
void main()
{
	Timer0Init();
	do
	{
		
	}while(system_flag>0);
	while(1)
	{
		display_Service();
	}
}

void display_Service()
{
	LEDBUF[7] = num/10000000%10;
	LEDBUF[6] = num/1000000%10;
	LEDBUF[5] = num/100000%10;
	LEDBUF[4] = num/10000%10;
	LEDBUF[3] = num/1000%10;
	LEDBUF[2] = num/100%10;
	LEDBUF[1] = num/10%10;
	LEDBUF[0] = num%10;
}
void Timer0Init(void)		//1毫秒@12.000MHz
{

	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	ET0 = 1;
	EA = 1;
	TR0 = 1;		//定时器0开始计时
}

void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	if(system_flag > 0)
		system_flag--;
	display();
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TR0 = 1;

}