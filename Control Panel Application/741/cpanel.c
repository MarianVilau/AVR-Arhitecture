#include "cpanel.h"
#include "led.h"
#include "btn.h"
#include "gpio.h"

#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3

#define SW0 0
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3

void cpanel_setup_all_BTN()
{
  btn_set_as_input(SW0);
  btn_set_as_input(BUTTON1);
  btn_set_as_input(BUTTON2);
  btn_set_as_input(BUTTON3);
}

void cpanel_setup_all_LED()
{
  led_set_as_output(LED0);
  led_set_as_output(LED1);
  led_set_as_output(LED2);
  led_set_as_output(LED3);
}

void cpanel_BTNx_control_LEDx(unsigned int indexBTN, unsigned int indexLED)
{
  int btn_state = btn_read_state(indexBTN);
  (btn_state==1) ? led_PowerOn(indexLED) : led_PowerOff(indexLED);
}

void cpanel_BTNx_turn_on_LEDx(unsigned int indexBTN, unsigned int indexLED)
{
  int btn_state = btn_read_state(indexBTN);
  if(btn_state==1) led_PowerOn(indexLED);
}

void cpanel_BTNx_control_LEDx_press2(unsigned int indexBTN, unsigned int indexLED)
{
  int btn_state = btn_read_state(indexBTN);
  if(btn_state==1)
  {
    hardware_delay(100);
    if(btn_state==1) led_PowerOff(indexLED);
  }
}

void cpanel_SW0_turn_on_only_LED0()
{
  int btn_state = btn_read_state(SW0);
  if(btn_state==1){
    led_PowerOn(LED0);
    led_PowerOff(LED1);
    led_PowerOff(LED2);
    led_PowerOff(LED3);
  }
}