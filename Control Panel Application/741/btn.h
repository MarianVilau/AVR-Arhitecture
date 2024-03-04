#ifndef BTN_H
#define BTN_H

#include <iom324pb.h>

int btn_read_state(unsigned int indexBTN);
void btn_set_as_input(unsigned int indexBTN);
unsigned char btn_state(unsigned int indexBTN);

void btn_debounce_delay(int milli);
int btn_read_states();

#endif