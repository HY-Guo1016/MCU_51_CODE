#include "display.h"

	unsigned char code leddata[]={ 
 
                0x3F,  //"0"  0
                0x06,  //"1"  1
                0x5B,  //"2"  2
                0x4F,  //"3"  3
                0x66,  //"4"  4
                0x6D,  //"5"  5
                0x7D,  //"6"  6
                0x07,  //"7"  7
                0x7F,  //"8"  8
                0x6F,  //"9"  9
                0x77,  //"A"  10 
                0x7C,  //"B"  11
                0x39,  //"C"  12
                0x5E,  //"D"  13
                0x79,  //"E"  14
                0x71,  //"F"  15
                0x76,  //"H"  16
                0x38,  //"L"  17 
                0x37,  //"n"  18 
                0x3E,  //"u"  19 
                0x73,  //"P"  20
                0x5C,  //"o"  21
                0x40,  //"-"  22
                0x00,  //Ϩ�� 23
                0x00  //�Զ���
 
                         };
	//��ѡ��̬�����
	unsigned char code HC138[] = {0xE3,0xE7,0xEB,0xEF,0xF3,0xF7,0xFB,0xFF};
		
		//{0xFF,0xFB,0xF7,0xF3,0xEF,0xEB,0xE7,0xE3};
	
	//λѡ��̬�����
	unsigned char LEDBUF[] = {8,8,8,8,8,8,8,8};
	//���ݻ����� 
	
void display()
{
	
	static unsigned char i = 0;
	switch(i)
	{
	case 0:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[0]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[0];
	//ͨ��iʵ�ֶ�̬�����
	i++;
	break;
	
	case 1:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[1]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[1];
	//ͨ��iʵ�ֶ�̬�����
	i++;
	break;
	
	case 2:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[2]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[2];
	//ͨ��iʵ�ֶ�̬�����
	i++;
	break;
	
	case 3:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[3]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[3];
	//ͨ��iʵ�ֶ�̬�����
	i++;
	break;		
	
	case 4:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[4]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[4];
	//ͨ��iʵ�ֶ�̬�����
	i++;
	break;
	
	case 5:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[5]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[5];
	//ͨ��iʵ�ֶ�̬�����
	i++;
	break;
	
	case 6:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[6]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[6];
	//ͨ��iʵ�ֶ�̬�����
	i++;
	break;
	
	case 7:
	//ʵ����Ӱ	
	GPIO_DIG = 0x00;
	//���ж�ѡ
	GPIO_DIG = leddata[LEDBUF[7]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[7];
	//ͨ��iʵ�ֶ�̬�����
	i = 0;
	break;
	
	default: break;
	}

}
	
	
	
	