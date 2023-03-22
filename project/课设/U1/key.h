#ifndef __KEY_H
#define __KEY_H
#include "reg52.h"
typedef unsigned int u16;	  //对数据类型进行声明定义
sbit KEY1=P1^7;
sbit KEY2=P1^6;
#define KEY1_PRESS 1
#define KEY2_PRESS 2

unsigned char KEY_Scan();
void delay(u16 i);

#endif
