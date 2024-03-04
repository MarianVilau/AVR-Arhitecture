#include "uart_receive.h"

uint8_t uart_receive_byte(void) {
 // Wait for data to be received
    while (UCSR2A_RXC == 0);
    // Return the received data
    return UDR2;
}
