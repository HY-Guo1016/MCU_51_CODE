#include "matrixkey.h"

unsigned char key_scan()
{
	static unsigned char temp,temp2;
	static unsigned char KeyNum=20;
	
	KEYPORT = 0x0F;//先给列零，判断行
	temp = KEYPORT;
	if(temp != 0x0F)
	{
		Delayxms(20);//按键消抖
		if(temp != 0x0F)//消抖后再次判断是否按下
		{
			temp = KEYPORT && 0x0F;//提取矩阵键盘对应的列号
			KEYPORT = 0xF0;//给行全0，判断列
			temp2 = KEYPORT && 0xF0;//提取矩阵键盘对应的行号
		}
	}while(KEYPORT != 0x0F);//松手等待
	
	switch(temp+temp2)
	{
		case 0xEE:KeyNum = 1;break;
		case 0xDE:KeyNum = 2;break;
		case 0xBE:KeyNum = 3;break;
		case 0x7E:KeyNum = 4;break;
		
		case 0xED:KeyNum = 5;break;
		case 0xDD:KeyNum = 6;break;
		case 0xBD:KeyNum = 7;break;
		case 0x7D:KeyNum = 8;break;
		
		case 0xEB:KeyNum = 9;break;
		case 0xDB:KeyNum = 10;break;
		case 0xBB:KeyNum = 11;break;
		case 0x7B:KeyNum = 12;break;
		
		case 0xE7:KeyNum = 13;break;
		case 0xD7:KeyNum = 14;break;
		case 0xB7:KeyNum = 15;break;
		case 0x77:KeyNum = 16;break;
		default: break;
	}
	return KeyNum;
}