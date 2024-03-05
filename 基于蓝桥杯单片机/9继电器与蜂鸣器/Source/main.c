#include <reg51.h>
#include <intrins.h>
sbit RE = P0^4;
sbit BUZZ=P0^6;
void Delay500ms();		//@11.0592MHz
void main()
{
	BUZZ = 0;
	P2 = (P2&0x1F)|0xA0;
	P2 = P2&0x1F;
	while(1)
	{
//		BUZZ = 1;
//		P2 = (P2&0x1F)|0xA0;
//		P2 = P2&0x1F;
//		Delay500ms();
		BUZZ = 1;
		P2 = (P2&0x1F)|0xA0;
		P2 = P2&0x1F;
//		Delay500ms();
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
