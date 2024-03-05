#include "display.h"
unsigned char code LED_DATA[] = 
								{
									0xc0, //0
									0xf9, //1
									0xa4, //2
									0xb0, //3
									0x99, //4
									0x92, //5
									0x82, //6
									0xf8, //7
									0x80, //8
									0x90, //9
									0x88, //A
									0x83, //b
									0xc6, //C
									0xa1, //d
									0x86, //E
									0x8e, //F
									0xFF,
									0xBF
								};
								
unsigned char code LED_Place[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

unsigned char LEDBUF[] = {16,16,16,16,16,16,16,16};

void display()
{
	static unsigned char i = 0;
	switch(i)
	{
		case 0:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
		
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
		
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i++;
			break;
		case 1:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i++;
			break;
		case 2:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i++;
			break;
		case 3:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i++;
			break;
		case 4:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i++;
			break;
		case 5:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i++;
			break;
		case 6:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i++;
			break;
		case 7:
			P0 = 0xFF;
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			P0 = LED_Place[i];
			P2 = (P2&0x1F)|0xC0;
			P2 = P2&0x1F;
			P0 = LED_DATA[LEDBUF[i]];
			P2 = (P2&0x1F)|0xE0;
			P2 = P2&0x1F;
			i = 0;
			break;
		default:break;
	}
}
