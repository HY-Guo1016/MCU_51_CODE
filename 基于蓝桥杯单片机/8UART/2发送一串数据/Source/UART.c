#include "UART.h"

unsigned char Start_Timer = 0;
unsigned char Recv_cnt = 0;
unsigned char Recv_Timer_Cnt=0;
unsigned char Recv_flag=0;
unsigned char Recv_buf[20];
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
	ET1 = 0;			//��ֹ��ʱ���ж�
	ES = 1;
	EA = 1;
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

void clr_recv_buf()
{
	unsigned char i;
	for(i=0;i<MAX_RECV;i++)
	{
		Recv_buf[i]=0;
	}
}

void UART_ISR() interrupt 4
{
	if(RI)
	{
		RI = 0;
		Start_Timer=1;
		if(Recv_cnt<MAX_RECV)
		{
			Recv_buf[Recv_cnt] = SBUF;
			Recv_cnt++;
			
		}
		else
		{
			Recv_cnt = MAX_RECV;
		}
		Recv_Timer_Cnt = 0;
	}

}