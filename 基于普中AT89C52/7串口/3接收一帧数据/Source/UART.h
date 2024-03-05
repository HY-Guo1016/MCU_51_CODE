#ifndef __UART_H__
#define __UART_H__

#include <reg51.h>
#include "delay.h"
#include <stdio.h>
void UartInit(void);		//9600bps@11.0592MHz
void SendByte(unsigned char dat);
void SendString(unsigned char *dat);
char putchar(char c);
extern unsigned char Rec_dat;
extern bit Rec_flag;
#endif
