#ifndef __CX20106A_H__
#define __CX20106A_H__

#include <reg51.h>
#include "delay.h"

sbit WaveSend = P1^0;
sbit WaveRecv = P1^1;

void WaveS();
void WaveR(unsigned int *tmp);

#endif