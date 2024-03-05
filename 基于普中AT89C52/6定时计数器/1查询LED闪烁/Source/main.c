#include <reg51.h>

void timer0_Init();

sbit LED = P2^0;
void main()
{
	timer0_Init();
	while(1)
	{	if(TF0 == 1)
		{
		TF0 = 0;
		LED = ~LED;
		TH0 = (65536 - 50000)/256;
		TL0 = (65536 - 50000)%256;
		}
	}

}

void timer0_Init()
{
	TMOD = 0X01;//�趨��ʱ������0�Ĺ�����ʽ1
	//�趨��ʼ��ʱʱ��
	TH0 = (65536 - 50000)/256;
	TL0 = (65536 - 50000)%256;
	//��ʱ��������ʼ����
	TR0 = 1;
}