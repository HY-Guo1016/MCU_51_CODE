#include <reg51.h>

void timer0_Init();

sbit LED = P2^0;
void main()
{
	timer0_Init();
	while(1)
	{	if(TF0 == 1)
		{
		TF0 = 0;
		LED = ~LED;
		TH0 = (65536 - 50000)/256;
		TL0 = (65536 - 50000)%256;
		}
	}

}

void timer0_Init()
{
	TMOD = 0X01;//设定定时计数器0的工作方式1
	//设定初始定时时间
	TH0 = (65536 - 50000)/256;
	TL0 = (65536 - 50000)%256;
	//定时计数器开始工作
	TR0 = 1;
}