#include <reg51.h>
#include "key.h"
#include "delay.h"

void main()
{
	P2 = 0xFF;
	while(1)
	{
		if(key_scan() == 1)
		{
			P2 = ~P2;
			
		}
	}
}