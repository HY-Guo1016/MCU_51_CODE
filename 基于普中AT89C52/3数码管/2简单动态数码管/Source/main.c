#include <reg51.h>
#include "delay.h"

void main()
{
	unsigned char code leddata[]={ 
 
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
                0x77,  //"A"
                0x7C,  //"B"
                0x39,  //"C"
                0x5E,  //"D"
                0x79,  //"E"
                0x71,  //"F"
                0x76,  //"H"
                0x38,  //"L"
                0x37,  //"n"
                0x3E,  //"u"
                0x73,  //"P"
                0x5C,  //"o"
                0x40,  //"-"
                0x00,  //Ï¨Ãð
                0x00  //×Ô¶¨Òå
 
                         };
	unsigned char HC138[] = {0xE3,0xE7,0xEB,0xEF,0xF3,0xF7,0xFB,0xFF};
	long int i;
	while(1)
	{
		for(i=100;i>0;i--)
		{
			P2 = HC138[0];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[1];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[2];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[3];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[4];
			P0 = leddata[0];
			Delayxms(1);
			
			P2 = HC138[5];
			P0 = leddata[2];
			Delayxms(1);
			
			P2 = HC138[6];
			P0 = leddata[0];
			Delayxms(1);
			
			P2 = HC138[7];
			P0 = leddata[2];
			Delayxms(1);
		}
		
		for(i=100;i>0;i--)
		{
			P2 = HC138[0];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[1];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[2];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[3];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[4];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[5];
			P0 = leddata[0];
			Delayxms(1);
			
			P2 = HC138[6];
			P0 = leddata[2];
			Delayxms(1);
			
			P2 = HC138[7];
			P0 = leddata[0];
			Delayxms(1);
		}
		
		for(i=100;i>0;i--)
		{
			P2 = HC138[0];
			P0 = leddata[0];
			Delayxms(1);
			
			P2 = HC138[1];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[2];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[3];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[4];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[5];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[6];
			P0 = leddata[0];
			Delayxms(1);
			
			P2 = HC138[7];
			P0 = leddata[2];
			Delayxms(1);
		}
		
		for(i=100;i>0;i--)
		{
			P2 = HC138[0];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[1];
			P0 = leddata[0];
			Delayxms(1);
			
			P2 = HC138[2];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[3];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[4];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[5];
			P0 = leddata[4];
			Delayxms(1);
			
			P2 = HC138[6];
			P0 = leddata[1];
			Delayxms(1);
			
			P2 = HC138[7];
			P0 = leddata[0];
			Delayxms(1);
		}
	}
}