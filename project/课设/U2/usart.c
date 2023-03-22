#include "usart.h"

u8 receiveData[10],num=0,i,count=0;
u8 allData[8][10];

//���ڳ�ʼ�������ò�����Ϊ4800��ʹ�ö�ʱ��1,����Ƶ��12Mhz
void UART_Init()
{
    SCON=0X50;			//����Ϊ������ʽ1
    TMOD=0X20;			//���ü�����1 ������ʽ2
    PCON=0X80;			//�����ʼӱ�
    TH1=0XF3;			//��������ʼֵ���ã�ע�Ⲩ������4800��
    TL1=0XF3;			//����ֵ
    ES=1;				//�򿪽����ж�  �ӻ�����
    EA=1;				//�����ж�
    TR1=1;				//�򿪼�����
}


void UART_Interrupt(void) interrupt 4 //�����жϷ������
{
    if (RI)//�ж��ǽ����жϲ���
    {
        RI = 0; //��־λ����
        receiveData[num] = SBUF; //��ȡ����
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
                //��һ����ʾ
                LcdWriteCom(0x80);
				LcdWriteData(count-1+'0');
				LcdWriteData(' ');
                for(i=0; i<10; i++)
                {
                    LcdWriteData(allData[count-1][i]);
                }
            }

            //���յ������ݸ���
			if(count==7)
				count=0;
			else
				count++;

        }
    }
}