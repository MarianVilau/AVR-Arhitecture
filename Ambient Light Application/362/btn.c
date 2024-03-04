#include "btn.h"
#include "gpio.h"
#include "pins.h"
#define INPUT 0
#define SW0 0
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3

void btn_set_as_input(unsigned int indexBTN)
{
  switch(indexBTN)
  {
   case SW0: set_direction(&PORTC, 6,INPUT);
             set_pin(&PORTC,6); // enable pull-up resistor
             break;
           
   case BUTTON1: set_direction(&PORTC, 1,INPUT);
                 set_pin(&PORTC,1); // enable pull-up resistor
                 break;
     
   case BUTTON2: set_direction(&PORTA, 0,INPUT);
                 set_pin(&PORTA,0); // enable pull-up resistor
                 break;
  
   case BUTTON3: set_direction(&PORTA, 1,INPUT);
                 set_pin(&PORTA,1); // enable pull-up resistor
                 break;              
  }
  
}

unsigned char btn_state(unsigned int indexBTN)
{
  switch(indexBTN)
  {
   case SW0: return PINC & 0x40; 
             break;
           
   case BUTTON1: return PINC & 0x02; 
                 break;
     
   case BUTTON2: return PINA & 0x01; 
                 break;
  
   case BUTTON3: return PINA & 0x02; 
                 break;              
  }
  return 0;
}

void btn_debounce_delay(int milli)
{
  for(volatile unsigned int i=0;i<milli;i++);
}

int btn_read_state(unsigned int indexBTN)
{
  int _btn_state = btn_state(indexBTN);
  btn_debounce_delay(250);
  _btn_state = btn_state(indexBTN);
  if(_btn_state==0) return 1;
  return 0;
}