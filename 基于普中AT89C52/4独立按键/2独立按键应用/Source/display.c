#include "display.h"

	unsigned char code leddata[]={ 
 
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
                0x77,  //"A"
                0x7C,  //"B"
                0x39,  //"C"
                0x5E,  //"D"
                0x79,  //"E"
                0x71,  //"F"
                0x76,  //"H"
                0x38,  //"L"
                0x37,  //"n"
                0x3E,  //"u"
                0x73,  //"P"
                0x5C,  //"o"
                0x40,  //"-"
                0x00,  //熄灭
                0x00  //自定义
 
                         };
	//段选动态数码管
	unsigned char code HC138[] = {0xE3,0xE7,0xEB,0xEF,0xF3,0xF7,0xFB,0xFF};
		
	//{0xFF,0xFB,0xF7,0xF3,0xEF,0xEB,0xE7,0xE3};
	//位选动态数码管
	unsigned char LEDBUF[] = {8,8,8,8,8,8,8,8};
	//数据缓冲区 
	
void display()
{
	
	unsigned char i;
	for(i=0;i<8;i++)
	{
	//首先进行段选
	GPIO_DIG = leddata[LEDBUF[i]];
	//然后进行位选
	GPIO_PLACE = HC138[i];
	//之后进行延时
	Delayxms(1);
	//通过i实现动态数码管
	GPIO_DIG = 0x00;
	//实现消影
	
	}
	
}
	
	
	
	