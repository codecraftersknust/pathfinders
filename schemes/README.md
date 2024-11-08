# Electromechanical diagrams

## Schematic Diagrams

The following diagrams illustrate the connections between all the electromechanical components and the vehicle's motors.

### **System Schematic**

- Includes the Jetson Orin Nano, Arduino Nano, ESC, sensors (RPLidar, Intel D435i Camera), and power supply components.

### **Power Management**

- Displays how the 11.1V LiPo & 6V NiMH batteries connect to the ESC to power the motors, controllers and sensors.

### **Control and Communication**

- Illustrates the communication between the Jetson Orin Nano and Arduino Nano, and the Driving Motor ESC together with the power distribution.

![Schematic Diagram](/schemes/diagrams/circuit.png)

> **Note:** All schematic diagrams can be found in the `/diagrams` folder in PNG format.

---

## Assembly Instructions

1. **Chassis Setup**:
   - Begin with the LaTraxx 1/18 Rally chassis.
   - Install the custom base plate and mount all necessary components.

2. **Component Connections**:
   - Wire the driving motors to the ESC and the steering servo to the Arduino Nano.
   - Connect the RPLidar, Arduino nano and Intel D435i to the Jetson Orin Nano via USB.
   - Ensure all components are powered correctly.

3. **Power On and Program Start**:
   - Use the installed switches to power the vehicle and initiate autonomous operation.

---

## Power Consumption Summary

| Component              | Power Consumption (W) |
|------------------------|-----------------------|
| Jetson Orin Nano        | 5-15W                 |
| RPLidar                | 3-5W                  |
| Intel D435iF Camera     | 1.5W                  |
| Arduino Nano           | 0.25W                 |
| 6V Brushed Motor       | 2-4W                  |
| Servo Motor            | 0.5-1.5W              |

---
