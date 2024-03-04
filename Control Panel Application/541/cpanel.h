#ifndef CPANEL_H
#define CPANEL_H

#include <iom324pb.h>
#include "pins.h"
#include "btn.h"

#ifndef __cplusplus
#define bool  _Bool
#define true  1
#define false 0
#endif

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

#define DEBOUNCE_THRESHOLD 5

void cpanel_setup_all_BTN();
void cpanel_setup_all_LED();

void cpanel_BTNx_control_LEDx(unsigned int indexBTN, unsigned int indexLED);
void cpanel_BTNx_turn_on_LEDx(unsigned int indexBTN, unsigned int indexLED);
void cpanel_BTNx_control_LEDx_press2(unsigned int indexBTN, unsigned int indexLED);
void cpanel_SW0_turn_on_only_LED0();
void cpanel_master_control();

void cpanel_debounce_buttons();
#endif
