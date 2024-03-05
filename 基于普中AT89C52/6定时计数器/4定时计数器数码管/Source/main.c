#include <reg51.h>
#include "display.h"

void Timer0Init(void);
void display_Service();

unsigned int system_timer = 50000;
unsigned long num = 12345678;
unsigned int system_flag = 5000;
void main()
{
	Timer0Init();
	do
	{
		
	}while(system_flag>0);
	while(1)
	{
		display_Service();
	}
}

void display_Service()
{
	LEDBUF[7] = num/10000000%10;
	LEDBUF[6] = num/1000000%10;
	LEDBUF[5] = num/100000%10;
	LEDBUF[4] = num/10000%10;
	LEDBUF[3] = num/1000%10;
	LEDBUF[2] = num/100%10;
	LEDBUF[1] = num/10%10;
	LEDBUF[0] = num%10;
}
void Timer0Init(void)		//1����@12.000MHz
{

	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	ET0 = 1;
	EA = 1;
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}

void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	if(system_flag > 0)
		system_flag--;
	display();
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TR0 = 1;

}