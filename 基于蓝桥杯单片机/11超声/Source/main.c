#include <reg51.h>
#include "CX20106A.h"
#include "display.h"

void Timer0_Init(void);
void Timer1_Init(void);		//1����@11.0592MHz
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
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0;				//���ö�ʱ��ʼֵ
	TH0 = 0;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
}

void disp_ser()
{
	LEDBUF[7] = Dist/10000;
	LEDBUF[6] = Dist/1000%10;
	LEDBUF[5] = Dist/100%10;
	LEDBUF[4] = Dist/10%10;
	LEDBUF[3] = Dist%10;
}

void Timer1_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ
	TL1 = 0x66;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	ET1 = 1;
	EA = 1;
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
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
	TL1 = 0x66;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
	TR1 = 1;
}
