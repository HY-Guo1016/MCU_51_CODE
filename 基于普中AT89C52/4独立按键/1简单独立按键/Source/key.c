#include "key.h"

unsigned char key_scan()
{
	unsigned char KeyNum = 0;
	if(!key1)
	{
		Delayxms(20);//按键消抖
		if(!key1)
		{
			KeyNum = 1;
		}
	}while(!key1);//松手等待
		
	return KeyNum;
}