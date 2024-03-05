#include <reg51.h>
#include "display.h"

void Timer0Init(void);		//1����@12.000MHz
void Timer1Init(void);		//50����@12.000MHz
void display_service();

unsigned char sec_cnt = 20;
unsigned char sec = 60;
void main()
{
	
	Timer0Init();
	Timer1Init();
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
	LEDBUF[3] = 23;
	LEDBUF[2] = 23;
	LEDBUF[1] = sec/10;
	LEDBUF[0] = sec%10;
	
}
void Timer0Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = (65536-1000)%256;		//���ö�ʱ��ʼֵ
	TH0 = (65536-1000)/256;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	ET0 = 1;
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}



void Timer1Init(void)		//50����@11.0592MHz
{
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x10;		//���ö�ʱ��ģʽ
	TL1 = (65536-50000)%256;		//���ö�ʱ��ʼֵ
	TH1 = (65536-50000)/256;		//���ö�ʱ��ʼֵ
	TF1 = 0;		//���TF1��־
	ET1 = 1;
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
}


void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TR0 = 1;

}

void timer1_ISR(void) interrupt 3
{
	TR1 = 0;
	sec_cnt--;
	if(sec_cnt == 0)
	{
		sec_cnt = 20;
		sec--;
		if(sec == 0)
		{
			sec = 60;
		}
	}
	TL1 = (65536-50000)%256;		//���ö�ʱ��ʼֵ
	TH1 = (65536-50000)/256;		//���ö�ʱ��ʼֵ
	TR1 = 1;

}