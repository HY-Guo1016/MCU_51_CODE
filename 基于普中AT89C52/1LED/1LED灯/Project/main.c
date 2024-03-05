#include <reg51.h>

void DelayXms(unsigned char X);		//@12.000MHz
void main()
{
	while(1)
	{
		P2 = 0xFE;//1111 1110
		DelayXms(500);
		P2 = 0xFD;//1111 1101
		DelayXms(500);
		P2 = 0xFB;//1111 1011
		DelayXms(500);
		P2 = 0xF7;//1111 0111
		DelayXms(500);
		P2 = 0xEF;//1110 1111
		DelayXms(500);
		P2 = 0xDF;//1101 1111
		DelayXms(500);
		P2 = 0xBF;//1011 1111
		DelayXms(500);
		P2 = 0x7F;//0111 1111
		DelayXms(500);
	}

}

void DelayXms(unsigned char X)		//@12.000MHz
{
	
	unsigned char i, j, k;
	for(k=X;k>0;k--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
