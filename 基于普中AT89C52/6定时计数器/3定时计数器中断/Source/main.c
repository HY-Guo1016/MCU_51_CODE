#include <reg51.h>



void Timer0Init(void);

unsigned char timercnt = 20;


sbit LED = P2^0;
void main()
{
	Timer0Init();
	while(1);
}

void Timer0Init(void)		//50毫秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xB0;		    //设置定时初始值
	TH0 = 0x3C;		    //设置定时初始值
	TF0 = 0;	    	//清除TF0标志
	ET0 = 1;
	EA = 1;
	TR0 = 1;		    //定时器0开始计时
}

void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	timercnt--;
	if(!timercnt)
	{
		timercnt = 20;
		LED = ~LED;
	}
	TR0 = 1;
}