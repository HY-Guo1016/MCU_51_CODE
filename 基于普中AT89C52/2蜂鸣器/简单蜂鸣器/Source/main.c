#include <reg51.h>
#include "delay.h"
sbit BUZZER = P2^5;
void main()
{
	BUZZER = 1;
	while(1)
	{
		
		unsigned char i;
		for(i=0;i<100;i++)
		{
			BUZZER = ~BUZZER;
			Delayxms(1);
		}
		for(i=0;i<100;i++)
		{
			BUZZER = ~BUZZER;
			Delayxms(2);
		}
	}
}