#include <reg51.h>
#include <stdio.h>
#include "DS18B20.h"
#include "display.h"
#include "delay.h"
#include "OneWire.h"
#include "UART.h"

void Timer0_Init(void);		//1����@11.0592MHz


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
		if(flag)//1s����һ���¶�
		{
			flag = 0;
			ack = Read18B20(&temp);
			if(!ack)
			{
				if(temp < 0)//���¶�Ϊ����
				{
//					LEDBUF[7] = 22;
					temp = ~temp;
					temp = temp +1;
					tmp = temp;
					temp = tmp*0.0625*100;//��λС��
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
//				LEDBUF[4] = temp/100%10;//��λ
//				LEDBUF[3] = temp/10%10;//С��λ
//				LEDBUF[2] = temp%10;//С��λ
			}
		}
		ET0 = 0;
		tmp = temp*0.01;
		printf("Temp=%f\r\c",tmp);
		ET0 = 1;
		Delayxms(10000);
	}
	
}

void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
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
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;
}