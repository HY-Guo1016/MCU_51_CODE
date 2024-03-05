#ifndef __KEY_H__
#define __KEY_H__

#include <reg51.h>
#include "delay.h"

sfr P4          =   0xC0;   //1111,1111 ¶Ë¿Ú4

sbit keyin1 = P3^3;
sbit keyin2 = P3^2;
sbit keyin3 = P3^1;
sbit keyin4 = P3^0;

sbit keyout1 = P4^4;
sbit keyout2 = P4^2;
sbit keyout3 = P3^5;
sbit keyout4 = P3^4;

unsigned char KeyScan();
#endif