#include <reg51.h>
#include "I2C.h"
#include "display.h"
#include "E2PROM.h"
void Timer0_Init(void);		//1����@11.0592MHz
void display_service();
void Delay10ms();		//@11.0592MHz
unsigned char dat;
void main()
{

	Timer0_Init();
	dat = EEPReadByte(0x50,0x21);
	Delay10ms();
	dat = dat+1;
	EEPWriteByte(0x50,0x21,dat);
	Delay10ms();
	while(1)
	{
		display_service();
	}
}

void display_service()
{
	LEDBUF[7] = dat/16;
	LEDBUF[6] = dat%16;
}

void Timer0_Isr(void) interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;
}

void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
	EA = 1;
}


void Delay10ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 117;
	j = 184;
	do
	{
		while (--j);
	} while (--i);
}
