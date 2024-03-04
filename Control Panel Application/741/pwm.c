#include "pwm.h"

#define LED1 5
#define LED2 4
#define LED_IO1 3

void pwm_init() {
     // Set LED pins as outputs
    DDRD |= (1 << LED1) | (1 << LED2);
    DDRB |= (1 << LED_IO1);

    // Set Timer/Counter1 (16-bit) to Fast PWM mode with TOP value as MAX_PWM_VALUE
    TCCR1A = (1 << TCCR1A_COM1A1) | (1 << TCCR1A_COM1B1) | (1 << TCCR1A_WGM11);
    TCCR1B = (1 << TCCR1B_WGM13) | (1 << TCCR1B_WGM12);

    // Calculate the PWM prescaler based on system frequency and desired PWM frequency
    uint16_t prescaler = F_CPU / (PWM_FREQ_HZ * MAX_PWM_VALUE);

    // Set the appropriate PWM prescaler
    if (prescaler >= 1) {
        TCCR1B |= (1 << TCCR1B_CS10);      // No prescaler
    } else if (prescaler >= 8) {
        TCCR1B |= (1 << TCCR1B_CS11);      // Prescaler 8
    } else if (prescaler >= 64) {
        TCCR1B |= (1 << TCCR1B_CS11) | (1 << TCCR1B_CS10);   // Prescaler 64
    } else if (prescaler >= 256) {
        TCCR1B |= (1 << TCCR1B_CS12);      // Prescaler 256
    } else if (prescaler >= 1024) {
        TCCR1B |= (1 << TCCR1B_CS12) | (1 << TCCR1B_CS10);   // Prescaler 1024
    }

    // Set the initial PWM duty cycle to 0%
    pwm_set_duty_cycle(0);
    
    // Enable Timer/Counter1 Overflow Interrupt
    TIMSK1 = (1 << TIMSK1_TOIE1);
    
    // Set the Global Interrupt Enable bit
    SREG = (1 << 7);
}

void pwm_set_duty_cycle(uint8_t duty) {
     // Ensure that the duty cycle is within the valid range (0 to MAX_PWM_VALUE)
    duty_cycle = (duty > MAX_PWM_VALUE) ? MAX_PWM_VALUE : duty;
    
    // Update the PWM duty cycle by loading the value into OCR1A and OCR1B registers
    OCR1A = (duty_cycle * MAX_PWM_VALUE) / 100;
    OCR1B = (duty_cycle * MAX_PWM_VALUE) / 100;
}
