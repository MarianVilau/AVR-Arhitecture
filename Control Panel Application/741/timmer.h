#ifndef TIMMER_H
#define TIMMER_H

#include <iom324pb.h>
#define F_CPU 8000000

#define N   1
#define CTC 2
#define PWM 3

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

#ifndef __uint16_t_defined
typedef unsigned short int        uint16_t;
# define __uint16_t_defined
#endif

#ifndef __uint32_t_defined
typedef unsigned int                uint32_t;
# define __uint32_t_defined
#endif

void set_timer_prescaler_ms(uint16_t time_ms);
void TC0_Init(uint16_t time_ms);
void countdown_timmer();

void TC0_mode(uint8_t mode);
void TC0_set_prescale(uint16_t prescaler);
uint8_t TC0_get_prescale();
void TC0_duty_cycle(uint8_t duty);
void TC0_enable_ovf();

#endif