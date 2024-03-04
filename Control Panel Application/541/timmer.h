#ifndef TIMMER_H
#define TIMMER_H

#include <iom324pb.h>
#define F_CPU 8000000

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


#endif