#include <reg51.h>
#include "delay.h"

void EX1_INT(void);
void main()
{
	EX1_INT();
	while(1)
	{
		
	}
}

void EX1_INT(void)//中断的初始化
{
	IT1 = 1;   //下降沿触发
	EA = 1;    //总中断允许开关
	EX1 = 1;   //外部中断0允许开关
}

void EX1_ISR(void) interrupt 2 //外部中断1程序
{
	Delayxms(1200);
	P2 = ~P2;
}