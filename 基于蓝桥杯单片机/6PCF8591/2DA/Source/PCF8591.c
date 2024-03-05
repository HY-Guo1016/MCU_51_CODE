#include "PCF8591.h"

unsigned char AD_Convert(unsigned char addr,unsigned char channel)
{
	unsigned char dat=0;
	IIC_Start();
	if(IIC_SendByte(addr<<1))
	{
		IIC_Stop();
		return 0;
	}
	IIC_SendByte(channel);
	
	IIC_Start();
	IIC_SendByte((addr<<1)|0x01);
	IIC_RecByte();
	IIC_SendAck(0);
	dat = IIC_RecByte();
	IIC_SendAck(1);
	IIC_Stop();
	return dat;

}

unsigned char DA_Convert(unsigned char Addr,unsigned char dat)
{
	IIC_Start();
	if(IIC_SendByte((Addr<<1)))
	{
		IIC_Stop();
		return 0;
	}
	IIC_SendAck(0x40);
	IIC_SendAck(dat);
	IIC_Stop();
	return 1;
	
	
	
}