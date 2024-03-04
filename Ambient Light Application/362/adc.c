#include "adc.h"

void ADC_Init() {
    ADMUX |= (1 << ADMUX_MUX2) | (1 << ADMUX_MUX1) | (1 << ADMUX_MUX0);
  ADMUX |= (1 << ADMUX_REFS1);
  ADCSRA |= (1 << ADCSRA_ADEN); 
  ADCSRA |= (1 << ADCSRA_ADPS2) | (1 << ADCSRA_ADPS1) | (1 << ADCSRA_ADPS0);
  
  ADCSRA |= (1 << ADCSRA_ADIE); 
  DDRA = (1 << PINA_PINA3);
}

uint16_t ADC_Read() {
    // Start ADC conversion
    ADCSRA |= (1 << ADCSRA_ADSC);
    
    // Wait for ADC conversion to complete
    while (ADCSRA & (1 << ADCSRA_ADSC));
}

uint8_t ADC_get_result()
{
  return ADC;
}

void ADC_coversion()
{
       while (ADCSRA & (1 << ADCSRA_ADSC)) {} 
     int analogValue = ADC_get_result(); 
}