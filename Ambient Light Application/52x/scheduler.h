#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iom324pb.h>

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3
#define LED_IO1 4

#define FLAG_10MS   (1 << 0)
#define FLAG_50MS   (1 << 1)
#define FLAG_100MS  (1 << 2)
#define FLAG_500MS  (1 << 3)
#define FLAG_1000MS (1 << 4)

typedef void (*TaskFunction)();
void task_10ms();
void task_50ms();
void task_100ms();
void task_500ms();
void task_1000ms();

void scheduler_init();
void scheduler_flags_management();

uint8_t get_flags(void);
void set_flags(uint8_t new_flags);

#endif
