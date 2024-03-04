#include "scheduler.h"
#include "led.h"

volatile uint8_t flags = 0;

TaskFunction task_10ms_ptr = task_10ms;
TaskFunction task_50ms_ptr = task_50ms;
TaskFunction task_100ms_ptr = task_100ms;
TaskFunction task_500ms_ptr = task_500ms;
TaskFunction task_1000ms_ptr = task_1000ms;

void scheduler_init() {
    // Set compare values for different time periods
    OCR0A = 0x9C;   // 10ms
    OCR0B = 0x4E;   // 50ms
    OCR1A = 0x1F4;  // 100ms
    OCR1B = 0x7D0;  // 500ms
    OCR3A = 0x3E8;  // 1000ms

    // Set Timer/Counter 0 to CTC mode with OCR0A as TOP
    TCCR0A = (1 << TCCR0A_WGM01);

    // Set Timer/Counter 1 to CTC mode with OCR1A/B as TOP
    TCCR1A = 0;
    TCCR1B = (1 << TCCR1B_WGM12);

    // Set Timer/Counter 3 to CTC mode with OCR3A as TOP
    TCCR3A = 0;
    TCCR3B = (1 << TCCR3B_WGM32);

    // Set prescaler to 64 for Timer/Counter 0
    TCCR0B = (1 << TCCR0B_CS01) | (1 << TCCR0B_CS00);

    // Set prescaler to 64 for Timer/Counter 1
    TCCR1B = (1 << TCCR1B_CS11) | (1 << TCCR1B_CS10);

    // Set prescaler to 64 for Timer/Counter 3
    TCCR3B = (1 << TCCR3B_CS31) | (1 << TCCR3B_CS30);

    // Enable Timer/Counter 0, 1, 3 Compare Match A interrupts
    TIMSK0 = (1 << TIMSK0_OCIE0A);
    TIMSK1 = (1 << TIMSK1_OCIE1A) | (1 << TIMSK1_OCIE1B);
    TIMSK3 = (1 << TIMSK3_OCIE3A);
}

void scheduler_flags_management() {
    if (flags & FLAG_10MS) {
        task_10ms_ptr();
        flags &= ~FLAG_10MS;
    }

    if (flags & FLAG_50MS) {
        task_50ms_ptr();
        flags &= ~FLAG_50MS;
    }

    if (flags & FLAG_100MS) {
        task_100ms_ptr();
        flags &= ~FLAG_100MS;
    }

    if (flags & FLAG_500MS) {
        task_500ms_ptr();
         flags &= ~FLAG_500MS;
    }

    if (flags & FLAG_1000MS) {
        task_1000ms_ptr();
        flags &= ~FLAG_1000MS;
    }
}


uint8_t get_flags(void) {
    return flags;
}

void set_flags(uint8_t new_flags) {
    flags = new_flags;
}