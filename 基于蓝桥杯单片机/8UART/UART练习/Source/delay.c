#include "delay.h"

void Delayxms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	unsigned int k;
	k = xms;
	while(k)
	{
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		k--;
	}
}
