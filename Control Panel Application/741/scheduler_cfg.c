#include "sheduler_cfg.h"
#include "led.h"
#include "timmer.h"
#define LED0 0

void task_10ms() {
 TC0_set_duty_cycle(0);
}

void task_400ms() {
 TC0_set_duty_cycle(25);
}

void task_800ms() {
 TC0_set_duty_cycle(50);
}

void task_1000ms() {
  led_PowerOn(LED0);
}

void task_1500ms() {
  TC0_set_duty_cycle(90);
}

void task_2000ms() {
  led_PowerOff(LED0);
}

void task_3000ms() {
  TC0_set_duty_cycle(0);
}

void task_4000ms() {
  TC0_set_duty_cycle(90);
}

void task_5000ms() {
  TC0_set_duty_cycle(0);
}

void task_6000ms() {
  TC0_set_duty_cycle(90);
}

void task_7000ms() {
  TC0_set_duty_cycle(90);
}

void task_7500ms() {
  TC0_set_duty_cycle(75);
}

void task_8000ms() {
  TC0_set_duty_cycle(25);
}

void task_9000ms() {
  TC0_set_duty_cycle(0);
}

void task_12000ms() {
  TC0_set_duty_cycle(0);
}


