#include <iom324pb.h>
#include <intrinsics.h>

#define PWM_FREQ_HZ 1000
#define MAX_PWM_VALUE 255
#define F_CPU 8000000UL

#define LED1 5 // PD5
#define LED2 4 // PD4
#define BUTTON_PIN 6 // PC6
#define DEBOUNCE_DELAY_MS 50

#ifndef __uint8_t_defined
typedef unsigned char             uint8_t;
#define __uint8_t_defined
#endif

#ifndef __uint16_t_defined
typedef unsigned short int        uint16_t;
#define __uint16_t_defined
#endif

#ifndef __uint32_t_defined
typedef unsigned int                uint32_t;
#define __uint32_t_defined
#endif

volatile uint8_t dayMode = 0; // 0: Night Mode, 1: Day Mode
volatile uint16_t lightIntensity = 0;
volatile uint8_t buttonState = 0;
volatile uint8_t lastButtonState = 0;
volatile uint32_t lastDebounceTime = 0;
volatile uint32_t milliseconds = 0;

void adc_init() {
    ADMUX = (1 << ADMUX_REFS0); // Use AVCC as reference voltage
    ADCSRA = (1 << ADCSRA_ADEN) | (1 << ADCSRA_ADPS2) | (1 << ADCSRA_ADPS1); // Enable ADC, set prescaler to 64
}

uint16_t read_light_intensity() {
    ADCSRA |= (1 << ADCSRA_ADSC); // Start conversion
    while (ADCSRA & (1 << ADCSRA_ADSC)); // Wait for conversion to complete
    return ADC;
}

void pwm_init() {
    // Set LED pins as outputs
    DDRD |= (1 << LED1);
    DDRD |= (1 << LED2);

    // Set Timer/Counter0 (8-bit) to Fast PWM mode with TOP value as MAX_PWM_VALUE
    TCCR0A = (1 << TCCR0A_COM0A1) | (1 << TCCR0A_COM0B1) | (1 << TCCR0A_WGM01) | (1 << TCCR0A_WGM00);
    TCCR0B = (1 << TCCR0B_CS00); // No prescaler

    // Enable Timer/Counter1 Overflow Interrupt for the 3 seconds pause
    TCCR1B = (1 << TCCR1B_CS10); // No prescaler
    TIMSK1 = (1 << TIMSK1_TOIE1);
}

void pwm_set_duty_cycle(uint8_t duty, uint8_t led) {
    if (duty > 100) {
        duty = 100;
    }

    uint8_t pwmValue = (duty * MAX_PWM_VALUE) / 100;

    if (led == 1) {
        OCR0A = pwmValue;
    } else if (led == 2) {
        OCR0B = pwmValue;
    }
}

void set_day_mode(uint8_t mode) {
    dayMode = mode;
}

void entry_phase() {
    volatile float elapsed_time = 0;
    volatile float relative_steps = 0;

    while (elapsed_time <= 2) {
        // Read light intensity during the entry phase
        lightIntensity = read_light_intensity();

        // Determine relative time and light intensity steps
        if (dayMode) {
            relative_steps = 1 + (lightIntensity - 41) * (16 - 1) / (70 - 41);
        } else {
            relative_steps = (lightIntensity - 0) * (16 - 0) / (40 - 0);
        }

        // Calculate PWM duty cycle based on relative steps
        uint8_t dutyCycle = 0;
        if (dayMode) {
            dutyCycle = 42 + (80 - 42) * (relative_steps - 1) / (16 - 1);
        } else {
            dutyCycle = 15 + (20 - 15) * relative_steps / 16;
        }

        // Set PWM duty cycles for LED1 and LED2
        pwm_set_duty_cycle(dutyCycle, 1);
        pwm_set_duty_cycle(dutyCycle, 2);

        // LED changing statements based on the current time and light intensity
        if (dayMode) {
            if (dutyCycle <= 42) {
                // Set LED1 to Night Mode
                PORTD |= (1 << LED1);
            } else {
                // Set LED1 to Day Mode
                PORTD &= ~(1 << LED1);
            }

            if (dutyCycle <= 80) {
                // Set LED2 to Night Mode
                PORTD |= (1 << LED2);
            } else {
                // Set LED2 to Day Mode
                PORTD &= ~(1 << LED2);
            }
        } else {
            if (dutyCycle <= 15) {
                // Set LED1 to Night Mode
                PORTD |= (1 << LED1);
            } else {
                // Set LED1 to Day Mode
                PORTD &= ~(1 << LED1);
            }

            if (dutyCycle <= 20) {
                // Set LED2 to Night Mode
                PORTD |= (1 << LED2);
            } else {
                // Set LED2 to Day Mode
                PORTD &= ~(1 << LED2);
            }
        }

        // Increment elapsed time with the desired time step (e.g., 0.1 seconds)
        elapsed_time += 0.1;

        // Delay for the time step (requires <intrinsics.h> library)
        __delay_cycles(F_CPU / 10);
        milliseconds += 100; // Increment milliseconds
    }
}

void debounce_button() {
    uint8_t reading = (PINC & (1 << BUTTON_PIN));

    if (reading != lastButtonState) {
        lastDebounceTime = milliseconds;
    }

    if ((milliseconds - lastDebounceTime) > DEBOUNCE_DELAY_MS) {
        if (reading != buttonState) {
            buttonState = reading;

            if (buttonState == 1) {
                // Button pressed, repeat the entry phase
                entry_phase();
            }
        }
    }

    lastButtonState = reading;
}

#pragma vector=TIMER1_OVF_vect
__interrupt void TIMER1_OVF_ISR(void) {
    // Reset Timer1 value for 3 seconds
    TCNT1 = -(F_CPU * 3) / 1024;
}

int main(void) {
    adc_init();
    pwm_init();

    // Enable global and Timer1 interrupts
    SREG = (1 << 7);
    TIMSK1 = (1 << TIMSK1_TOIE1);

    while (1) {
        // Read light intensity
        lightIntensity = read_light_intensity();

        // Determine the mode based on the light intensity
        if (lightIntensity <= 40) {
            set_day_mode(0); // Night Mode
        } else {
            set_day_mode(1); // Day Mode
        }

        // Perform the entry phase
        entry_phase();

        // Check the button state for repeating the entry phase
        debounce_button();
    }

    return 0;
}
