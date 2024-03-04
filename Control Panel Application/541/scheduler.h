#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iom324pb.h>
#include <stddef.h>

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

#define FLAG_10MS   (1 << 0)
#define FLAG_50MS   (1 << 1)
#define FLAG_100MS  (1 << 2)
#define FLAG_500MS  (1 << 3)
#define FLAG_1000MS (1 << 4)

//Maximum number of tasks that can be added to the scheduler
#define MAX_TASKS 10

// Structure to hold task information
typedef struct {
    void (*task)();
    uint16_t period;
    uint16_t counter;
} task_info_t;

typedef void (*TaskFunction)();
void task_10ms();
void task_50ms();
void task_100ms();
void task_500ms();
void task_1000ms();
void task_adc_conversion();
void task_ambient_light();
void task_button_debounce(); 
void task_master_control();

void scheduler_HW_init();
void scheduler_init();
void scheduler_flags_management();

uint8_t get_flags(void);
void set_flags(uint8_t new_flags);

void scheduler_add_task(void (*task)(), uint16_t period_ms);
void scheduler_dispatch();

#endif
