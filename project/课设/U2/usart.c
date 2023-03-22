#include "usart.h"

u8 receiveData[10],num=0,i,count=0;
u8 allData[8][10];

//串口初始化，设置波特率为4800，使用定时器1,晶振频率12Mhz
void UART_Init()
{
    SCON=0X50;			//设置为工作方式1
    TMOD=0X20;			//设置计数器1 工作方式2
    PCON=0X80;			//波特率加倍
    TH1=0XF3;			//计数器初始值设置，注意波特率是4800的
    TL1=0XF3;			//重载值
    ES=1;				//打开接收中断  从机接收
    EA=1;				//打开总中断
    TR1=1;				//打开计数器
}


void UART_Interrupt(void) interrupt 4 //串行中断服务程序
{
    if (RI)//判断是接收中断产生
    {
        RI = 0; //标志位清零
        receiveData[num] = SBUF; //提取数据
        num++;
        if(num==10)
        {
            num=0;
            beep=~beep;
            delay(50000);
            beep=~beep;
			
			strcpy(allData[count],receiveData);

            LcdWriteCom(0x80+0x40);
			LcdWriteData(count+'0');
			LcdWriteData(' ');
            for(i=0; i<10; i++)
            {
                LcdWriteData(allData[count][i]);
            }

            if(count>0)
            {
                //第一行显示
                LcdWriteCom(0x80);
				LcdWriteData(count-1+'0');
				LcdWriteData(' ');
                for(i=0; i<10; i++)
                {
                    LcdWriteData(allData[count-1][i]);
                }
            }

            //接收到的数据个数
			if(count==7)
				count=0;
			else
				count++;

        }
    }
}