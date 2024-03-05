#include "UART.h"

unsigned char Rec_dat;
bit Rec_flag=0;
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


void SendByte(unsigned char dat)//����һ֡����
{
	SBUF = dat;
	while(!TI);
	TI = 0;
}


void SendString(unsigned char *dat)
{	
	while(*dat!='\0')
	{
		SendByte(*dat++);
	}
}

char putchar(char c)
{
	SendByte(c);
	return c;
}

void UART_ISR() interrupt 4
{
	if(RI)
	{	
		RI = 0;
		Rec_flag = 1;
		Rec_dat = SBUF;
	}

}