#include "E2PROM.h"

void EEPRead(unsigned char I2CAddr,unsigned char addr,unsigned char *buf,unsigned char len)
{
	I2CStart();
	I2CWriteByte(I2CAddr<<1);
	I2CWriteByte(addr);
	I2CStart();
	I2CWriteByte((I2CAddr<<1)|0x01);//后续是读操作，从这个字节开始往下读
	while(len > 1)
	{
		*buf++ = I2CReadByte();
		//INC R0
		//MOV @R0,#01H
		SendAck(0);
		len--;
	}
	*buf = I2CReadByte();
	SendAck(1);
	I2CStop();
}

void EEPWrite(unsigned char I2CAddr,unsigned char Addr,unsigned char *buf,unsigned char len)
{
	while(len>0)
	{
		do{
			I2CStart();
			if(!(I2CWriteByte(I2CAddr<<1)))
				break;
			I2CStop();
		}while(1);
		
		
		I2CWriteByte(Addr++);
		I2CWriteByte(*buf++);
		I2CStop();
		//Delayxms(15);
		len--;
	}
}


unsigned char E2PROMWritePage(unsigned char I2CAddr,unsigned char addr,unsigned char *buf,unsigned char len)
{
	if(Max_addr-addr<len)
		return 0;
	while(len>0)
	{
		do{
			I2CStart();
			if(!(I2CWriteByte(I2CAddr<<1)))
				break;
			I2CStop();
		}while(1);
		I2CWriteByte(addr);
		while(len>0)
		{
			I2CWriteByte(*buf++);
			addr++;
			len--;
			if(!(addr&page))
				break;	
		}
		I2CStop();
	}
	return 1;
}