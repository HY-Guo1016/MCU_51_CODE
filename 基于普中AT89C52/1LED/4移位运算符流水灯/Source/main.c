#include <reg51.h>
#include "delay.h"

void main()
{
	unsigned char LED=0x01,i=0;
	while(1)
	{
		P2 = ~(LED<<i++);
		if(i==8) i=0;
		Delayxms(500);
	}

}