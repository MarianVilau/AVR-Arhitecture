#ifndef LED_H
#define LED_H

#include <iom324pb.h>
#include "pins.h"

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

void led_PowerOn(uint8_t indexLED);
void led_PowerOff(uint8_t indexLED);
void led_set_as_output(uint8_t indexLED);
void led_PowerOff_all();
void led_PowerOn_all();

void led_PowerOn_OLED1();
void led_PowerOff_OLED1();

void led_init();
void led_change(uint8_t indexLED);

void Blink_Fast(uint8_t indexLED, uint8_t milli);
void Blink_Slow(uint8_t indexLED, uint8_t milli);

#endif