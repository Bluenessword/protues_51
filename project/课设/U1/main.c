#include "reg52.h"			 
#include "lcd.h"
#include "usart.h"
#include "key.h"
#include "stdlib.h"

u8 CHAR[]="      CHAR";
u8 DIGIT[]="      DIGIT";
u8 send[10]={0};//发送字符串
u8 flag=0;  	//0为字符模式 1为数字模式

//产生随机字符
char* getRandomString(u8 string[],u8 length,u8 flag)
{
	u8 i;
	srand(TL1);
	if(!flag)
	{
		for (i = 0; i < length; i++)
		{
			flag = rand() % 2;
			switch (flag)
			{
				case 0:
					string[i] = 'A' + rand() % 26;
					break;
				case 1:
					string[i] = 'a' + rand() % 26;
					break;
			}
		}
		return string;	
	}
	else
	{
		for (i = 0; i < length; i++)
		{
			string[i] = '0' + rand() % 10;
		}
		return string;
	}

}


void main(void)
{
	u8 i;
	u8 key;
	LcdInit();
	UART_Init();
	for(i=0;i<sizeof(CHAR)/sizeof(CHAR[0]);i++)
	{
		LcdWriteData(CHAR[i]);	
	}
	while(1)
	{
		key=KEY_Scan();
        switch(key)
        {
			case KEY1_PRESS:
				flag=~flag;
				if(!flag)
				{
					LcdWriteCom(0x80);
					for(i=0;i<sizeof(CHAR)/sizeof(CHAR[0]);i++)
					{
						LcdWriteData(CHAR[i]);	
					}
					getRandomString(send,10,flag);
					LcdWriteCom(0x80+0x40);
					for(i=0;i<sizeof(send)/sizeof(send[0]);i++)
					{
						LcdWriteData(send[i]);	
					}
				}
				else
				{
					LcdWriteCom(0x80);
					for(i=0;i<sizeof(DIGIT)/sizeof(DIGIT[0]);i++)
					{
						LcdWriteData(DIGIT[i]);	
					}
					getRandomString(send,10,flag);
					LcdWriteCom(0x80+0x40);
					for(i=0;i<sizeof(send)/sizeof(send[0]);i++)
					{
						LcdWriteData(send[i]);	
					}
				}
				break;
			case KEY2_PRESS:
				if(send[0]!=0)
					UART_SendStr(send,sizeof(send)/sizeof(send[0]));
				break;
        }
	};				
}
