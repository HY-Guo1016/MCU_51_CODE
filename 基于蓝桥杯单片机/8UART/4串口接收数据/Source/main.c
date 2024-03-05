#include <reg51.h>
#include "UART.h"
#include "delay.h"
#include <stdio.h>
#include "time.h"

void UART_ser();

unsigned char UART_Place=0;

void main()
{
	UartInit();
	Timer0_Init();
	EA = 1;
	while(1)
	{
		UART_ser();
//		Delayxms(1000);
	}
}

void UART_ser()
{
	if (_testbit_ (Rec_Flag))
	{
		if((RecBUF[0]=='o')&&(RecBUF[1]=='p')&&(RecBUF[2]=='e')&&(RecBUF[3]=='n')&&(RecBUF[4]=='\r')&&(RecBUF[5]=='\n'))
		{
			P0 = ~P0;
			P2 = (P2&0x1F)|0x80;
			P2 = P2&0x1F;
		}
		SendString(RecBUF);
		clr_RecBUF();
	}

}