#include <reg51.h>
#include "delay.h"
#include "display.h"

void main()
{
	
	unsigned int i;
	long num = 14141015;	
	for(i=0;i<300;i++)
	{
		display();
	}
		
	while(1)
	{

		LEDBUF[0] = num/10000000;
		LEDBUF[1] = num/1000000%10;
		LEDBUF[2] = num/100000%10;
		LEDBUF[3] = num/10000%10;
		LEDBUF[4] = num/1000%10;
		LEDBUF[5] = num/100%10;
		LEDBUF[6] = num/10%10;
		LEDBUF[7] = num%10;
		display();
	}
}