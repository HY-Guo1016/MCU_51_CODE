#include <STC15F2K60S2.H>
#include "delay.h"
#include "UART.h"

void main()
{

	UartInit();

	while(1)
	{
		if(Rec_flag)
		{
			switch(Rec_dat)
			{
				case 1:
					P0 = 0xFE;
					P2 = (P2&0x1F)|0x80;
					P2 = P2&0x1F;
					break;
				case 2:
					P0 = 0xFD;
					P2 = (P2&0x1F)|0x80;
					P2 = P2&0x1F;
					break;
				case 3:
					P0 = 0xFB;
					P2 = (P2&0x1F)|0x80;
					P2 = P2&0x1F;
					break;
				case 4:
					P0 = 0xF7;
					P2 = (P2&0x1F)|0x80;
					P2 = P2&0x1F;break;
				default:break;
			}
		}
		
	}
	

}

