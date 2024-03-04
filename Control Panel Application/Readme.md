# Central Control Panel Prototype for Car HVAC System

This project involves designing a prototype for a central control panel in a car, integrating an OLED1 extension board to control HVAC vents. The vents are positioned to direct airflow in three directions: left, central, and right. Each vent has a corresponding button and LED on the OLED1 board, providing visual confirmation to the driver about the enabled function of each vent.

## Requirements
## 33x - first version of this software

### Button Behavior

- Pressing a vent control button (X=1,2,3) activates the corresponding LED X.
- Releasing the button turns off the respective LED X.
- If the same button is pressed a second time, the corresponding LED X turns off.

### Master Control (SW0)

- Pressing the SW0 button activates LED0 on the ATmega324PB main board.
- Activating the master control blocks the functionality of the entire control panel.
- Pressing any vent control button during the blocked state has no effect on vents and LED indicators (they stay OFF).
- Pressing any vent control button during the blocked state results in fast blinking LED0, indicating that the panel is blocked.
- To unblock the panel, the SW0 master control must be pressed again.

## 541 - second version of this software

- Introduce task scheduler for handling of buttons and LEDs behavior
- Use debounce algorithm for a stable state of buttons 

## 741 - third version of this software

Refactor the code using the serial UART communication (simplex, that means one way) as follows:							
	- imagine that on the physical microcontroller (ATmega324PB) we construct two virtual microcontrollers (MCU1 and MCU2)						
	- these two virtual microcontrollers are connected by TX/RX line forming a simplex master-slave communication channel (MCU1 = master and MCU2 = slave)						
	- all the buttons from your system will be read by virtual MCU1 via the physical pins of ATmega324PB						
	- the buttons states are interpreted by virtual MCU1 and apropriate LEDs states are build and stored by virtual MCU1 but not executed						
	- virtual MCU1 will send over UART protocol ( by TX physical pin) the appropriate data/commands for LEDs light on/off behavior						
	- virtual MCU2 (the slave) will receive these data (by RX physical pin) and execute/implement the LEDs behavior as requested by virtual MCU1 (the master)						
							
