#include "time.h"
unsigned char UART_Timer_Start = 0;
unsigned char UART_Timer_Cnt = 0;
void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	ET0 = 1;
	
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}

void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	
	if(UART_Timer_Start)
	{
		UART_Timer_Cnt++;
		if(UART_Timer_Cnt>5)
		{
			Rec_Flag = 1;
			UART_Timer_Cnt = 0;
			Rec_cnt = 0;
			UART_Timer_Start=0;
			//Rec_cnt = 0;
		}
	}
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;
}