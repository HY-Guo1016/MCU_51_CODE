#include "time.h"

unsigned char Timer_Start = 0;
unsigned char Timer_Rec_Cnt = 0;
void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//定时器0开始计时
}

void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	if(Timer_Start)
	{
		Timer_Rec_Cnt++;
		if(Timer_Rec_Cnt>5)
		{
			Rec_Flag = 1;
			Timer_Rec_Cnt = 0;
			Rec_cnt = 0;
			Timer_Start = 0;
		}
	}
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TR0 = 1;				//定时器0开始计时
}