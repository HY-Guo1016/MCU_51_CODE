#ifndef __DISPLAY_H__
#define __DISPLAY_H__


#include "delay.h"
#include <reg51.h>

#define GPIO_DIG        P0   //��ѡIO��
#define GPIO_PLACE      P2   //λѡIO��
#define N               8    //8λ�����

void display();
unsigned char code leddata[];
unsigned char code HC138[];
extern unsigned char LEDBUF[];
	

#endif