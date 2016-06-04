#include "uart.h"

// function to initialize UART
void uart_init (void)
{
   UBRRH = (BAUDRATE>>8);
   UBRRL = BAUDRATE;                         //set baud rate
   UCSRB |= (1<<TXEN) | (1<<RXEN);             //enable receiver and transmitter
   UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);// 8bit data format
}

// function to send data - NOT REQUIRED FOR THIS PROGRAM IMPLEMENTATION
void uart_transmit (unsigned char data)
{
   //both lines are same.
   //while (!( UCSRA & (1<<UDRE)));            // wait while register is free
   loop_until_bit_is_set(UCSRA, UDRE);
   UDR = data;                             // load data in the register
}

void uart_print(const char *USART_String)
{
   uint8_t c;
   while ((c=*USART_String++))
     {
        uart_transmit(c);
     }
}//USART_Print

// function to receive data
unsigned char uart_recieve (void)
{
   //both statements are same
   //while(!(UCSRA & (1<<RXC)));           // wait while data is being received
   loop_until_bit_is_set(UCSRA, RXC);
   return UDR;                             // return 8-bit data
}
