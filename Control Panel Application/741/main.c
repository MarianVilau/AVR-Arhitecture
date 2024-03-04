#include <iom324pb.h>
#include "uart_init.h"
#include "uart_send.h"
#include "uart_receive.h"
#include "cpanel.h"
#include "led.h"
#include "btn.h"

#ifndef __uint8_t_defined
typedef unsigned char                uint8_t;
# define __uint8_t_defined
#endif

void process_buttons_and_send_led_commands() {
    // Read button states and generate LED commands
    uint8_t buttonStates = btn_read_states();
    uint8_t ledCommands = generate_led_commands(buttonStates);

    // Send LED commands over UART
    uart_send_byte(ledCommands);
}

void process_received_data_and_update_leds() {
    // Receive LED commands from UART
    uint8_t receivedData = uart_receive_byte();

    // Interpret received data and update LEDs
    uint8_t ledStates = interpret_received_data(receivedData);

    // Update physical LEDs based on interpreted data
    update_leds(ledStates);
}

int main(void) {
    uart_init();
    cpanel_setup_all_BTN();
    cpanel_setup_all_LED();

    while (1) {
        process_buttons_and_send_led_commands();
        process_received_data_and_update_leds();
    }
}
