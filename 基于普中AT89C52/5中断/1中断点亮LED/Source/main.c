#include <reg51.h>
#include "delay.h"

void EX1_INT(void);
void main()
{
	EX1_INT();
	while(1)
	{
		
	}
}

void EX1_INT(void)//�жϵĳ�ʼ��
{
	IT1 = 1;   //�½��ش���
	EA = 1;    //���ж�������
	EX1 = 1;   //�ⲿ�ж�0������
}

void EX1_ISR(void) interrupt 2 //�ⲿ�ж�1����
{
	Delayxms(1200);
	P2 = ~P2;
}