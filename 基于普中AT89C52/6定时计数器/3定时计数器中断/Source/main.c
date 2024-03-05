#include <reg51.h>



void Timer0Init(void);

unsigned char timercnt = 20;


sbit LED = P2^0;
void main()
{
	Timer0Init();
	while(1);
}

void Timer0Init(void)		//50����@12.000MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xB0;		    //���ö�ʱ��ʼֵ
	TH0 = 0x3C;		    //���ö�ʱ��ʼֵ
	TF0 = 0;	    	//���TF0��־
	ET0 = 1;
	EA = 1;
	TR0 = 1;		    //��ʱ��0��ʼ��ʱ
}

void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	timercnt--;
	if(!timercnt)
	{
		timercnt = 20;
		LED = ~LED;
	}
	TR0 = 1;
}