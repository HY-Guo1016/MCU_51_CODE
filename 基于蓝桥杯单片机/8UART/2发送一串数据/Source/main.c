#include <STC15F2K60S2.H>
#include "UART.h"

void Timer0_Init(void);		//1����@11.0592MHz
void main()
{
	UartInit();
	Timer0_Init();
	while(1)
	{
		if(Recv_flag)
		{
			Recv_flag=0;
			Start_Timer = 0;
			SendString(Recv_buf);
			clr_recv_buf();
		}
	}

}


void Timer0_Init(void)		//1����@11.0592MHz
{
	AUXR &= 0x7F;			//��ʱ��ʱ��12Tģʽ
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
	if(Start_Timer)
	{
		Recv_Timer_Cnt++;
		if(Recv_Timer_Cnt>5)
		{
			Recv_flag = 1;
			Recv_Timer_Cnt = 0;
			Recv_cnt = 0;
		}
	}
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;

}