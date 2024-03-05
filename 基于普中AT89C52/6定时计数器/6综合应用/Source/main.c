#include <reg51.h>
#include "display.h"

void Timer0Init(void);
void EX0_Init(void);
void EX1_Init(void);
void display_service();
void Delay10ms();
long num = 0000;

void main()
{
	EX0_Init();
	EX1_Init();
	Timer0Init();
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
	LEDBUF[3] = num/1000%10;
	LEDBUF[2] = num/100%10;
	LEDBUF[1] = num/10%10;
	LEDBUF[0] = num%10;
}

void Timer0Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x66;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	ET0 = 1;         //�򿪶�ʱ�������ж�0
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}

void timer_ISR(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TR0 = 1;
}

void EX0_Init(void)
{
	IT0 = 1;//�½��ش���
	EX0 = 1;
}

void EX0_ISR(void) interrupt 0
{
	EX0 = 0;
	Delay10ms();
	num++;
	if(num > 9999)
		num = 0;
	EX0 = 1;
}

void EX1_Init(void)
{
	IT1 = 1;//�½��ش���
	EX1 = 1;
}

void EX1_ISR(void) interrupt 2
{
	EX1 = 0;
	Delay10ms()	;
	num--;
	if(num < 0)
		num = 9999;
	EX1 = 1;
}
void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}
