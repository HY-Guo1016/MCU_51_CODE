#include <reg51.h>
#include "DS1302.h"
#include "display.h"
void Timer0_Init(void);
void disp_service();
unsigned char TimerFlag = 0;
unsigned char TimerCnt=0;
void main()
{
	DS1302Init();
	Timer0_Init();
	while(1)
	{
		ReadTimer();
		disp_service();
	}
}

void Timer0_Init(void)		//1����@12.000MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}
void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	TimerCnt++;
	if(TimerCnt == 20)
	{
		TimerFlag = 1;
	}
	display();
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ

	TR0 = 1;
}

void disp_service()
{
	if(TimerFlag == 1)
	{
		TimerFlag = 0;
		LEDBUF[7] = DS1302Time[2]>>4;
		LEDBUF[6] = DS1302Time[2]&0x0F;
		LEDBUF[5] = 22;
		LEDBUF[4] = DS1302Time[1]>>4;
		LEDBUF[3] = DS1302Time[1]&0x0F;
		LEDBUF[2] = 22;
		LEDBUF[1] = DS1302Time[0]>>4;
		LEDBUF[0] = DS1302Time[0]&0x0F;
	}
}