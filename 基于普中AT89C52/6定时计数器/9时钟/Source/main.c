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

void Timer0Init(void)		//50����@11.0592MHz
{

	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x00;		//���ö�ʱ��ʼֵ
	TH0 = 0x4C;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	ET0 = 1;
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}


void Timer1Init(void)		//1����@11.0592MHz
{
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x10;		//���ö�ʱ��ģʽ
	TL1 = 0x66;		//���ö�ʱ��ʼֵ
	TH1 = 0xFC;		//���ö�ʱ��ʼֵ
	TF1 = 0;		//���TF1��־
	ET1 = 1;
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
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
	TL0 = 0x00;		//���ö�ʱ��ʼֵ
	TH0 = 0x4C;		//���ö�ʱ��ʼֵ
	TR0 = 1;

}
void timer1_ISR(void) interrupt 3
{
	TR1 = 0;
	TL1 = 0x66;		//���ö�ʱ��ʼֵ
	TH1 = 0xFC;		//���ö�ʱ��ʼֵ
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