#ifndef __UART_H__
#define __UART_H__

#include <STC15F2K60S2.H>
#include "delay.h"
#include <stdio.h>
void UartInit(void);		//9600bps@11.0592MHz
void SendByte(unsigned char dat);
void SendString(unsigned char *dat);
char putchar(char c);
extern unsigned char Rec_dat;
extern unsigned char Rec_flag;
#endif
