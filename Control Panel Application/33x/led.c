#include "led.h"
#include "gpio.h"
#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3
#define OUTPUT 1

void led_PowerOn(int indexLED)
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
    }
}

void led_PowerOff(int indexLED)
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
    }
}

void led_set_as_output(int indexLED)
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
    }
}

void led_PowerOff_all()
{
  led_PowerOff(LED0);
  led_PowerOff(LED1);
  led_PowerOff(LED2);
  led_PowerOff(LED3);
}

void Blink_Fast(int indexLED, int milli)
{
  for(int i=0;i<6;i++){
      led_PowerOn(indexLED);
      software_delay(milli);
      led_PowerOff(indexLED);
      software_delay(milli);
  }
}
void Blink_Slow(int indexLED, int milli)
{
  for(int i=0;i<4;i++){
      led_PowerOn(indexLED);
      software_delay(milli);
      led_PowerOff(indexLED);
      software_delay(milli);
  }
}