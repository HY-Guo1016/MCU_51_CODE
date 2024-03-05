#ifndef __UART_H__
#define __UART_H__

#include <reg51.h>

void UartInit(void);		//4800bps@11.0592MHz
void SendByte(unsigned char dat);
void SendString(unsigned char *dat);
char putchar(char c);
#endif