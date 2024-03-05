#include "UART.h"

unsigned char Start_Timer = 0;
unsigned char Recv_cnt = 0;
unsigned char Recv_Timer_Cnt=0;
unsigned char Recv_flag=0;
unsigned char Recv_buf[20];
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	AUXR &= 0xBF;		//定时器时钟12T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFD;			//设置定时初始值
	TH1 = 0xFD;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	ES = 1;
	EA = 1;
	TR1 = 1;			//定时器1开始计时
}

void SendByte(unsigned char dat)//发送一帧数据
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