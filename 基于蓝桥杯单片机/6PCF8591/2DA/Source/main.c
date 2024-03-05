#include <STC15F2K60S2.H>
#include "PCF8591.h"

void main()
{
	
	while(1)
	{
		DA_Convert(0x48,0xff);
	}

}