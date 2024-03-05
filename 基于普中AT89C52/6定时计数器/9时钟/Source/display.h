#ifndef __DISPLAY_H__
#define __DISPLAY_H__


#include <reg51.h>

#define GPIO_DIG        P0   //段选IO口
#define GPIO_PLACE      P2   //位选IO口
#define N               8    //8位数码管

void display();
unsigned char code leddata[];
unsigned char code HC138[];
extern unsigned char LEDBUF[];
	

#endif