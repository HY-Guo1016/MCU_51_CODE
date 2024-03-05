#ifndef __UART_H__
#define __UART_H__

#include <STC15F2K60S2.H>
#include "delay.h"
#include <stdio.h>

#define MAX_RECV   20

void UartInit(void);		//9600bps@11.0592MHz
void SendByte(unsigned char dat);
void SendString(unsigned char *dat);
void clr_recv_buf();

extern unsigned char Start_Timer;
extern unsigned char Recv_cnt;
extern unsigned char Recv_Timer_Cnt;
extern unsigned char Recv_flag;
extern unsigned char Recv_buf[];

#endif
