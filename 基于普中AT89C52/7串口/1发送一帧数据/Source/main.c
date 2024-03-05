#include <reg51.h>
#include "delay.h"
void UartInit(void);

void main()
{
	UartInit();
	while(1)
	{
		SBUF = 'a';
		while(!TI);
			TI = 0;
		SBUF = 'b';
		while(!TI);
			TI = 0;
		Delayxms(1000);
	}
}

void UartInit(void)		//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFA;		//���ö�ʱ��ʼֵ
	TH1 = 0xFA;		//���ö�ʱ����ֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
}
