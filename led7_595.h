#ifndef __led7_595_h__
#define __led7_595_h__

#include "stdint.h"

#define DATACLOCK_PIN 0
#define STORAGECLOCK_PIN 4
#define DATA_PIN 5

#define SCAN 1

//extern uint8_t gLED[10];
//extern uint8_t gDigit[4];

extern void dataSend(uint8_t vData);
extern void dataLatch(uint8_t vData);
extern void ledDisplay(uint8_t vHour, uint8_t vMin);

#endif
