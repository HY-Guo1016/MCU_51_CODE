#include <reg51.h>
#include <intrins.h>

void Delay500ms();
sbit LED0 = P0^0;
void main()
{
	while(1)
	{
		LED0 = ~LED0;
		P2 = (P2&0x1F)|0x80;    //1000
		P2 = (P2&0x1F);
		Delay500ms();
	}
}

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}