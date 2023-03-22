#include "reg52.h"
#include "usart.h"
//串口初始化，设置波特率为4800，使用定时器1,晶振频率12Mhz

void UART_Init()
{
    SCON=0X50;			//设置为工作方式1
    TMOD=0X20;			//设置计数器1 工作方式2
    PCON=0X80;			//波特率加倍
    TH1=0XF3;			//计数器初始值设置，注意波特率是4800的
    TL1=0XF3;			//重载值
    ES=0;				//关闭接收中断  主机只发送
    EA=1;				//打开总中断
    TR1=1;				//打开计数器
}
void UART_Send_Data(u8 byte)
{
    SBUF=byte;
    while(!TI);		//等待串口数据发送完毕
    TI=0;			//将发送中断标志位清0，为下次发送数据做准备
}

void UART_SendStr(u8 *s,u8 length)
{
	u8 num = 0x00;
	while (num < length) //发送长度对比
	{
		UART_Send_Data(*s);//放松单字节数据
		s++;			  //指针++
		num++;			  //下一个++
	}
}