# Requirements for Light Intensity-Responsive LED Control:

## 362 - first version of this software

1. **Objective:**
   Implement a light intensity-responsive LED control system based on four predefined ADC readings intervals to enhance user experience in varying lighting conditions.

2. **ADC Readings Intervals:**
   - **Interval 1:** Full Dark
   - **Interval 2:** Semi-Dark
   - **Interval 3:** Semi-Light
   - **Interval 4:** Full Light

3. **Light Intensity Correspondence:**
   - **Interval 1 (Full Dark):** All LEDs (LED1, LED2, LED3) should be turned off.
   - **Interval 2 (Semi-Dark):** LED1 should be turned on.
   - **Interval 3 (Semi-Light):** LED1 and LED2 should be turned on.
   - **Interval 4 (Full Light):** LED1, LED2, and LED3 should be turned on.

4. **Implementation Details:**
   - Utilize ADC readings to determine the current light intensity level.
   - Implement logic to control LEDs based on the specified intervals and corresponding light intensity states.
   - Ensure that the LED control system responds seamlessly to changes in light conditions.
   - Documentation should include instructions for setup and calibration to achieve optimal performance.

5. **Testing Requirements:**
   - Validate the system's responsiveness by testing it in various lighting conditions.
   - Ensure LEDs transition smoothly between states as per the specified intervals.

6. **Scalability:**
   - Design the system to allow for easy modification or expansion of ADC readings intervals and corresponding LED states to accommodate future enhancements or adjustments.

7. **Compliance:**
   - The implemented solution should comply with the defined requirements, providing a reliable and user-friendly light intensity-responsive LED control system.

## 52x - second version of this software


**Overview**

When considering an application as a sum of periodic events, it's beneficial to adopt a task-oriented design. This involves executing tasks based on time slices, facilitated by a task scheduler module.

**Task Scheduler Module Reorganization**

- **scheduler.c:**
  - Contains `schedule_dispatcher` and `schedule_flags_management` functions.
  - Acts as a collection of task scheduling logic.
  
- **scheduler.h:**
  - Contains prototypes of provided functions.

- **scheduler_cfg.c:**
  - Contains initially empty task bodies.
  - After deciding the corresponding functions to connect with each task, contains those function calls.
  - Acts as a collection of task hooks.

- **scheduler_cfg.h:**
  - Contains prototypes of required functions.

**Ambient Light Application Refactoring**

**1. Encapsulation of Data Result in ADC Module**

- Utilize the `static` keyword to encapsulate/hide data results within the ADC module.

**2. Provide "Get" Interface/Function**

- Implement a "get" interface/function (`adc_get_data()`) to access data results from other modules.

**3. Task Scheduler Integration**

- Leverage the task scheduler to schedule tasks related to ambient light indicator LEDs:
  - Start of conversion.
  - Obtaining and utilizing the data result.
