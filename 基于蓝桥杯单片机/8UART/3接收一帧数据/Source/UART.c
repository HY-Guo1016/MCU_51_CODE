#include "UART.h"

unsigned char Rec_dat;
unsigned char Rec_flag=0;
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
	ES = 1;
	EA = 1;
	ET1 = 0;			//禁止定时器中断
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

void UART_ISR() interrupt 4
{
	if(RI)
	{	
		RI = 0;
		Rec_flag = 1;
		Rec_dat = SBUF;
	}

}