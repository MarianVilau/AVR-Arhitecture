# Dashboard Illumination Control Prototype Development

## Project Overview

Embarking on the creation of a dashboard illumination control prototype. 

## Requirements and Engineering Decisions

### Ambient Light Intensity Measurements

- Utilizing a TEMT6000 light sensor to measure ambient light intensity.
- Adopting a 10-bit ADC resolution on the ATmega324PB Xplained PRO main board for accurate light intensity readings.

### Day and Night Illumination Designs

- Crafting both day and night illumination designs based on measured ambient light intensity.
- Implementing an entry phase triggered by the SW0 switch (headlights activation).

### Illumination Design Parameters

#### Table 741.1 - Day/Night Illumination Design Preferences

| Eye Perceived Light Levels | PWM % Duty-Cycle | Design/Mode |
|---------------------------|------------------|-------------|
| 0 - 20                    | 15%              | Night       |
| 21 - 40                   | 20%              | Night       |
| 41 - 50                   | 42%              | Day         |
| 51 - 70                   | 80%              | Day         |
| 71 - 100                  | 90%              | Day         |

#### Table 741.2 - Entry Phase Steps for Night and Day Modes

| Time [sec] | Entry Phase Night Mode (Relative Steps) | Entry Phase Day Mode (Relative Steps) |
|------------|-----------------------------------------|---------------------------------------|
| 0          | 0                                       | 0                                     |
| 0.2        | 1                                       | 4                                     |
| 0.4        | 1                                       | 7                                     |
| 0.6        | 3                                       | 16                                    |
| 0.8        | 7                                       | 44                                    |
| 1          | 16                                      | 59                                    |
| 1.2        | 16                                      | 59                                    |
| 1.4        | 14                                      | 55                                    |
| 1.6        | 12                                      | 50                                    |
| 1.8        | 10                                      | 45                                    |
| 2          | 8                                       | 40                                    |

### Visual Feedback Implementation

- Employing the OLED1 board with two LEDs (LED1 and LED2) for background illumination in both Day and Night modes.
- Replicating the driver's scenario of turning on the headlights each time SW0 is pressed.
