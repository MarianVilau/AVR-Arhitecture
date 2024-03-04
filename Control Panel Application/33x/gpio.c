#include "gpio.h"

void software_delay(unsigned long millisec) {
    unsigned long loop_count = millisec;
    while (loop_count--) {
        for (volatile int i = 0; i < 300; i++);
    }
}