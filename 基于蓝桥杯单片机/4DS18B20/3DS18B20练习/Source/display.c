#include "display.h"

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
                0x00,  //Ϩ��
                0x00  //�Զ���
 
                         };
	//��ѡ��̬�����
	unsigned char code HC138[] = {0xE3,0xE7,0xEB,0xEF,0xF3,0xF7,0xFB,0xFF};
		
		//{0xFF,0xFB,0xF7,0xF3,0xEF,0xEB,0xE7,0xE3};
	
	//λѡ��̬�����
	unsigned char LEDBUF[] = {23,23,23,23,23,23,23,23};
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
	GPIO_DIG = leddata[LEDBUF[4]]|0x80;
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
	
	
	
	