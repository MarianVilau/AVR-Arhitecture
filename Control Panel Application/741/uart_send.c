#include "uart_send.h"

void uart_send_byte(uint8_t data) {
     // Wait for the transmit buffer to be ready
    while (UCSR2A_UDRE ==0);
    // Put the data into the transmit buffer
    UDR2 = data;
}
