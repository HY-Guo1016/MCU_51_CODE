#include "time.h"

unsigned char Timer_Start = 0;
unsigned char Timer_Rec_Cnt = 0;
void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
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
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}