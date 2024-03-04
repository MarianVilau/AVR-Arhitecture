#ifndef UART_SEND_H
#define UART_SEND_H

#include <iom324pb.h>
#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

void uart_send_byte(uint8_t data);

#endif
