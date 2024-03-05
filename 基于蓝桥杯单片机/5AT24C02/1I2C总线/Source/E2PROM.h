#ifndef __E2PROM_H__
#define __E2PROM_H__


#include "I2C.h"

unsigned char EEPReadByte(unsigned char I2CAddr,unsigned char addr);
void EEPWriteByte(unsigned char I2CAddr,unsigned char Addr,unsigned char dat);
#endif