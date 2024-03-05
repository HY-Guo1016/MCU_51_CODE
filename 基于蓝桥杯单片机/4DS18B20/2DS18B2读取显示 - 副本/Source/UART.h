#ifndef __UART_H__
#define __UART_H__

#include <reg51.h>

sfr T2H         =   0xD6;   //0000,0000 T2¸ß×Ö½Ú
sfr T2L         =   0xD7;   //0000,0000 T2µÍ×Ö½Ú
sfr AUXR        =   0x8E;   //0000,0000 ¸¨Öú¼Ä´æÆ÷
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