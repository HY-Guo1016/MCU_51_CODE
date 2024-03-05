#ifndef __E2PROM_H__
#define __E2PROM_H__


#include "I2C.h"
#include "delay.h"

void EEPRead(unsigned char I2CAddr,unsigned char addr,unsigned char *buf,unsigned char len);
void EEPWrite(unsigned char I2CAddr,unsigned char Addr,unsigned char *buf,unsigned char len);

#endif