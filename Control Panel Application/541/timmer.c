#include "timmer.h"
#include "gpio.h"
#include "led.h"
#include "btn.h"

#define SW0 0
#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3
#define LED_IO1 4

void set_timer_prescaler_ms(uint16_t time_ms) {
    uint16_t prescaler = (F_CPU / 1000UL) * time_ms / 256UL;
    
    uint8_t prescaler_bits = 0;
    if (prescaler < 8) {
        prescaler_bits = 0;
    } else if (prescaler < 64) {
        prescaler_bits = 1;
    } else if (prescaler < 256) {
        prescaler_bits = 2;
    } else if (prescaler < 1024) {
        prescaler_bits = 3;
    } else {
        prescaler_bits = 4;
    }

    TCCR0B = (TCCR0B & 0xF8) | prescaler_bits;
}

void TC0_Init(uint16_t time_ms) {
    TCCR0A = 0x00;
    set_timer_prescaler_ms(time_ms);
    TIMSK0 = (1 << TIMSK0_TOIE0);
    TCNT0 = 0;
}

void countdown_timmer()
{ 
  led_PowerOn_all();
  while (btn_state(SW0)){}
   for (int i = 5; i > 0; i--) {
        switch (i) {
            case 5:
                led_PowerOff(LED0);
                break;
            case 4:
                led_PowerOff(LED1);
                break;
            case 3:
                led_PowerOff(LED2);
                break;
            case 2:
                led_PowerOff(LED3);
                break;
            case 1:
                led_PowerOff(LED_IO1);
                break;
        }
        hardware_delay(1000);
   }
}