#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

//At 1 MHz, BAUD set to 2400 worked. 9600 did not work.
// http://wormfood.net/avrbaudcalc.php
// conceptually 4800 also should work
#define BAUD 2400UL                           // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)    // set baudrate value for UBRR

#ifndef F_CPU
#define F_CPU 1000000UL                    // set the CPU clock
#endif

/*
 * Perform UART startup initialization.
 */
void uart_init(void);

/*
 * Send one character to the UART.
 */
void uart_transmit(unsigned char c);

unsigned char uart_recieve(void);
void uart_print(const char *p);

#endif //UART_H
