#include "key.h"

unsigned char key_scan()
{
	unsigned char KeyNum = 0;
	key1 = 1;
	key2 = 1;
	key3 = 1;
	key4 = 1;
	if(!key1||!key2||!key3||!key4)
	{
		Delayxms(20);//按键消抖
		if(!key1||!key2||!key3||!key4)
		{
			if(!key1)
				KeyNum = 1;
			if(!key2)
				KeyNum = 2;
			if(!key3)
				KeyNum = 3;
			if(!key4)
				KeyNum = 4;
		}while(!key1||!key2||!key3||!key4);//松手等待
	}
		
	return KeyNum;
}