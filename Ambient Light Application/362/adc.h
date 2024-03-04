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

void ADC_Init();
uint16_t ADC_Read();
uint8_t ADC_get_result();
void ADC_coversion();

#endif