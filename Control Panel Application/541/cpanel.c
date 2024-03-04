#include "cpanel.h"
#include "led.h"
#include "btn.h"
#include "gpio.h"

#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3

#define SW0 0
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3

static bool btn_state_debounced[BUTTON3 + 1];

void cpanel_setup_all_BTN() {
    btn_set_as_input(SW0);
    btn_set_as_input(BUTTON1);
    btn_set_as_input(BUTTON2);
    btn_set_as_input(BUTTON3);
}

void cpanel_setup_all_LED() {
    led_set_as_output(LED0);
    led_set_as_output(LED1);
    led_set_as_output(LED2);
    led_set_as_output(LED3);
}

void cpanel_BTNx_control_LEDx(unsigned int indexBTN, unsigned int indexLED) {
    if (btn_state_debounced[indexBTN]) {
        led_PowerOn(indexLED);
    } else {
        led_PowerOff(indexLED);
    }
}

void cpanel_BTNx_turn_on_LEDx(unsigned int indexBTN, unsigned int indexLED) {
    if (btn_state_debounced[indexBTN]) {
        led_PowerOn(indexLED);
    }
}

void cpanel_BTNx_control_LEDx_press2(unsigned int indexBTN, unsigned int indexLED) {
    if (btn_state_debounced[indexBTN]) {
        hardware_delay(100);
        if (btn_state_debounced[indexBTN]) {
            led_PowerOff(indexLED);
        }
    }
}

void cpanel_SW0_turn_on_only_LED0() {
    if (btn_state_debounced[SW0]) {
        led_PowerOn(LED0);
        led_PowerOff(LED1);
        led_PowerOff(LED2);
        led_PowerOff(LED3);
    }
}

void cpanel_master_control() {
    static bool panel_blocked = false;

    if (btn_state_debounced[SW0]) {
        panel_blocked = !panel_blocked;

        if (panel_blocked) {
            led_PowerOn_OLED1();
        } else {
            led_PowerOff_OLED1();
        }

        for (int i = 0; i < 5; i++) {
            led_change(LED0);
            hardware_delay(100);
        }
    }
}

void cpanel_debounce_buttons() {
    for (int i = 0; i <= BUTTON3; i++) {
        static uint8_t btn_state_history[BUTTON3 + 1];
        static uint8_t stable_state_counter[BUTTON3 + 1];

        uint8_t current_state = btn_read_state(i);
        if (current_state == btn_state_history[i]) {
            stable_state_counter[i]++;
        } else {
            stable_state_counter[i] = 0;
        }

        if (stable_state_counter[i] == DEBOUNCE_THRESHOLD) {
            btn_state_debounced[i] = current_state;
        }

        btn_state_history[i] = current_state;
    }
}
