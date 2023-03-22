#ifndef __UART__
#define __UART__
#include "reg52.h"
#include "string.h"
#include "lcd.h"
#include "key.h"
typedef unsigned char u8;
sbit beep=P2^3;
void UART_Init();

#endif
