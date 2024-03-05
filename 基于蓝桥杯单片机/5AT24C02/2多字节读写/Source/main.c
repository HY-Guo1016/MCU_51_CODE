#include <reg51.h>
#include "I2C.h"
#include "display.h"
#include "E2PROM.h"
#include "delay.h"
void Timer0_Init(void);		//1����@11.0592MHz
void display_service();
unsigned char BUF[4];
unsigned char i=0;
void main()
{

	Timer0_Init();
	EEPRead(0x50,0x20,BUF,4);
	BUF[0]=BUF[0]+1;
	BUF[1]=BUF[1]+1;
	BUF[2]=BUF[2]+1;
	BUF[3]=BUF[3]+1;
	EEPWrite(0x50,0x20,BUF,4);
	while(1)
	{
		display_service();
	}
}

void display_service()
{
	LEDBUF[7] = BUF[3]/16;
	LEDBUF[6] = BUF[3]%16;
	LEDBUF[5] = BUF[2]/16;
	LEDBUF[4] = BUF[2]%16;
	LEDBUF[3] = BUF[1]/16;
	LEDBUF[2] = BUF[1]%16;
	LEDBUF[1] = BUF[0]/16;
	LEDBUF[0] = BUF[0]%16;
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
