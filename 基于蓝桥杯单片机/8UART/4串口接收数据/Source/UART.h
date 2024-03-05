#ifndef __UART_H__
#define __UART_H__

#include <reg51.h>
#include "time.h"
sfr T2H         =   0xD6;   //0000,0000 T2���ֽ�
sfr T2L         =   0xD7;   //0000,0000 T2���ֽ�
sfr AUXR        =   0x8E;   //0000,0000 �����Ĵ���
#define REC_MAX       10
void UartInit(void);		//9600bps@11.0592MHz
void SendByte(unsigned char dat);
void SendString(unsigned char *dat);
char putchar(char c);
void clr_RecBUF();

extern unsigned char RecBUF[10];
extern unsigned char Rec_cnt;
extern bit Rec_Flag;
#endif