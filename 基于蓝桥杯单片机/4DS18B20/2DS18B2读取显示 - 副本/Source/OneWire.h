#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include <reg51.h>
#include <intrins.h>
#include "delay.h"

void WriteOneWire(unsigned char dat);
unsigned char ReadOneWire();
bit OneWireRst();
sbit DS18B20 = P1^4;

#endif