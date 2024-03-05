#include <reg51.h>
#include "delay.h"

void UartInit(void);		//4800bps@11.0592MHz
void SendByte(unsigned char dat);

unsigned char dat = 55;
void main()
{
	UartInit();
	while(1)
	{
		SendByte(0x88);
		
	}

}

void UartInit(void)		//4800bps@11.0592MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFA;			//���ö�ʱ��ʼֵ
	TH1 = 0xFA;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
}

void SendByte(unsigned char dat)
{
	SBUF = dat;
	while(!TI);
	Delay1000ms();
	TI = 0;

}