#include "led.h"
#include "gpio.h"
#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3
#define LED_IO1 4
#define OUTPUT 1

void led_PowerOn(uint8_t indexLED)
{
    switch (indexLED) {
        case LED0:
            reset_pin(&PORTC, 7);
            break;
        case LED1:
            reset_pin(&PORTD, 5);
            break;
        case LED2:
            reset_pin(&PORTD, 4);
            break;
        case LED3:
            reset_pin(&PORTA,3);
            break;
        case LED_IO1:
            reset_pin(&PORTB,3);
            break;
    }
}

void led_PowerOff(uint8_t indexLED)
{
    switch (indexLED) {
        case LED0:
            set_pin(&PORTC, 7);
            break;
        case LED1:
            set_pin(&PORTD, 5);
            break;
        case LED2:
            set_pin(&PORTD, 4);
            break;
        case LED3:
            set_pin(&PORTA,3);
            break;
        case LED_IO1:
            set_pin(&PORTB,3);
            break;
    }
}

void led_set_as_output(uint8_t indexLED)
{
    switch (indexLED) {
        case LED0:
            set_direction(&DDRC, 7,OUTPUT);
            break;
        case LED1:
            set_direction(&DDRD, 5,OUTPUT);
            break;
        case LED2:
            set_direction(&DDRD, 4,OUTPUT);
            break;
        case LED3:
            set_direction(&DDRA, 3,OUTPUT);
            break;
        case LED_IO1:
            set_direction(&DDRB, 3,OUTPUT);
            break;
    }
}

void led_change(uint8_t indexLED)
{
      switch (indexLED) {
        case LED0:
            toggle_pin(&PORTC, 7);
            break;
        case LED1:
            toggle_pin(&PORTD, 5);
            break;
        case LED2:
            toggle_pin(&PORTD, 4);
            break;
        case LED3:
            toggle_pin(&PORTA,3);
            break;
        case LED_IO1:
            toggle_pin(&PORTB,3);
            break;
    }
}

void led_PowerOff_all()
{
  led_PowerOff(LED0);
  led_PowerOff(LED1);
  led_PowerOff(LED2);
  led_PowerOff(LED3);
  led_PowerOff(LED_IO1);
}

void led_PowerOn_all()
{
  led_PowerOn(LED0);
  led_PowerOn(LED1);
  led_PowerOn(LED2);
  led_PowerOn(LED3);
  led_PowerOn(LED_IO1);
}

void led_PowerOn_OLED1()
{
  led_PowerOn(LED1);
  led_PowerOn(LED2);
  led_PowerOn(LED3);
}

void led_PowerOff_OLED1()
{
  led_PowerOff(LED1);
  led_PowerOff(LED2);
  led_PowerOff(LED3);
}

void Blink_Fast(uint8_t indexLED, uint8_t milli)
{
  for(uint8_t i=0;i<6;i++){
      led_PowerOn(indexLED);
      software_delay(milli);
      led_PowerOff(indexLED);
      software_delay(milli);
  }
}
void Blink_Slow(uint8_t indexLED, uint8_t milli)
{
  for(uint8_t i=0;i<4;i++){
      led_PowerOn(indexLED);
      software_delay(milli);
      led_PowerOff(indexLED);
      software_delay(milli);
  }
}

void led_init()
{
  led_set_as_output(LED0);
  led_set_as_output(LED1);
  led_set_as_output(LED2);
  led_set_as_output(LED3);
  led_set_as_output(LED_IO1);
  led_PowerOff_all();
}