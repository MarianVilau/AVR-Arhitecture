#ifndef PWM_H
#define PWM_H

#include <iom324pb.h>

#define PWM_FREQ_HZ 1000      // Desired PWM frequency in Hz (e.g., 1000 Hz)
#define MAX_PWM_VALUE 255     // Maximum value for PWM counter (8-bit PWM)
#define F_CPU 8000000UL

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

#ifndef __uint16_t_defined
typedef unsigned short int        uint16_t;
# define __uint16_t_defined
#endif

volatile uint8_t duty_cycle = 0;

void pwm_init();
void pwm_set_duty_cycle(uint8_t duty_cycle);

#endif
