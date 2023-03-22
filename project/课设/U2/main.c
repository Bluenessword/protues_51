#include "reg52.h"
#include "lcd.h"
#include "usart.h"
#include "key.h"

extern u8 allData[8][10];
u8 n=0,m;

void main(void)
{
    u8 i;
    u8 key;
    beep=0;  //¾²Òô·äÃùÆ÷
    LcdInit();
    delay(100);
    UART_Init();

    while(1)
    {
        key=KEY_Scan();	
        switch(key)
        {
        case KEY1_PRESS:
            if(n==0)
                n=8;
			n--;
            if(n==7)
                m=0;
            else
                m=n+1;

            LcdWriteCom(0x80);
			LcdWriteData(n+'0');
			LcdWriteData(' ');
            for(i=0; i<10; i++)
            {
                LcdWriteData(allData[n][i]);
            }
            LcdWriteCom(0x80+0x40);
			LcdWriteData(m+'0');
			LcdWriteData(' ');
            for(i=0; i<10; i++)
            {
                LcdWriteData(allData[m][i]);
            }
            break;
			
        case KEY2_PRESS:
            n++;
            if(n==8)
                n=0;
            if(n==7)
                m=0;
            else
                m=n+1;
			
            LcdWriteCom(0x80);
			LcdWriteData(n+'0');
			LcdWriteData(' ');
            for(i=0; i<10; i++)
            {
                LcdWriteData(allData[n][i]);
            }
            LcdWriteCom(0x80+0x40);
			LcdWriteData(m+'0');
			LcdWriteData(' ');
            for(i=0; i<10; i++)
            {
                LcdWriteData(allData[m][i]);
            }
            break;
			
        case KEY3_PRESS:
            LcdWriteCom(0x01);
            break;
        }


    };
}
