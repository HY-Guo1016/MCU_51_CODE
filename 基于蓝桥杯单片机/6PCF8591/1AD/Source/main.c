#include <reg51.h>
#include "PCF8591.h"
#include "display.h"

void Timer0_Init(void);		//1����@11.0592MHz
void disp_service();
unsigned int AD_show=0;
unsigned char AD_flag=0;
unsigned char Timer0Cnt=0;
void main()
{
	unsigned char AD_result=0;
	unsigned int ADdat=0;
	unsigned int AD_filter=0;
	unsigned char AD_cnt=0;
	Timer0_Init();
	while(1)
	{
		if(AD_flag)
		{
			
			AD_flag = 0;
			AD_result = AD_Convert(0x48,3);//��������0-255��һ������ʵ�ʵ�ѹ��  ����/255*5V
			
			ADdat = AD_result*1.0*500/255;//0.01
			AD_filter = ADdat+AD_filter;
			AD_cnt++;
			
			if(AD_cnt >= 8)
			{
				AD_show = AD_filter>>3;
				AD_filter = 0;
				AD_cnt = 0;
			}
		}
		disp_service();
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
	TR0 = 0;
	
	Timer0Cnt++;
	if(Timer0Cnt==100)
	{	
		Timer0Cnt = 0;
		AD_flag = 1;
	}
	display();
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;
}

void disp_service()
{
	LEDBUF[2] = AD_show/100%10;
	LEDBUF[1] = AD_show/10%10;
	LEDBUF[0] = AD_show%10;

}