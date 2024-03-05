#include <STC15F2K60S2.H>
#include "UART.h"

void Timer0_Init(void);		//1毫秒@11.0592MHz
void main()
{
	UartInit();
	Timer0_Init();
	while(1)
	{
		if(Recv_flag)
		{
			Recv_flag=0;
			Start_Timer = 0;
			SendString(Recv_buf);
			clr_recv_buf();
		}
	}

}


void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;
	TR0 = 1;				//定时器0开始计时
}


void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	if(Start_Timer)
	{
		Recv_Timer_Cnt++;
		if(Recv_Timer_Cnt>5)
		{
			Recv_flag = 1;
			Recv_Timer_Cnt = 0;
			Recv_cnt = 0;
		}
	}
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TR0 = 1;

}