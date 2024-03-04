#ifndef PINS_H
#define PINS_H

#include <iom324pb.h>

void set_pin(unsigned volatile char* port, unsigned int pin_number);
void reset_pin(unsigned volatile char* port,unsigned int pin_number);
void set_direction(unsigned volatile char* ddr,unsigned int pin_number, unsigned int direction);
void toggle_pin(unsigned volatile char* port,unsigned int pin_number);

#endif
