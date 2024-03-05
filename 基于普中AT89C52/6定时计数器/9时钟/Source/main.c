#include <reg51.h>
#include "display.h"

void Timer1Init(void);
void Timer0Init(void);
void ShowNormal();
void ShowSec();
void ShowMin();
void ShowHou();
void EX0_Init(void);
void EX1_Init(void);

unsigned char TimerCnt;
unsigned char Sec;
unsigned char Min;
unsigned char Hou;
unsigned char state;

void main()
{
	Timer1Init();
	Timer0Init();
	EX0_Init();
	EX1_Init();
	EA = 1;
	while(1)
	{
		switch(state)
		{
			case 0:ShowNormal();break;
			case 1:ShowSec();break;
			case 2:ShowMin();break;
			case 3:ShowHou();break;
			default:break;
		}
	}
}

void Timer0Init(void)		//50毫秒@11.0592MHz
{

	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x00;		//设置定时初始值
	TH0 = 0x4C;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	ET0 = 1;
	TR0 = 1;		//定时器0开始计时
}


void Timer1Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x66;		//设置定时初始值
	TH1 = 0xFC;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	ET1 = 1;
	TR1 = 1;		//定时器1开始计时
}

void EX0_Init(void)
{
	IT0 = 1;
	EX0 = 1;
}

void EX1_Init(void)
{
	IT1 = 1;
	EX1 = 1;
}
void ShowNormal()
{
	LEDBUF[7] = Hou/10;
	LEDBUF[6] = Hou%10;
	LEDBUF[5] = 22;
	LEDBUF[4] = Min/10;
	LEDBUF[3] = Min%10;
	LEDBUF[2] = 22;
	LEDBUF[1] = Sec/10;
	LEDBUF[0] = Sec%10;
}

void ShowSec()
{
	LEDBUF[7] = 23;
	LEDBUF[6] = 23;
	LEDBUF[5] = 22;
	LEDBUF[4] = 23;
	LEDBUF[3] = 23;
	LEDBUF[2] = 22;
	LEDBUF[1] = Sec/10;
	LEDBUF[0] = Sec%10;
}

void ShowMin()
{
	LEDBUF[7] = 23;
	LEDBUF[6] = 23;
	LEDBUF[5] = 22;
	LEDBUF[4] = Min/10;
	LEDBUF[3] = Min%10;
	LEDBUF[2] = 22;
	LEDBUF[1] = 23;
	LEDBUF[0] = 23;
}
void ShowHou()
{
	LEDBUF[7] = Hou/10;
	LEDBUF[6] = Hou%10;
	LEDBUF[5] = 22;
	LEDBUF[4] = 23;
	LEDBUF[3] = 23;
	LEDBUF[2] = 22;
	LEDBUF[1] = 23;
	LEDBUF[0] = 23;
}
void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	TimerCnt++;
	if(TimerCnt >= 20)
	{
		TimerCnt = 0;
		Sec++;
		if(Sec >= 60)
		{
			Sec = 0;
			Min++;
			if(Min >= 60)
			{
				Min = 0;
				Hou++;
				if(Hou >= 24)
					Hou =0;
			}
		}
	}
	TL0 = 0x00;		//设置定时初始值
	TH0 = 0x4C;		//设置定时初始值
	TR0 = 1;

}
void timer1_ISR(void) interrupt 3
{
	TR1 = 0;
	TL1 = 0x66;		//设置定时初始值
	TH1 = 0xFC;		//设置定时初始值
	display(); 
	TR1 = 1;
}

void EX0_ISR() interrupt 0
{
	
	TR0 = 0;
	state++;
	if(state > 3)
	{
		state = 0;
		TR0 = 1;
	}

}

void EX1_ISR(void) interrupt 2
{
	switch(state)
	{
		case 1:
			Sec++;
			if(Sec >= 60)
				Sec = 0;
			break;
		case 2:
			Min++;
			if(Min >= 60)
				Min = 0;
			break;
		case 3:
			Hou++;
			if(Hou >= 60)
				Hou = 0;
			break;	
		default:break;
	}
}