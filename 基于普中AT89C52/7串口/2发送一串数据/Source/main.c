#include <reg51.h>
#include <intrins.h>
#include <stdio.h>
#include "UART.h"

void Delay1000ms();		//@11.0592MHz

void main()
{
	UartInit();
	while(1)
	{
		SendString("Œ“œ≤ª∂¡ı√ŒÍœ\r\n");
		printf("Œ“œ≤ª∂¡ı√ŒÍœ\r\n");
		Delay1000ms();
	}
}


void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
