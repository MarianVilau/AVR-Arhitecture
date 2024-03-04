#include "led.h"
#include "gpio.h"
#include "sos.h"
#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3

void point()
{
  led_PowerOn(LED0);
  software_delay(85);
  led_PowerOff(LED0);
  software_delay(85);
  
}
void line()
{
  led_PowerOn(LED0);
  software_delay(125);
  led_PowerOff(LED0);
  software_delay(125);
}
void space()
{
  software_delay(250);
}

void s_letter()
{
  point();
  point();
  point();
}
void o_letter()
{
  line();
  line();
  line();
}