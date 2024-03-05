#include <reg51.h>
#include "delay.h"


unsigned char code LEDBUF[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
void main()
{	unsigned char m;
	while(1)
	{
		
		for(m = 0;m < 8;m++)
		{
			P2 = LEDBUF[m];
			Delayxms(200);
		}
	}

}