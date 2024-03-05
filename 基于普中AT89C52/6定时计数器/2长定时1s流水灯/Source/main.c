#include <reg51.h>
#include <intrins.h>
void timer0_Init();
unsigned int temp = 0xFE;
void main()
{
	unsigned char timer_cnt = 50;
	timer0_Init();
	while(1)
	{
		if(TF0 == 1)
		{
			TF0 = 0;
			TH0 = (65536 - 20000)/256;
			TL0 = (65536 - 20000)%256;
			timer_cnt--;
			if(timer_cnt == 0)
			{
			timer_cnt = 50;
			P2 = temp;
			temp = _crol_(temp,1);
			}
		}
	}

}

void timer0_Init()
{
	TMOD = 0x01;
	TH0 = (65536 - 20000)/256;
	TL0 = (65536 - 20000)%256;
	TR0 = 1;
}