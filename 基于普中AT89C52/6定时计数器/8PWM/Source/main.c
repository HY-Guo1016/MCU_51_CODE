#include <reg51.h>
#include <intrins.h>

sbit PWM_LED = P2^2;
void Timer0Init();
void EX0_init();
void Delay1000ms();
unsigned char PWM_pro = 0;
unsigned char PWM_cnt = 100;
unsigned char key_cnt = 0;
void main()
{
	Timer0Init();
	EX0_init();
	while(1)
	{
		
	}
}


void Timer0Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	PWM_cnt--;
	if(PWM_cnt == 0)
	{
		PWM_cnt = 100;//定时10毫秒
	}
	
	
	if(PWM_cnt >= PWM_pro)
	{
		PWM_LED = 1;
	}
	else
	{
		PWM_LED = 0;
	}
	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TR0 = 1;
}

void EX0_init()
{
	EX1 = 1;
}

void EX1_ISR(void) interrupt 2
{
	Delay1000ms();

	key_cnt++;
	if(key_cnt > 6)
		key_cnt = 0;
	switch(key_cnt)
	{
		case 1:PWM_pro = 0;break;
		case 2:PWM_pro = 20;break;
		case 3:PWM_pro = 40;break;
		case 4:PWM_pro = 60;break;
		case 5:PWM_pro = 80;break;
		case 6:PWM_pro = 100;break;
		default:break;
	}

}
void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
