#include <reg51.h>
#include <stdio.h>
#include "DS18B20.h"
#include "display.h"
#include "delay.h"
#include "OneWire.h"
#include "UART.h"

void Timer0_Init(void);		//1毫秒@11.0592MHz


unsigned char flag = 0;

void main()
{
	bit ack;
	int temp;
	float tmp;
	Timer0_Init();
	UartInit();
	Start18B20();
	while(1)
	{
		Start18B20();
		if(flag)//1s更新一次温度
		{
			flag = 0;
			ack = Read18B20(&temp);
			if(!ack)
			{
				if(temp < 0)//当温度为负数
				{
//					LEDBUF[7] = 22;
					temp = ~temp;
					temp = temp +1;
					tmp = temp;
					temp = tmp*0.0625*100;//两位小数
				}
				else
				{	
//					LEDBUF[7] = 23;
					tmp = temp;
					temp = tmp * 0.0625 * 100;
				}
//				
//				if(temp >= 10000)
//					LEDBUF[6] = temp/10000;
//				else
//					LEDBUF[6] = 23;
//				if(temp >= 1000)
//					LEDBUF[5] = temp/1000;
//				else
//					LEDBUF[5] = 23;
//				LEDBUF[4] = temp/100%10;//个位
//				LEDBUF[3] = temp/10%10;//小数位
//				LEDBUF[2] = temp%10;//小数位
			}
		}
		ET0 = 0;
		tmp = temp*0.01;
		printf("Temp=%f\r\c",tmp);
		ET0 = 1;
		Delayxms(10000);
	}
	
}

void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//定时器0开始计时
}



void Timer0_ISR() interrupt 1
{
	static unsigned char Timer0Cnt;
	TR0 = 0;
	display();
	Timer0Cnt++;
	if(Timer0Cnt==100)
	{
		Timer0Cnt = 0;
		flag = 1;
	}
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TR0 = 1;
}