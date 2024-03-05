#include "display.h"

//段选数组
unsigned char code leddata[]={ 
 
                0xC0,  //"0"
                0xF9,  //"1"
                0xA4,  //"2"
                0xB0,  //"3"
                0x99,  //"4"
                0x92,  //"5"
                0x82,  //"6"
                0xF8,  //"7"
                0x80,  //"8"
                0x90,  //"9"
                0x88,  //"A"
                0x83,  //"B"
                0xC6,  //"C"
                0xA1,  //"D"
                0x86,  //"E"
                0x8E,  //"F"
                0x89,  //"H"
                0xC7,  //"L"
                0xC8,  //"n"
                0xC1,  //"u"
                0x8C,  //"P"
                0xA3,  //"o"
                0xBF,  //"-"
                0xFF,  //熄灭
                0xFF  //自定义
 
                         };
//位选数组
unsigned char code place[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
//{0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//数据缓冲区
unsigned char LEDBUF[] = {23,23,23,23,23,23,23,23};
void display()
{
	static unsigned char i = 0;
	switch(i)
	{
		case 0:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i++;
		break;
		
		case 1:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i++;
		break;
		
		case 2:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i++;
		break;
						
		case 3:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i++;
		break;
								
		case 4:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i++;
		break;
								
		case 5:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]]&0x7F;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i++;
		break;
									
		case 6:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i++;
		break;
							
		case 7:
		//消影
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送段码
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//送位选
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//通过i实现数码管
		i=0;
		break;
		
		default:break;
	}
}