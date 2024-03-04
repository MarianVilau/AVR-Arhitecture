# Central Control Panel Prototype for Car HVAC System

This project involves designing a prototype for a central control panel in a car, integrating an OLED1 extension board to control HVAC vents. The vents are positioned to direct airflow in three directions: left, central, and right. Each vent has a corresponding button and LED on the OLED1 board, providing visual confirmation to the driver about the enabled function of each vent.

## Requirements

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
