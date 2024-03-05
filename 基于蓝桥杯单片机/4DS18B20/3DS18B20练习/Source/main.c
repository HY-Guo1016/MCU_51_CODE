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
					tmp = temp*0.0625*100;//2λС��
				}
				else
				{
					LEDBUF[7] = 23;
					temp = tmp;
					tmp = temp*0.0625*100;//2λС��
				}
				if(tmp >= 10000)
					LEDBUF[6] = tmp/10000;
				else
					LEDBUF[6] = 23;//��λ
				if(tmp>1000)
					LEDBUF[5] = tmp/1000;
				else
					LEDBUF[5] = 23;//ʮλ
				//��λ��С����
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
	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
	EA = 1;
	TR0 = 1;				//��ʱ��0��ʼ��
}
