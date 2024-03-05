#ifndef __TIME_H__
#define __TIME_H__

#include <reg51.h>
#include "display.h"
#include "UART.h"     
//sfr AUXR        =   0x8E;   //0000,0000 ¸¨Öú¼Ä´æÆ÷

void Timer0_Init(void);		//1ºÁÃë@11.0592MHz

extern unsigned char UART_Timer_Start;
extern unsigned char UART_Timer_Cnt;
#endif