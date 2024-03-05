#include "key.h"

unsigned char KeyScan()
{
	unsigned char KeyNum = 0;
	keyout1 = 0;keyout2 = 1;keyout3 = 1;keyout4 = 1;
	keyin1 = 1;keyin2 = 1;keyin3 = 1;keyin4 = 1;
	if(!keyin1|!keyin2|!keyin3|!keyin4)
	{
		Delayxms(20);
		if(!keyin1|!keyin2|!keyin3|!keyin4)
		{
			if(!keyin1)
				KeyNum = 4;
			if(!keyin2)
				KeyNum = 5;
			if(!keyin3)
				KeyNum = 6;
			if(!keyin4)
				KeyNum = 7;
		}while(!keyin1|!keyin2|!keyin3|!keyin4);
	}
	keyout1 = 1;keyout2 = 0;keyout3 = 1;keyout4 = 1;
	keyin1 = 1;keyin2 = 1;keyin3 = 1;keyin4 = 1;
	if(!keyin1|!keyin2|!keyin3|!keyin4)
	{
		Delayxms(20);
		if(!keyin1|!keyin2|!keyin3|!keyin4)
		{
			if(!keyin1)
				KeyNum = 8;
			if(!keyin2)
				KeyNum = 9;
			if(!keyin3)
				KeyNum = 10;
			if(!keyin4)
				KeyNum = 11;
		}while(!keyin1|!keyin2|!keyin3|!keyin4);
	}
	keyout1 = 1;keyout2 = 1;keyout3 = 0;keyout4 = 1;
	keyin1 = 1;keyin2 = 1;keyin3 = 1;keyin4 = 1;
	if(!keyin1|!keyin2|!keyin3|!keyin4)
	{
		Delayxms(20);
		if(!keyin1|!keyin2|!keyin3|!keyin4)
		{
			if(!keyin1)
				KeyNum = 12;
			if(!keyin2)
				KeyNum = 13;
			if(!keyin3)
				KeyNum = 14;
			if(!keyin4)
				KeyNum = 15;
		}while(!keyin1|!keyin2|!keyin3|!keyin4);
	}
	keyout1 = 1;keyout2 = 1;keyout3 = 1;keyout4 = 0;
	keyin1 = 1;keyin2 = 1;keyin3 = 1;keyin4 = 1;
	if(!keyin1|!keyin2|!keyin3|!keyin4)
	{
		Delayxms(20);
		if(!keyin1|!keyin2|!keyin3|!keyin4)
		{
			if(!keyin1)
				KeyNum = 16;
			if(!keyin2)
				KeyNum = 17;
			if(!keyin3)
				KeyNum = 18;
			if(!keyin4)
				KeyNum = 19;
		}while(!keyin1|!keyin2|!keyin3|!keyin4);
	}
	return KeyNum;
}