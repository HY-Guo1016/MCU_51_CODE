#include <reg51.h>
#include "delay.h"
#include "display.h"
#include "key.h"

void Timer0_Init(void);

void main()
{
	LEDBUF[7] = 23;
	LEDBUF[6] = 23;
	LEDBUF[5] = 23;
	LEDBUF[4] = 23;
	LEDBUF[3] = 23;
	LEDBUF[2] = 23;
	Timer0_Init();
	while(1)
	{
		switch(key_scan())
		{
			case 4:
				LEDBUF[0] = 4/10;
				LEDBUF[1] = 4%10;
				break;
					
			case 5:
				LEDBUF[0] = 5/10;
				LEDBUF[1] = 5%10;;
				break;
							
			case 6:
				LEDBUF[0] = 6/10;
				LEDBUF[1] = 6%10;;
				break;
						
			case 7:
				LEDBUF[0] = 7/10;
				LEDBUF[1] = 7%10;
				break;
					
			case 8:
				LEDBUF[0] = 8/10;
				LEDBUF[1] = 8%10;
				break;
							
			case 9:
				LEDBUF[0] = 9/10;
				LEDBUF[1] = 9%10;
				break;
						
			case 10:
				LEDBUF[0] = 10/10;
				LEDBUF[1] = 10%10;
				break;
	
			case 11:
				LEDBUF[0] = 11/10;
				LEDBUF[1] = 11%10;
				break;
							
			case 12:
				LEDBUF[0] = 12/10;
				LEDBUF[1] = 12%10;
				break;
						
			case 13:
				LEDBUF[0] = 13/10;
				LEDBUF[1] = 13%10;
				break;
					
			case 14:
				LEDBUF[0] = 14/10;
				LEDBUF[1] = 14%10;
				break;
						
			case 15:
				LEDBUF[0] = 15/10;
				LEDBUF[1] = 15%10;
				break;
					
			case 16:
				LEDBUF[0] = 16/10;
				LEDBUF[1] = 16%10;
				break;
							
			case 17:
				LEDBUF[0] = 17/10;
				LEDBUF[1] = 17%10;
				break;
						
			case 18:
				LEDBUF[0] = 18/10;
				LEDBUF[1] = 18%10;
				break;
			
			case 19:
				LEDBUF[0] = 19/10;
				LEDBUF[1] = 19%10;
				break;
			default:break;
		}

	}

}


void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	ET0 = 1;
	EA = 1;
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}

void Timer0_ISR() interrupt 1
{
	TR0 = 0;
	display();
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TR0 = 1;

}