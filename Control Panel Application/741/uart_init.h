#ifndef UART_INIT_H
#define UART_INIT_H

#include <iom324pb.h>

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

#ifndef __uint16_t_defined
typedef unsigned short int        uint16_t;
# define __uint16_t_defined
#endif

void uart_init();

#endif
