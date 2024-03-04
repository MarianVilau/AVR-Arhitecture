#include "scheduler.h"
#include "led.h"
#include "adc.h"
#include "cpanel.h"

#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3

#define SW0 0
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3


void task_10ms() {
    cpanel_BTNx_control_LEDx(BUTTON1, LED1);
    cpanel_BTNx_control_LEDx(BUTTON2, LED2);
    cpanel_BTNx_control_LEDx(BUTTON3, LED3);
}

void task_50ms() {
 cpanel_master_control();
}

void task_100ms() {
  //led_change(LED2);
}

void task_500ms() {
   
}

void task_1000ms() {
  //led_change(LED_IO1);
}

void task_adc_conversion() {
    ADC_coversion();
}

void task_ambient_light()
{
    ADC_ambient_light();
}

void task_master_control() {
    cpanel_master_control();
}

void task_button_debounce() {
    cpanel_debounce_buttons();
}
