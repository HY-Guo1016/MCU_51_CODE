#include "matrixkey.h"

unsigned char key_scan()
{
	static unsigned char KeyNum = 0;
	//第一行扫描
	keyin1 = 1;	keyin2 = 1;	keyin3 = 1;	keyin4 = 1;
	keyout1 = 0;	keyout2 = 1;	keyout3 = 1;	keyout4 = 1;
	if(!keyin1||!keyin2||!keyin3||!keyin4)
	{
		Delayxms(20);//按键消抖
		if(!keyin1||!keyin2||!keyin3||!keyin4)
		{
			if(!keyin1)
				KeyNum = 1;
			if(!keyin2)
				KeyNum = 2;
			if(!keyin3)
				KeyNum = 3;
			if(!keyin4)
				KeyNum = 4;
		}while(!keyin1||!keyin2||!keyin3||!keyin4);//松手等待
	}
		
	//第二行扫描
	keyin1 = 1;	keyin2 = 1;	keyin3 = 1;	keyin4 = 1;
	keyout1 = 1;	keyout2 = 0;	keyout3 = 1;	keyout4 = 1;
	if(!keyin1||!keyin2||!keyin3||!keyin4)
	{
		Delayxms(20);//按键消抖
		if(!keyin1||!keyin2||!keyin3||!keyin4)
		{
			if(!keyin1)
				KeyNum = 5;
			if(!keyin2)
				KeyNum = 6;
			if(!keyin3)
				KeyNum = 7;
			if(!keyin4)
				KeyNum = 8;
		}while(!keyin1||!keyin2||!keyin3||!keyin4);//松手等待
	}
	//第三行扫描
	keyin1 = 1;	keyin2 = 1;	keyin3 = 1;	keyin4 = 1;
	keyout1 = 1;	keyout2 = 1;	keyout3 = 0;	keyout4 = 1;
	if(!keyin1||!keyin2||!keyin3||!keyin4)
	{
		Delayxms(20);//按键消抖
		if(!keyin1||!keyin2||!keyin3||!keyin4)
		{
			if(!keyin1)
				KeyNum = 9;
			if(!keyin2)
				KeyNum = 10;
			if(!keyin3)
				KeyNum = 11;
			if(!keyin4)
				KeyNum = 12;
		}while(!keyin1||!keyin2||!keyin3||!keyin4);//松手等待
	}
			
	//第四行扫描
	keyin1 = 1;	keyin2 = 1;	keyin3 = 1;	keyin4 = 1;
	keyout1 = 1;	keyout2 = 1;	keyout3 = 1;	keyout4 = 0;
	if(!keyin1||!keyin2||!keyin3||!keyin4)
	{
		Delayxms(20);//按键消抖
		if(!keyin1||!keyin2||!keyin3||!keyin4)
		{
			if(!keyin1)
				KeyNum = 13;
			if(!keyin2)
				KeyNum = 14;
			if(!keyin3)
				KeyNum = 15;
			if(!keyin4)
				KeyNum = 16;

		}while(!keyin1||!keyin2||!keyin3||!keyin4);//松手等待
	}
	return KeyNum;
}