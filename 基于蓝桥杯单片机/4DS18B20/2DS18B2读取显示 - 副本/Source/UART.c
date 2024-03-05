#include "UART.h"

unsigned char RecBUF[10];
unsigned char Rec_cnt = 0;
bit Rec_Flag = 0;
void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR &= 0xFB;		//定时器时钟12T模式
	T2L = 0xE8;			//设置定时初始值
	T2H = 0xFF;			//设置定时初始值
	ES = 1;
	AUXR |= 0x10;		//定时器2开始计时
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

//void clr_RecBUF()
//{
//	unsigned char i;
//	for(i=0;i<10;i++)
//	{
//		RecBUF[i] = 0;
//	}
//}

//void UART_ISR() interrupt 4
//{
//	if(RI)
//	{
//		RI = 0;
//		Timer_Start = 1;
//		if(Rec_cnt<REC_MAX)
//		{
//			RecBUF[Rec_cnt] = SBUF;
//			Rec_cnt++;
//		}
//		else
//			Rec_cnt = 0;
//		Timer_Rec_Cnt = 0;
//	}
//}

