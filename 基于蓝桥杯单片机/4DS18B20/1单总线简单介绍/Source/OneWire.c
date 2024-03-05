#include "OneWire.h"

bit OneWireRst()
{
	bit ack;
	EA = 0;
	DS18B20 = 0;
	Delay480us();
	DS18B20 = 1;
	Delay60us();
	ack = DS18B20;
	while(!DS18B20);
	EA = 1;
	return ack;
}

void WriteOneWire(unsigned char dat)
{

	unsigned char tmp;
	EA = 0;
	for(tmp=0x01;tmp != 0;tmp<<1)
	{
		DS18B20 = 0;
		_nop_();
		_nop_();
		if((tmp&dat) == 0)
			DS18B20 = 0;
		else
			DS18B20 = 1;
		Delay60us();
		DS18B20 = 1;
	}
	EA = 1;
}

unsigned char ReadOneWire()
{
	
	unsigned char dat;
	unsigned char tmp;
	EA = 0;
	for(tmp = 0x01;tmp != 0;tmp<<1)
	{
		DS18B20 = 0;
		_nop_();
		_nop_();
		DS18B20 = 1;
		_nop_();
		_nop_();
		if(!DS18B20)
			dat &= ~tmp;
		else
			dat |= tmp;
	}
	EA = 1;
	return dat;
}