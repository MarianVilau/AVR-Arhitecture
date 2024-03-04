#include <iom324pb.h>
#include "scheduler.h"
#include "cpanel.h"
#include "led.h"
#include "btn.h"
#include "gpio.h"

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

void hw_init()
{
    scheduler_HW_init();
    cpanel_setup_all_BTN();
    cpanel_setup_all_LED();
    led_PowerOff_OLED1();
    Timer0_Init();
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
    hw_init();
    
    while (1) {
        scheduler_flags_management();
    }
}
