#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h" // Heder fil med källkod samt anvisningar för STM projekt
#include <stdio.h> // Inkluderar standard biblotek för C

void USART2_Init(void); // Kallar på uart funktionen
void test_setup(void); // Kallar på testfunktion i uart.c
#endif // Heder fil avslutas