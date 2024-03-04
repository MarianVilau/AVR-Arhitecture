#ifndef UART_RECEIVE_H
#define UART_RECEIVE_H

#include <iom324pb.h>

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

uint8_t uart_receive_byte(void);

#endif
