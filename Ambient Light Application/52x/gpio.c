#include "gpio.h"

void software_delay(unsigned long millisec) {
    unsigned long loop_count = millisec;
    while (loop_count--) {
        for (volatile int i = 0; i < 300; i++);
    }
}
void hardware_delay(unsigned long milliseconds) {
    // Set Timer0 in CTC mode with prescaler 64
    TCCR0A = (1 << TCCR0A_WGM01);
    TCCR0B = (1 << TCCR0B_CS01) | (1 << TCCR0B_CS00);
    OCR0A = 125;  // 1 ms delay with 8 MHz clock and prescaler 64
    
    // Enable Timer0 compare match A interrupt
    TIMSK0 |= (1 << TIMSK0_OCIE0A);
    
    // Start the delay loop
    for (unsigned volatile long i = 0; i < milliseconds*8; i++) {
        TCNT0 = 0;  // Reset the Timer0 counter
        while (!(TIFR0 & (1 << TIFR0_OCF0A)));  // Wait for the Timer0 compare match A flag
        TIFR0 |= (1 << TIFR0_OCF0A);  // Clear the Timer0 compare match A flag
    }
}

