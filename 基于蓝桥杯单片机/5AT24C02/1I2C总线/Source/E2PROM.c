#include "E2PROM.h"

unsigned char EEPReadByte(unsigned char I2CAddr,unsigned char addr)
{
	unsigned char dat;
	I2CStart();
	I2CWriteByte(I2CAddr<<1);
	I2CWriteByte(addr);
	I2CStart();
	I2CWriteByte((I2CAddr<<1)|0x01);
	dat = I2CReadByte();
	SendAck(1);
	I2CStop();
	return dat;
}

void EEPWriteByte(unsigned char I2CAddr,unsigned char Addr,unsigned char dat)
{
	I2CStart();
	I2CWriteByte((I2CAddr<<1));
	I2CWriteByte(Addr);
	I2CWriteByte(dat);
	I2CStop();
}