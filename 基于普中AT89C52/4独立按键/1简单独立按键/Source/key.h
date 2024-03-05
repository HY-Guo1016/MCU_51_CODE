#ifndef __KEY_H__
#define __KEY_H__
#include <reg51.h>
#include "delay.h"

unsigned char key_scan();
sbit key0 = P3^0;
sbit key1 = P3^1;
sbit key2 = P3^2;
sbit key3 = P3^3;



#endif