#include "cpanel.h"
#include "gpio.h"
#include "led.h"
#include "btn.h"

#ifndef __cplusplus
#define bool  _Bool
#define true  1
#define false 0
#endif

#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3

#define SW0 0
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3

#pragma vector = PCINT2_vect
__interrupt void my_routine(void){
  bool SWO_press_once=false;
  
  if(btn_read_state(SW0)==1 && SWO_press_once==0)
  {
    SWO_press_once=true;
    led_PowerOn(LED0);
    for(volatile int i=0;i<=100;i++)
    {
      if(btn_read_state(BUTTON1)==1 || btn_read_state(BUTTON2)==1 || btn_read_state(BUTTON3)==1 )
      {
        Blink_Fast(LED0,30);
      }
    }
  }
  if(btn_read_state(SW0)==1 && SWO_press_once==1)
  {
   cpanel_BTNx_turn_on_LEDx(BUTTON1,LED1);      
   cpanel_BTNx_turn_on_LEDx(BUTTON2,LED2);     
   cpanel_BTNx_turn_on_LEDx(BUTTON3,LED3);     
   led_PowerOff(LED0);
   SWO_press_once=false;
  }
}

void main() {
   cpanel_setup_all_BTN();
   cpanel_setup_all_LED();
   led_PowerOff_all();
   
   SREG |= (1 << 7);
   PCICR |= (1 << 2);
   PCMSK2 |= (1 << 6);
   void __enable_interrupt(); 
   
   while(1){}
}