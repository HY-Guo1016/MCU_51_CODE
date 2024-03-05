#include <reg51.h>
#include "matrixkey.h"
#include "display.h"
#include "delay.h"

void main()
{
	
	LEDBUF[0] = 23;
	LEDBUF[1] = 23;
	LEDBUF[2] = 23;
	LEDBUF[3] = 23;
	LEDBUF[4] = 23;
	LEDBUF[5] = 23;
	LEDBUF[6] = 23;
	
	while(1)
	{
		switch(key_scan())
		{
			case 1:LEDBUF[7] = 1;break;
			case 2:LEDBUF[7] = 2;break;
			case 3:LEDBUF[7] = 3;break;
			case 4:LEDBUF[7] = 4;break;
			case 5:LEDBUF[7] = 5;break;
			case 6:LEDBUF[7] = 6;break;
			case 7:LEDBUF[7] = 7;break;
			case 8:LEDBUF[7] = 8;break;
			case 9:LEDBUF[7] = 9;break;
			case 10:LEDBUF[7] = 10;break;
			case 11:LEDBUF[7] = 11;break;
			case 12:LEDBUF[7] = 12;break;
			case 13:LEDBUF[7] = 13;break;
			case 14:LEDBUF[7] = 14;break;
			case 15:LEDBUF[7] = 15;break;
			case 16:LEDBUF[7] = 16;break;
			default:break;
		}
		display();
	
	}
}