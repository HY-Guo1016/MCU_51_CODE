#include <reg51.h>
#include <intrins.h>
#include "delay.h"
#include "UART.h"

void main()
{

	UartInit();
	EA = 1;
	while(1)
	{
		if(_testbit_(Rec_flag))
		{
			SendByte(Rec_dat);
		}
	}
	

}

