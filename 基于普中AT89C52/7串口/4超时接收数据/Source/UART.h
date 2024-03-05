#ifndef __UART_H__
#define __UART_H__

#include <reg51.h>
#include <stdio.h>
#include "time.h"


void UartInit(void);		//9600bps@11.0592MHz
void Sendbyte(unsigned char dat);
void SendString(unsigned char *dat);
void clr_Rec_BUF();

extern bit Rec_Flag;
extern unsigned char Rec_dat;
extern unsigned char Rec_BUF[10];
extern unsigned char Rec_cnt;
#endif