#include <reg51.h>
#include "CX20106A.h"
#include "display.h"

void Timer0_Init(void);
void Timer1_Init(void);		//1毫秒@11.0592MHz
void disp_ser();

unsigned int Dist;
unsigned char Timer1_cnt = 0;
unsigned char Timer_flag = 0;
void main()
{
	
	Timer0_Init();
	Timer1_Init();
	while(1)
	{
		if(Timer_flag)
		{
			Timer_flag = 0;
			WaveS();
			WaveR(&Dist);
		}
		disp_ser();
	}

}


void Timer0_Init(void)
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0;				//设置定时初始值
	TH0 = 0;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
}

void disp_ser()
{
	LEDBUF[7] = Dist/10000;
	LEDBUF[6] = Dist/1000%10;
	LEDBUF[5] = Dist/100%10;
	LEDBUF[4] = Dist/10%10;
	LEDBUF[3] = Dist%10;
}

void Timer1_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0x66;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	ET1 = 1;
	EA = 1;
	TR1 = 1;				//定时器1开始计时
}
void Timer1_ISR() interrupt 3
{
	TR1 = 0;
	Timer1_cnt++;
	if(Timer1_cnt==200)
	{
		Timer1_cnt = 0;
		Timer_flag = 1;
	}
	display();
	TL1 = 0x66;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TR1 = 1;
}
