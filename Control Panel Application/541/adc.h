#ifndef ADC_H
#define ADC_H

#include <iom324pb.h>

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

void ADC_Init();
void ADC_ISR();
void ADC_Read();
uint8_t ADC_get_result();
uint8_t adc_get_data();
void ADC_StartConversion();
void ADC_ambient_light();
void ADC_coversion();

#endif