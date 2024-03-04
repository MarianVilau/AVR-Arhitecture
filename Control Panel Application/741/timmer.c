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

void TC0_mode(uint8_t mode){
  switch(mode){
     case N:
      TCCR0A_WGM00 = 0; TCCR0A_WGM01 = 0;
      TCCR0B_WGM02 = 0;
      break;
     
     case CTC:
      TCCR0A_WGM00 = 0; TCCR0A_WGM01 = 1;
      TCCR0B_WGM02 = 0;
      break;
      
     case PWM:
      TCCR0A_WGM00 = 1; TCCR0A_WGM01 = 1;
      TCCR0B_WGM02 = 0;
      break;
  }
}

void TC0_set_prescale(uint16_t prescaler){
  switch(prescaler){
   case 1:
      TCCR0B_CS02=0; TCCR0B_CS01=0; TCCR0B_CS00=1;
      break;
    case 8:
      TCCR0B_CS02=0; TCCR0B_CS01=1; TCCR0B_CS00=0;
      break;
    case 64:
      TCCR0B_CS02=0; TCCR0B_CS01=1; TCCR0B_CS00=1;
      break;    
    case 256:
      TCCR0B_CS02=1; TCCR0B_CS01=0; TCCR0B_CS00=0;
      break;       
    case 1024:
      TCCR0B_CS02=1; TCCR0B_CS01=0; TCCR0B_CS00=1;
      break;  
  }
}

uint8_t TC0_get_prescale(){
    if ((TCCR0B_CS00 == 1) && (TCCR0B_CS01 == 0) && (TCCR0B_CS02 == 1))
        return 5;
    if ((TCCR0B_CS00 == 0) && (TCCR0B_CS01 == 0) && (TCCR0B_CS02 == 1))
        return 4;
    if ((TCCR0B_CS00 == 1) && (TCCR0B_CS01 == 1) && (TCCR0B_CS02 == 0))
        return 3;
    if ((TCCR0B_CS00 == 0) && (TCCR0B_CS01 == 1) && (TCCR0B_CS02 == 0))
        return 2;
    if ((TCCR0B_CS00 == 1) && (TCCR0B_CS01 == 0) && (TCCR0B_CS02 == 0))
        return 1;
    
    return 0;
}

void TC0_set_duty_cycle(uint8_t duty){
  OCR0A=( duty *255 )/ 100;
}

void TC0_enable_ovf(){
   TIMSK0_TOIE0 = 1;
   SREG = (1<<7);
}