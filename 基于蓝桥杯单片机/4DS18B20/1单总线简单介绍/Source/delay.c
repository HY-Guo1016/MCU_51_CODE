#include "delay.h"

void Delayxms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j, k;
	for(k=xms;k<0;k--)
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
	}
}

void Delay60us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 163;
	while (--i);
}
void Delay480us()		//@11.0592MHz
{
	unsigned char i, j;

	i = 6;
	j = 38;
	do
	{
		while (--j);
	} while (--i);
}
