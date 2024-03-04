#include <iom324pb.h>
#include "led.h"
#include "adc.h"

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

#ifndef __uint16_t_defined
typedef unsigned short int        uint16_t;
# define __uint16_t_defined
#endif


#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3
#define LED_IO1 4
 
uint16_t maxValue = 1023;
uint16_t middleValue = 512;

#pragma vector=ADC_vect
__interrupt void ADC_ISR(void){
   uint8_t adcResult = ADCH;
} 

void main() {
    led_init();
    ADC_Init();
    
    SREG|= (1<<7);
    
    while (1) {
        ADC_coversion();
        uint16_t adcValue = ADC_Read();
        
        if (adcValue <= 0)          led_PowerOff_OLED1();
        if(adcValue < middleValue)  led_PowerOn(LED1);
        if(adcValue >middleValue){
          led_PowerOn(LED1);
          led_PowerOn(LED2);
        }
        if(adcValue >= maxValue)     led_PowerOn_OLED1();
    }
}
