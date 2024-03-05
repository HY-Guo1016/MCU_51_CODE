#include "DS18B20.h"

bit Start18B20()
{
	bit ack;
	EA = 0;
	ack = OneWireRst();
	if(!ack)
	{
		WriteOneWire(SKIP_ROM);
		WriteOneWire(CONVERT_T);//�����¶�ת��
	}
	EA = 1;
	return ack;

}

bit Read18B20(int *tmp)
{
	bit ack;
	unsigned char MSB,LSB;
	ack = OneWireRst();//��ʼ��
	if(!ack)
	{
		WriteOneWire(SKIP_ROM);
		WriteOneWire(READ_SCRATCHPAD);
		//��ת�����
		LSB = ReadOneWire();
		MSB = ReadOneWire();
		
		*tmp = ((int)MSB<<8)+LSB;
	}
	return ack;
}