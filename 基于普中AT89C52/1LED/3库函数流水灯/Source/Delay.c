#include"Delay.h"

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i,j,k;
	for(k=xms;k>0;k--)
	{
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
}
