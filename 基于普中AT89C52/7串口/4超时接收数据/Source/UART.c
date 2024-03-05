#include "UART.h"
bit Rec_Flag = 0;
unsigned char Rec_dat;
unsigned char Rec_BUF[10];
unsigned char Rec_cnt = 0;
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFD;			//���ö�ʱ��ʼֵ
	TH1 = 0xFD;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	ES = 1;
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
}


void Sendbyte(unsigned char dat)
{
	SBUF = dat;
	while(!TI);
	TI = 0;
}

void clr_Rec_BUF()
{
	unsigned char i;
	for(i=0;i<10;i++)
	{
		Rec_BUF[i] = 0;
	}
}
void SendString(unsigned char *dat)
{
	while(*dat != '\0')
	{
		Sendbyte(*dat++);
	}
}

char putchar(char c)
{
	Sendbyte(c);
	return c;
}


void UART_ISR() interrupt 4
{
	if(RI)
	{
		RI = 0;
		UART_Timer_Start = 1;
		if(Rec_cnt<10)
		{
			Rec_BUF[Rec_cnt] = SBUF;
			Rec_cnt++;
		}
		else
			Rec_cnt = 0;
		UART_Timer_Cnt = 0;
	}
}

