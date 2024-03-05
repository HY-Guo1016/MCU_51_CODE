#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include <reg51.h>
#include "delay.h"

bit OneWireRst();
void WriteOneWire(unsigned char dat);
unsigned char ReadOneWire();
sbit DS18B20 = P3^7;

#endif