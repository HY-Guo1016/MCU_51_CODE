#include <reg51.h>
#include "display.h"

void Timer0_Init(void);		//1毫秒@11.0592MHz
void Timer1_Init(void);		//1毫秒@11.0592MHz
void disp_service();

unsigned int TimerCnt=0;
unsigned int Freq;

void main()
{
	Timer0_Init();
	Timer1_Init();
	EA = 1;
	while(1)
	{
		
		disp_service();
	}	
	
		
}

void Timer1_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0x66;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	ET1 = 1;
	TR1 = 1;				//定时器1开始计时
}

void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x05;			//设置定时器模式
	TL0 = 0;				//设置定时初始值
	TH0 = 0;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
}
void Timer1_ISR() interrupt 3
{
	TR1 = 0;
	TimerCnt++;
	if(TimerCnt>=1000)
	{
		TR0 = 0;
		TimerCnt=0;
		Freq = TH0*256+TL0;
		TH0 = 0;
		TL0 = 0;
		TR0 = 1;
	
	}
	display();
	TL1 = 0x66;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TR1 = 1;
}


void disp_service()
{
	
	LEDBUF[5] = Freq/10000;
	LEDBUF[4] = Freq/1000%10;
	LEDBUF[3] = Freq/100%10;
	LEDBUF[2] = Freq/10%10;
	LEDBUF[1] = Freq%10;
}