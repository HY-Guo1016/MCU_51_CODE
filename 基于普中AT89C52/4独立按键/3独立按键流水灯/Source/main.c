#include <reg51.h>
#include <intrins.h>
#include "key.h"
#include "delay.h"

void key_service();
bit StartFlag = 0;
bit UpDownFlag = 0;
unsigned char temp = 0xFE;
void main()
{
	
	while(1)
	{
		key_service();
	}
}

void key_service()
{
	switch(key_scan())
	{
		case 1:
			StartFlag = 0;
			break;
		case 2:
			StartFlag = 1;
			break;
		case 3:
			UpDownFlag = 0;
			break;
		case 4:
			UpDownFlag = 1;
			break;
		default:break;
	}

	if(StartFlag)
	{
		P2 = temp;
		Delayxms(500);
		if(0 == UpDownFlag)
			temp = _crol_(temp,1);
		else
			temp = _cror_(temp,1);
	}
}