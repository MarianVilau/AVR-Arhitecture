#include <iom324pb.h>
#include "scheduler.h"


int scheduler_flags_management(int overflow) {
  switch (overflow) {
    case    5: return   10; 
    case   10: return   20; 
    case   15: return   30; 
    case   20: return   40; 
    case   25: return   50;
    case   50: return  100;
    case  100: return  200;
    case  150: return  300;
    case  200: return  400;    
    case  250: return  500;
    case  300: return  600; 
    case  350: return  700;  
    case  400: return  800; 
    case  450: return  900; 
    case  500: return 1000; 
    case  750: return 1500; 
    case 1000: return 2000;
    case 1500: return 3000;
    case 2000: return 4000;
    case 2500: return 5000; 
    case 3000: return 6000;    
    case 3500: return 7000;  
    case 3750: return 7500; 
    case 4000: return 8000;
    case 4250: return 8500;
    case 4500: return 9000;
    case 6000: return 12000;
  }
}

void schedule_tasks_dispatcher(int _flag, int overflow) {
    _flag = 0;
    overflow = 0;
}


