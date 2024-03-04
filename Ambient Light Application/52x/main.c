#include <iom324pb.h>
#include "scheduler.h"
#include "led.h"

#ifndef __uint16_t_defined
typedef unsigned short int        uint16_t;
# define __uint16_t_defined
#endif

#ifndef __uint32_t_defined
typedef unsigned int                uint32_t;
# define __uint32_t_defined
#endif

volatile uint32_t system_tick = 0;

void Timer0_Init() {
  //10ms period
    OCR0A = 124;
    TIMSK0 = (1 << TIMSK0_OCIE0A);
    TCCR0A = (1 << TCCR0A_WGM01);
    TCCR0B = (1 << TCCR0B_CS01) | (1 << TCCR0B_CS00);
}

#pragma vector=TIMER0_OVF_vect
__interrupt void TIMER0_CTC_ISR(void) {
    system_tick++;

    if (system_tick % 1 == 0) {
        set_flags(get_flags() | FLAG_10MS);
    }
    if (system_tick % 5 == 0) {
        set_flags(get_flags() | FLAG_50MS);
    }
    if (system_tick % 10 == 0) {
        set_flags(get_flags() | FLAG_100MS);
    }
    if (system_tick % 50 == 0) {
        set_flags(get_flags() | FLAG_500MS);
    }
    if (system_tick % 100 == 0) {
        set_flags(get_flags() | FLAG_1000MS);
    }
}
void main(void) {
    SREG |= (1 << 7); 
    led_init();
    Timer0_Init();

    while (1) {
        scheduler_flags_management();
    }
}
