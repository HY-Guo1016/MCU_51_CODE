#include <reg51.h>
#include "delay.h"

void UartInit(void);		//4800bps@11.0592MHz
void SendByte(unsigned char dat);

unsigned char dat = 55;
void main()
{
	UartInit();
	while(1)
	{
		SendByte(0x88);
		
	}

}

void UartInit(void)		//4800bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR &= 0xBF;		//定时器时钟12T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFA;			//设置定时初始值
	TH1 = 0xFA;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}

void SendByte(unsigned char dat)
{
	SBUF = dat;
	while(!TI);
	Delay1000ms();
	TI = 0;

}