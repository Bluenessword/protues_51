#include "key.h"
typedef unsigned char u8;

//0 û�а������� 1��key1 2��key2
void delay(u16 i)
{
    while(i--);
}
u8 KEY_Scan()
{
    if(KEY1==0)
    {
        delay(100);
        if(KEY1==0)
		{
			delay(100);
			while(KEY1==0);
			return KEY1_PRESS;
		} 
    }
    if(KEY2==0) 
	{
        delay(100);
        if(KEY2==0)
		{
			delay(100);
			while(KEY2==0);
			return KEY2_PRESS;
		} 
    }
	if(KEY3==0) 
	{
        delay(100);
        if(KEY3==0)
		{
			delay(100);
			while(KEY3==0);
			return KEY3_PRESS;
		} 
    }
    return 0;//�ް�������
}
