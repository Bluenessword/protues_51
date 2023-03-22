#ifndef __UART__
#define __UART__
typedef unsigned char u8;
void UART_Init();
void UART_Send_Data(u8 byte);
void UART_SendStr(u8 *s,u8 length);
#endif
