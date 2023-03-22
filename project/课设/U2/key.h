#ifndef __KEY_H
#define __KEY_H
#include "reg52.h"
typedef unsigned int u16;	  //对数据类型进行声明定义
sbit KEY1=P2^0;
sbit KEY2=P2^1;
sbit KEY3=P2^2;
#define KEY1_PRESS 1
#define KEY2_PRESS 2
#define KEY3_PRESS 3

unsigned char KEY_Scan();
void delay(u16 i);

#endif
