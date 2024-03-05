#include <reg51.h>
#include "display.h"
#include "delay.h"

void EX0_INT(void);
void EX1_INT(void);
void display_service();
unsigned long param = 0;

void main()
{
	EX0_INT();
	EX1_INT();
	EA = 1;
	
	while(1)
	{
		display_service();
	}
}


void display_service()
{
	LEDBUF[7] = param/100000%10;
	LEDBUF[6] = param/10000%10;
	LEDBUF[5] = param/10000%10;
	LEDBUF[4] = param/1000%10;
	LEDBUF[3] = param/100%10;
	LEDBUF[2] = param/100%10;
	LEDBUF[1] = param/10%10;
	LEDBUF[0] = param%10;	
	display();
	
}
void EX0_INT(void)
{
	IT0 = 1;
	EX0 = 1;

}

void EX1_INT(void)
{
	IT1 = 1;
	EX1 = 1;

}

void EX0_ISR(void) interrupt 0
{
	Delayxms(20);
	if(INT0 == 0)
	{
	param++;
	if(param > 99999999)
		param = 0;
	}
}

void EX1_ISR(void) interrupt 2
{
	Delayxms(20);
	if(INT1 == 0)
	{
	param--;
	if(param > 99999999)
		param = 99999999;
	}
}