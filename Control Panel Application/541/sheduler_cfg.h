#ifndef SCHEDULER_CFG_H
#define SCHEDULER_CFG_H

#include "scheduler.h"

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

// Function prototypes for required interfaces
void led_change(uint8_t indexLED);
void ADC_coversion();
void ADC_ambient_light();
void cpanel_master_control();
void cpanel_BTNx_control_LEDx(unsigned int indexBTN, unsigned int indexLED);

#endif
