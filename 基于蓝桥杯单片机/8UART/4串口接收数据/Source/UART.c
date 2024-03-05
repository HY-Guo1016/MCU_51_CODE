#include "UART.h"

unsigned char RecBUF[10];
unsigned char Rec_cnt = 0;
bit Rec_Flag = 0;
void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x01;		//����1ѡ��ʱ��2Ϊ�����ʷ�����
	AUXR &= 0xFB;		//��ʱ��ʱ��12Tģʽ
	T2L = 0xE8;			//���ö�ʱ��ʼֵ
	T2H = 0xFF;			//���ö�ʱ��ʼֵ
	ES = 1;
	AUXR |= 0x10;		//��ʱ��2��ʼ��ʱ
}


void SendByte(unsigned char dat)
{
	SBUF = dat;
	while(!TI);
	TI = 0;
}

void SendString(unsigned char *dat)
{
	while(*dat != '\0')
	{
		SendByte(*dat++);
	}

}

char putchar(char c)
{
	SendByte(c);
	return c;
}

void clr_RecBUF()
{
	unsigned char i;
	for(i=0;i<10;i++)
	{
		RecBUF[i] = 0;
	}
}

void UART_ISR() interrupt 4
{
	if(RI)
	{
		RI = 0;
		Timer_Start = 1;
		if(Rec_cnt<REC_MAX)
		{
			RecBUF[Rec_cnt] = SBUF;
			Rec_cnt++;
		}
		else
			Rec_cnt = 0;
		Timer_Rec_Cnt = 0;
	}
}

