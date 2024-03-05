#include <reg51.h>
#include "delay.h"
#include "display.h"
#include "key.h"

void dis_service();
void key_service();
unsigned int i;
unsigned char wnd=1;
long parm1 = 12685;
long parm2 = 25454;
long parm3 = 32755;
long parm4 = 24752;
void main()
{
	
	for(i=0;i<100;i++)//开机界面
	{
		display();
	}
		
	while(1)
	{
		dis_service();
		key_service();
		display();
	}
}


void dis_service()
{
	
	
	switch(wnd)
		{
			case 1:
				LEDBUF[0] = 20;
				LEDBUF[1] = 1;
				LEDBUF[2] = 22;
				LEDBUF[3] = parm1/10000%10;
				LEDBUF[4] = parm1/1000%10;
				LEDBUF[5] = parm1/100%10;
				LEDBUF[6] = parm1/10%10;
				LEDBUF[7] = parm1%10;
				break;
			case 2:
				LEDBUF[0] = 20;
				LEDBUF[1] = 2;
				LEDBUF[2] = 22;
				LEDBUF[3] = parm2/10000%10;
				LEDBUF[4] = parm2/1000%10;
				LEDBUF[5] = parm2/100%10;
				LEDBUF[6] = parm2/10%10;
				LEDBUF[7] = parm2%10;
				break;
			case 3:
				LEDBUF[0] = 20;
				LEDBUF[1] = 3;
				LEDBUF[2] = 22;
				LEDBUF[3] = parm3/10000%10;
				LEDBUF[4] = parm3/1000%10;
				LEDBUF[5] = parm3/100%10;
				LEDBUF[6] = parm3/10%10;
				LEDBUF[7] = parm3%10;
				break;
			case 4:
				LEDBUF[0] = 20;
				LEDBUF[1] = 4;
				LEDBUF[2] = 22;
				LEDBUF[3] = parm4/10000%10;
				LEDBUF[4] = parm4/1000%10;
				LEDBUF[5] = parm4/100%10;
				LEDBUF[6] = parm4/10%10;
				LEDBUF[7] = parm4%10;
				break;
			default:break;
			}
}

void key_service()
{
	switch(key_scan())
	{
		case 0:break;
		case 1:
			wnd++;
			if(wnd>4)
				wnd=1;
			break;
		case 2:
			switch(wnd)
			{
				case 1:
					parm1++;
					if(parm1>99999)
						parm1 = 0;
					break;
				case 2:
					parm2++;
					if(parm2>99999)
						parm2 = 0;
					break;
				case 3:
					parm3++;
					if(parm3>99999)
						parm3 = 0;
					break;
				case 4:
					parm4++;
					if(parm4>99999)
						parm4 = 0;
					break;
				default:break;
			}
			break;
		case 3:
			switch(wnd)
			{
				case 1:
					parm1--;
					if(parm1<0)
						parm1 = 99999;
					break;
				case 2:
					parm2--;
					if(parm2<0)
						parm2 = 99999;
					break;
				case 3:
					parm3--;
					if(parm3<0)
						parm3 = 99999;
					break;
				case 4:
					parm4--;
					if(parm4<0)
						parm4 = 99999;
					break;
				default:break;
			}
			break;
		case 4:
			switch(wnd)
			{
				case 1:
					parm1=0;
					break;
				case 2:
					parm2=0;
					break;
				case 3:
					parm3=0;
					break;
				case 4:
					parm4=0;
					break;
				default:break;
			}
			break;
		default:break;
	}
}
