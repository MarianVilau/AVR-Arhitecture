#include "scheduler.h"
#include "led.h"

void task_10ms() {
 // led_change(LED0);
}

void task_50ms() {
 //led_change(LED1);
}

void task_100ms() {
  //led_change(LED2);
}

void task_500ms() {
  led_change(LED3);
}

void task_1000ms() {
  //led_change(LED_IO1);
}