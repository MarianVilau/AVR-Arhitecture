#include "adc.h"
#include "led.h"

static uint8_t adc_result=0;
volatile uint8_t ledState = 0;

void ADC_Init() {
    ADMUX |= (1 << ADMUX_MUX2) | (1 << ADMUX_MUX1) | (1 << ADMUX_MUX0);
  ADMUX |= (1 << ADMUX_REFS1);
  ADCSRA |= (1 << ADCSRA_ADEN); 
  ADCSRA |= (1 << ADCSRA_ADPS2) | (1 << ADCSRA_ADPS1) | (1 << ADCSRA_ADPS0);
  
  ADCSRA |= (1 << ADCSRA_ADIE); 
  DDRA = (1 << PINA_PINA3);
}

void ADC_ISR(void) {
    adc_result = ADCH;
}

void ADC_Read() {
    ADC_StartConversion();
    // Wait for ADC conversion to complete
    while (ADCSRA & (1 << ADCSRA_ADSC));
}

uint8_t ADC_get_result()
{
  return ADC;
}

void ADC_coversion()
{
    ADC_StartConversion();
    // Wait for conversion to complete
    while (ADCSRA & (1 << ADCSRA_ADSC));
    // Read the ADC result
    adc_result = ADCH;
}

uint8_t adc_get_data() {
    return adc_result;
}

void ADC_StartConversion() {
    ADCSRA |= (1 << ADCSRA_ADSC);
}

void ADC_ambient_light()
{
  if (adc_result <= 0) {
        ledState = 0;
    } else if (adc_result < 128) {
        ledState = 1;
    } else if (adc_result < 192) {
        ledState = 2;
    } else {
        ledState = 3;
    }

    // Turn on/off LEDs based on the LED state
    switch (ledState) {
        case 0:
          led_PowerOff_OLED1();
          break;
       case 1:
          led_PowerOn(LED1);
          break;
       case 2:
          led_PowerOn(LED1);
          led_PowerOn(LED2);
          break;
       case 3:
          led_PowerOn_OLED1();
          break;
      
    }
}