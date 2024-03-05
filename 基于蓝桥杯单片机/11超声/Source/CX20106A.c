#include "CX20106A.h"

void WaveS()
{
	unsigned char WavNum = 10;
	while(WavNum--)
	{
		WaveSend = ~WaveSend;
		Delay12us();
	}

}

void WaveR(unsigned int *tmp)
{
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	while(WaveRecv&!TF0);
	TR0 = 0;
	if(TF0)
	{
		TF0 = 0;
		*tmp = 65535;
	}	
	if(!WaveRecv)
	{
		*tmp = ((TH0<<8)+TL0)*0.017*100;//保留两位小数
	}

}