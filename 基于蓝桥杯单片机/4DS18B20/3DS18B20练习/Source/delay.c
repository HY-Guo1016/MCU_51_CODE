#include "delay.h"

void Delay60us()		//@11.0592MHz
{
	unsigned char i;

	i = 25;
	while (--i);
}


void Delay600us()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 15;
	do
	{
		while (--j);
	} while (--i);
}

