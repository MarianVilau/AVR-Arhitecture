#include "pins.h"
#define OUTPUT 1
#define INPUT 0

void set_pin(unsigned volatile char* port, unsigned int pin_number) {
    *port |= (1 << pin_number);
}

void reset_pin(unsigned volatile char* port,unsigned int pin_number) {
    *port &= ~(1 << pin_number);
}

void set_direction(unsigned volatile char* ddr,unsigned int pin_number, unsigned int direction) {  /*1 for output, 0 for input*/
    (direction == OUTPUT) ? (*ddr |= (1 << pin_number)) : ((direction == INPUT) ? (*ddr &= (1 << pin_number)) : 0);
}

void toggle_pin(unsigned volatile char* port,unsigned int pin_number){
    *port^=(1<<pin_number);
}