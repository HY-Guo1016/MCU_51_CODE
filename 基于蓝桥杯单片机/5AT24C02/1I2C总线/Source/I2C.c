#include "I2C.h"

void I2CStart()
{
	I2C_SDA = 1;//���߿���ʱSCL��SDA��Ϊ�ߵ�ƽ
	I2C_SCL = 1;
	I2CDelay();//SCL����4.7us�����ͣ�SDA������ʼ�ź�
	I2C_SDA = 0;
	I2CDelay();
	I2C_SCL = 0;
}

bit I2CWriteByte(unsigned char dat)
{
	bit ack;
	unsigned char tmp;
	for(tmp = 0x80;tmp != 0;tmp >>= 1)
	{
		if((tmp&dat)==0)
			I2C_SDA = 0;
		else
			I2C_SDA = 1;
		I2CDelay();
		I2C_SCL = 1;
		I2CDelay();
		I2C_SCL = 0;
	}
	ack = I2CRecAck();
	return ack;
}
unsigned char I2CReadByte()
{
	unsigned char tmp;
	unsigned char dat;
	I2C_SDA = 1;
	for(tmp = 0x80;tmp != 0;tmp >>= 1)
	{
		I2CDelay();
		I2C_SCL = 1;
		if(I2C_SDA == 1)
			dat |= tmp;
		else 
			dat &= ~tmp;
		I2CDelay();
		I2C_SCL = 0;
	}
	return dat;
}

bit I2CRecAck()
{
	bit ack;
	I2C_SDA = 1;
	I2CDelay();
	I2C_SCL = 1;
	I2CDelay();
	ack = I2C_SDA;
	I2CDelay();
	I2C_SCL = 0;
	return ack;
}

void SendAck(bit ack)
{
	I2C_SDA = ack;
	I2CDelay();
	I2C_SCL = 1;
	I2CDelay();
	I2C_SCL = 0;
}
void I2CStop()
{
	I2C_SDA = 0;//����SCL��SDA��Ϊ�͵�ƽ
	I2C_SCL = 0;
	I2CDelay();
	I2C_SCL = 1;
	I2CDelay();
	I2C_SDA = 1;
	I2CDelay();
}