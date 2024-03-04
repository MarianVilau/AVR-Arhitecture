#ifndef LED_H
#define LED_H

#include <iom324pb.h>
#include "pins.h"

void led_PowerOn(int indexLED);
void led_PowerOff(int indexLED);
void led_set_as_output(int indexLED);
void led_PowerOff_all();
void led_PowerOn_all();

void led_PowerOn_OLED1();
void led_PowerOff_OLED1();

void led_init();
void led_change(int indexLED);

void Blink_Fast(int indexLED, int milli);
void Blink_Slow(int indexLED, int milli);

#endif