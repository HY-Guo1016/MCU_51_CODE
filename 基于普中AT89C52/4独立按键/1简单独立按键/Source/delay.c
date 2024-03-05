//ÑÓÊ±º¯Êý´úÂë
#include "delay.h"


void Delayxms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms=xms-1;
	
	
	}
	
}
