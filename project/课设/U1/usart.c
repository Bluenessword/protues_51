#include "reg52.h"
#include "usart.h"
//���ڳ�ʼ�������ò�����Ϊ4800��ʹ�ö�ʱ��1,����Ƶ��12Mhz

void UART_Init()
{
    SCON=0X50;			//����Ϊ������ʽ1
    TMOD=0X20;			//���ü�����1 ������ʽ2
    PCON=0X80;			//�����ʼӱ�
    TH1=0XF3;			//��������ʼֵ���ã�ע�Ⲩ������4800��
    TL1=0XF3;			//����ֵ
    ES=0;				//�رս����ж�  ����ֻ����
    EA=1;				//�����ж�
    TR1=1;				//�򿪼�����
}
void UART_Send_Data(u8 byte)
{
    SBUF=byte;
    while(!TI);		//�ȴ��������ݷ������
    TI=0;			//�������жϱ�־λ��0��Ϊ�´η���������׼��
}

void UART_SendStr(u8 *s,u8 length)
{
	u8 num = 0x00;
	while (num < length) //���ͳ��ȶԱ�
	{
		UART_Send_Data(*s);//���ɵ��ֽ�����
		s++;			  //ָ��++
		num++;			  //��һ��++
	}
}