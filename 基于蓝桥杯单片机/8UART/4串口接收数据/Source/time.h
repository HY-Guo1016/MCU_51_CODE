#ifndef __TIME_H__
#define __TIME_H__

#include <reg51.h>
#include "UART.h"
void Timer0_Init(void);		//1∫¡√Î@11.0592MHz

extern unsigned char Timer_Start;
extern unsigned char Timer_Rec_Cnt;
#endif