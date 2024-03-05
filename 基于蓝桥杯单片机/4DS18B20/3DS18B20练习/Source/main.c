#include <reg51.h>
#include "OneWire.h"
#include "delay.h"
#include "DS18B20.h"
#include "display.h"

void Timer0_Init(void);

unsigned char Timer0Cnt;
unsigned char flag;

void main()
{
	int tmp;
	float temp;
	bit ack;
	Timer0_Init();
	Start18B20();
	while(1)
	{

		if(flag)
		{
			flag = 0;
			ack = Read18B20(&tmp);
			if(!ack)
			{
				if(tmp<0)
				{
					LEDBUF[7] = 22;
					tmp = ~tmp;
					tmp = tmp + 1;
					temp = tmp;
					tmp = temp*0.0625*100;//2位小数
				}
				else
				{
					LEDBUF[7] = 23;
					temp = tmp;
					tmp = temp*0.0625*100;//2位小数
				}
				if(tmp >= 10000)
					LEDBUF[6] = tmp/10000;
				else
					LEDBUF[6] = 23;//百位
				if(tmp>1000)
					LEDBUF[5] = tmp/1000;
				else
					LEDBUF[5] = 23;//十位
				//个位和小数点
				LEDBUF[4] = tmp/100%10;
				LEDBUF[3] = tmp/10%10;
				LEDBUF[2] = tmp%10;
				
			}
		}
		Start18B20();
	}
}

void Timer0_ISR(void) interrupt 1
{
	TR0 = 0;
	display();
	Timer0Cnt++;
	if(Timer0Cnt>100)
	{
		Timer0Cnt = 0;
		flag = 1;
	}
	
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TR0 = 1;
}

void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;				//使能定时器0中断
	EA = 1;
	TR0 = 1;				//定时器0开始计
}
