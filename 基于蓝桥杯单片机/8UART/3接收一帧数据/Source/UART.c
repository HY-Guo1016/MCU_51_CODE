#include "UART.h"

unsigned char Rec_dat;
unsigned char Rec_flag=0;
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFD;			//���ö�ʱ��ʼֵ
	TH1 = 0xFD;			//���ö�ʱ����ֵ
	ES = 1;
	EA = 1;
	ET1 = 0;			//��ֹ��ʱ���ж�
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