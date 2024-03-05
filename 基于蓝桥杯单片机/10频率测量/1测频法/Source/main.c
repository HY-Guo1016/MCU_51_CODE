#include <reg51.h>
#include "display.h"

void Timer0_Init(void);		//1����@11.0592MHz
void Timer1_Init(void);		//1����@11.0592MHz
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

void Timer1_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ
	TL1 = 0x66;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	ET1 = 1;
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
}

void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x05;			//���ö�ʱ��ģʽ
	TL0 = 0;				//���ö�ʱ��ʼֵ
	TH0 = 0;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
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
	TL1 = 0x66;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
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