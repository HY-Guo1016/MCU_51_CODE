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
	unsigned char code HC138[] = {0xFF,0xFB,0xF7,0xF3,0xEF,0xEB,0xE7,0xE3};
		//{0xE3,0xE7,0xEB,0xEF,0xF3,0xF7,0xFB,0xFF};
	
	//λѡ��̬�����
	unsigned char LEDBUF[] = {22,22,22,22,22,22,22,22};
	//���ݻ����� 
	
void display()
{
	
	unsigned char i;
	for(i=0;i<8;i++)
	{
	//���Ƚ��ж�ѡ
	GPIO_DIG = leddata[LEDBUF[i]];
	//Ȼ�����λѡ
	GPIO_PLACE = HC138[i];
	//֮�������ʱ
	Delayxms(1);
	//ͨ��iʵ�ֶ�̬�����
	GPIO_DIG = 0x00;
	//ʵ����Ӱ
	
	}

}
	
	
	
	