#include "key.h"

unsigned char key_scan()
{
	unsigned char KeyNum = 0;
	if(!key1)
	{
		Delayxms(20);//��������
		if(!key1)
		{
			KeyNum = 1;
		}
	}while(!key1);//���ֵȴ�
		
	return KeyNum;
}