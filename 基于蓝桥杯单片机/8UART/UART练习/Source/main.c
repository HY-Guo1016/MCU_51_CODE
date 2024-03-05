#include <reg51.h>
#include "time.h"
#include "key.h"
#include "UART.h"
#include <intrins.h>
void Rec_Ser();
void disp_ser();
unsigned int a=10;
void main()
{
	UartInit();
	Timer0_Init();
	EA = 1;
	while(1)
	{
		//Rec_Ser();
		printf("woainiliumenghan:%d\n\r",a);
		//Delayxms(1000);
	}
}

//void disp_ser()
//{
//	switch(KeyScan())
//	{
//		case 4:
//			LEDBUF[0] = 0;
//			break;
//		case 5:
//			LEDBUF[0] = 1;
//			break;
//		case 6:
//			LEDBUF[0] = 2;
//			break;
//		case 7:
//			LEDBUF[0] = 3;
//			break;
//		case 8:
//			LEDBUF[0] = 4;
//			break;
//		case 9:
//			LEDBUF[0] = 5;
//			break;
//		case 10:
//			LEDBUF[0] = 6;
//			break;
//		case 11:
//			LEDBUF[0] = 7;
//			break;
//		case 12:
//			LEDBUF[0] = 8;
//			break;
//		case 13:
//			LEDBUF[0] = 9;
//			break;
//		case 14:
//			LEDBUF[0] = 10;
//			break;
//		case 15:
//			LEDBUF[0] = 11;
//			break;
//		case 16:
//			LEDBUF[0] = 12;
//			break;
//		case 17:
//			LEDBUF[0] = 13;
//			break;
//		case 18:
//			LEDBUF[0] = 14;
//			break;
//		case 19:
//			LEDBUF[0] = 15;
//			break;
//	}
//	
//}
void Rec_Ser()
{
	if((_testbit_ (Rec_Flag)))
	{
		SendString(Rec_BUF);
		clr_Rec_BUF();
	}
	//Sendbyte(Rec_dat);
//	if((_testbit_ (Rec_Flag)))
//	{
//		switch(Rec_dat)
//		{
//			case 'a':
//				P0 = 0xFE;
//				P2 = (P2&0x1F)|0x80;
//				P2 = P2&0x1F;
//				break;
//			case 'b':
//				P0 = 0xFD;
//				P2 = (P2&0x1F)|0x80;
//				P2 = P2&0x1F;
//				break;
//			case 'c':
//				P0 = 0xFB;
//				P2 = (P2&0x1F)|0x80;
//				P2 = P2&0x1F;
//				break;
//			case 'd':
//				P0 = 0xF7;
//				P2 = (P2&0x1F)|0x80;
//				P2 = P2&0x1F;
//				break;
//		}
//	}
}