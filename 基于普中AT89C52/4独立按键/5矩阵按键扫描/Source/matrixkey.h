#ifndef __MATRIXKEY_H__
#define __MATRIXKEY_H__
#include <reg51.h>
#include "delay.h"

unsigned char key_scan();
sbit keyin1 =  P1^3;
sbit keyin2 =  P1^2;
sbit keyin3 =  P1^1;
sbit keyin4 =  P1^0;
sbit keyout4 = P1^4;
sbit keyout3 = P1^5;
sbit keyout2 = P1^6;
sbit keyout1 = P1^7;


#endif