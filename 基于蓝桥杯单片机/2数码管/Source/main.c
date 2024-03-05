#include <reg51.h>
#include "display.h"

void Timer0_Init(void);
void display_Service();
void main()
{
	Timer0_Init();

	while(1)
	{
		display_Service();
	}
}

void display_Service()
{
	LEDBUF[7] = 7;
	LEDBUF[6] = 6;
	LEDBUF[5] = 5;
	LEDBUF[4] = 4;
	LEDBUF[3] = 3;
	LEDBUF[2] = 2;
	LEDBUF[1] = 1;
	LEDBUF[0] = 0;
}
void Timer0_Init(void)		//1����@11.0592MHz
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



void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;

}