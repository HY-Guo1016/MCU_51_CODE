#include "display.h"

//��ѡ����
unsigned char code leddata[]={ 
 
                0xC0,  //"0"
                0xF9,  //"1"
                0xA4,  //"2"
                0xB0,  //"3"
                0x99,  //"4"
                0x92,  //"5"
                0x82,  //"6"
                0xF8,  //"7"
                0x80,  //"8"
                0x90,  //"9"
                0x88,  //"A"
                0x83,  //"B"
                0xC6,  //"C"
                0xA1,  //"D"
                0x86,  //"E"
                0x8E,  //"F"
                0x89,  //"H"
                0xC7,  //"L"
                0xC8,  //"n"
                0xC1,  //"u"
                0x8C,  //"P"
                0xA3,  //"o"
                0xBF,  //"-"
                0xFF,  //Ϩ��
                0xFF  //�Զ���
 
                         };
//λѡ����
unsigned char code place[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
//{0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//���ݻ�����
unsigned char LEDBUF[] = {23,23,23,23,23,23,23,23};
void display()
{
	static unsigned char i = 0;
	switch(i)
	{
		case 0:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i++;
		break;
		
		case 1:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i++;
		break;
		
		case 2:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i++;
		break;
						
		case 3:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i++;
		break;
								
		case 4:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i++;
		break;
								
		case 5:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]]&0x7F;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i++;
		break;
									
		case 6:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i++;
		break;
							
		case 7:
		//��Ӱ
		P0 = 0xFF;
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//�Ͷ���
		P0 = leddata[LEDBUF[i]];
		P2 = (P2 & 0x1f) | 0xE0;
		P2 = (P2 & 0x1f);
		//��λѡ
		P0 = place[i];
		P2 = (P2 & 0x1f) | 0xC0;
		P2 = (P2 & 0x1f);
		//ͨ��iʵ�������
		i=0;
		break;
		
		default:break;
	}
}