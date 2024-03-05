#include <reg51.h>
#include "key.h"
#include "display.h"
#include "delay.h"

void main()
{
	
	
	while(1)
	{
		long cnt;
		LEDBUF[7] = cnt/10000000%10;
		LEDBUF[6] = cnt/1000000%10;
		LEDBUF[5] = cnt/100000%10;
		LEDBUF[4] = cnt/10000%10;
		LEDBUF[3] = cnt/1000%10;
		LEDBUF[2] = cnt/100%10;
		LEDBUF[1] = cnt/10%10;
		LEDBUF[0] = cnt%10;
		switch(key_scan())
		{
			case 0:break;
			case 1:
				cnt++;
				if(cnt>99999999) cnt = 0;
				break;
			case 2:
				cnt--;
				if(cnt<0) cnt = 99999999;
				break;
			case 3:
				cnt = 0;
				break;
			case 4:
				cnt = 88888888;
				break;
			default:break;		
		}
		display();
	}
}