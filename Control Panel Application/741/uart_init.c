#include "uart_init.h"

#define F_CPU 80000000UL
#define BAUD_RATE 9600

void uart_init() {
     // Set baud rate
    UBRR2 = F_CPU / (16 * BAUD_RATE) - 1;
    
    // Enable transmitter and receiver
    UCSR2B |= (1 << UCSR2B_TXEN) | (1 << UCSR2B_RXEN);

    // Set frame format: asynchronous, 8 data bits, even parity, 1 stop bit
    UCSR2C |= (1 << UCSR2C_UPM1) | (1 << UCSR2C_UCSZ1) | (1 << UCSR2C_UCSZ0);
}
