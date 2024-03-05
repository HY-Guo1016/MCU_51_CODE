#include <reg51.h>
#include "delay.h"
#include "display.h"

void main()
{
	
	unsigned int i;
	unsigned char wnd=1;
	long parm1 = 124685;
	long parm2 = 255454;
	long parm3 = 323755;
	long parm4 = 247552;
	long parm5 = 214554;
	long parm6 = 577589;
	for(i=0;i<300;i++)
	{
		display();
	}
		
	while(1)
	{
		switch(wnd)
		{
			case 1:
				LEDBUF[0] = 1;
				LEDBUF[1] = 22;
				LEDBUF[2] = parm1/100000;
				LEDBUF[3] = parm1/10000%10;
				LEDBUF[4] = parm1/1000%10;
				LEDBUF[5] = parm1/100%10;
				LEDBUF[6] = parm1/10%10;
				LEDBUF[7] = parm1%10;
				for(i=0;i<500;i++)
				{
					display();
				}
				wnd++;
				break;
			case 2:
				LEDBUF[0] = 2;
				LEDBUF[1] = 22;
				LEDBUF[2] = parm2/100000;
				LEDBUF[3] = parm2/10000%10;
				LEDBUF[4] = parm2/1000%10;
				LEDBUF[5] = parm2/100%10;
				LEDBUF[6] = parm2/10%10;
				LEDBUF[7] = parm2%10;
				for(i=0;i<500;i++)
				{
					display();
				}
				wnd++;
				break;
			case 3:
				LEDBUF[0] = 3;
				LEDBUF[1] = 22;
				LEDBUF[2] = parm3/100000;
				LEDBUF[3] = parm3/10000%10;
				LEDBUF[4] = parm3/1000%10;
				LEDBUF[5] = parm3/100%10;
				LEDBUF[6] = parm3/10%10;
				LEDBUF[7] = parm3%10;
				for(i=0;i<500;i++)
				{
					display();
				}
				wnd++;
				break;
			case 4:
				LEDBUF[0] = 4;
				LEDBUF[1] = 22;
				LEDBUF[2] = parm4/100000;
				LEDBUF[3] = parm4/10000%10;
				LEDBUF[4] = parm4/1000%10;
				LEDBUF[5] = parm4/100%10;
				LEDBUF[6] = parm4/10%10;
				LEDBUF[7] = parm4%10;
				for(i=0;i<500;i++)
				{
					display();
				}
				wnd++;
				break;
			case 5:
				LEDBUF[0] = 5;
				LEDBUF[1] = 22;
				LEDBUF[2] = parm5/100000;
				LEDBUF[3] = parm5/10000%10;
				LEDBUF[4] = parm5/1000%10;
				LEDBUF[5] = parm5/100%10;
				LEDBUF[6] = parm5/10%10;
				LEDBUF[7] = parm5%10;
				for(i=0;i<500;i++)
				{
					display();
				}
				wnd++;
				break;
			case 6:
				LEDBUF[0] = 6;
				LEDBUF[1] = 22;
				LEDBUF[2] = parm6/100000;
				LEDBUF[3] = parm6/10000%10;
				LEDBUF[4] = parm6/1000%10;
				LEDBUF[5] = parm6/100%10;
				LEDBUF[6] = parm6/10%10;
				LEDBUF[7] = parm6%10;
				for(i=0;i<500;i++)
				{
					display();
				}
				wnd=1;
				break;
			
			default:break;
			}
	}
}