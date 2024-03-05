#ifndef __PCF8591_H__
#define __PCF8591_H__

#include "iic.h"

unsigned char AD_Convert(unsigned char addr,unsigned char channel);
unsigned char DA_Convert(unsigned char Addr,unsigned char dat);

#endif