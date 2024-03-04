#ifndef CPANEL_H
#define CPANEL_H

#include <iom324pb.h>
#include "pins.h"
#include "btn.h"

void cpanel_setup_all_BTN();
void cpanel_setup_all_LED();

void cpanel_BTNx_control_LEDx(unsigned int indexBTN, unsigned int indexLED);
void cpanel_BTNx_turn_on_LEDx(unsigned int indexBTN, unsigned int indexLED);
void cpanel_BTNx_control_LEDx_press2(unsigned int indexBTN, unsigned int indexLED);
void cpanel_SW0_turn_on_only_LED0();
#endif