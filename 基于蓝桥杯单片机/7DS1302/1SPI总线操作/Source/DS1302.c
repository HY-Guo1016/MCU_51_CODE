#include "DS1302.h"

unsigned char code READ_TIME[7] = {0x81,0x83,0x85,0x87,0x89,0x8B,0x8D};
unsigned char code WRITE_TIME[7] = {0x80,0x82,0x84,0x86,0x88,0x8A,0x8C};
unsigned char DS1302Time[7] = {0x50,0x59,0x23,0x00,0x00,0x00,0x00};

void DS1302Init()
{
	unsigned char i;
	Write_Ds1302_Byte(0x8E,0x00);
	for(i=0;i<7;i++)
	{
		Write_Ds1302_Byte(WRITE_TIME[i],DS1302Time[i]);
	}
	Write_Ds1302_Byte(0x8E,0x80);
}

void ReadTimer()
{
	unsigned char i;
	for(i=0;i<7;i++)
	{
		DS1302Time[i] = Read_Ds1302_Byte(READ_TIME[i]);
	}
}

