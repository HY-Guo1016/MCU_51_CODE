#include <reg51.h>
#include <intrins.h>
#include "Delay.h"
void main()
{
	unsigned char temp = 0xfe;;
	while(1)
	{
		P2 = temp;
		Delay(500);
		temp = _crol_(temp,1);
	}
}