#ifndef __DS1302_H__
#define __DS1302_H__

#include "SPI.h"
//void DS1302_Write(unsigned char addr,unsigned char dat);
//unsigned char DS1302_Read(unsigned char addr);
void DS1302Init();
void ReadTimer();
extern unsigned char DS1302Time[7];
#endif