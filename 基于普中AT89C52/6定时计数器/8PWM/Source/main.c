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


void Timer0Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xA4;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
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
		PWM_cnt = 100;//��ʱ10����
	}
	
	
	if(PWM_cnt >= PWM_pro)
	{
		PWM_LED = 1;
	}
	else
	{
		PWM_LED = 0;
	}
	TL0 = 0xA4;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
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
