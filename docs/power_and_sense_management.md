# Power and Sense Management

## 1. Jetson Orin Nano (Primary Controller)

**Purpose**: Acts as the brain of the system, handling high-level decision-making, sensor data processing, and sending commands to motor controllers.  
**Connections**:

- **RPLidar** (Serial Over USB): Collects 360-degree LiDAR data, which is used for mapping, obstacle detection, or navigation.
- **Intel D435i Camera** (Serial Over USB): Provides depth sensing and visual information, useful for object detection, path planning, and visual SLAM.
- **Arduino Nano** (Serial Over USB): Communicates with the Arduino, which manages motor control.  
**Power Consumption**: The Jetson Orin Nano consumes around 5-15W depending on processing load.

## 2. Arduino Nano (Motor Controller)

**Purpose**: Receives control commands from the Jetson Orin Nano and translates them into signals for the motor drivers to control the wheels and steering.
**Connections**:

- Communicates with the motor driver via PWM signals, allowing precise control over speed and direction.  
**Power Consumption**: Typically consumes 0.25W.

## 3. RPLidar

**Purpose**: Provides distance measurements and 2D mapping around the robot for obstacle avoidance.  
**Power Consumption**: Around 3-5W.

## 4. Intel D435i Depth Camera

**Purpose**: Offers depth perception to the robot, crucial for tasks like object recognition, depth mapping, and navigation.  
**Power Consumption**: Around 1.5W.

## 5. Electronic Speed Controller

**Purpose**: Drives the DC motor responsible for the vehicle's motion. The motor driver allows control of both speed and direction of the motor via PWM inputs.  
**Connections**:

- Receives PWM signals from the Arduino Nano to control the speed and direction of the 6V brushed motor.  
**Power Consumption**: Minimal, but drives the 6V motor which may consume between 2-4W depending on load.

## 6. 6V DC Brushed Motor

**Purpose**: Powers the wheels, providing the propulsion needed to move the vehicle.  
**Power Consumption**: Between 2-4W depending on speed and load.

## 7. Servo Motor

**Purpose**: Provides steering control for the vehicle (likely Ackermann steering), adjusting the angle of the front wheels.  
**Power Consumption**: Around 0.5-1.5W, varying based on the load and steering angle.

## 8. Batteries

**Purpose**: The main power source for the system, 11.1V LiPo, supplies voltage to the Jetson whereas the the 6V NiMH powers the driving motor.
**Power Output**: 11.1V with a capacity of 2200mAh, providing enough energy to sustain the robot's operations for a moderate duration.

## 9. Switches

- **Power Switch**: Controls the overall power to the system, turning the vehicle on or off.
- **Program Start Switch**: Allows the user to initiate the program on the Jetson Orin Nano, triggering autonomous behavior.

## Summary of Power Consumption

- **Jetson Orin Nano**: 5-15W
- **RPLidar**: 3-5W
- **Intel D435i Camera**: 1.5W
- **Arduino Nano**: 0.25W
- **6V Brushed Motor**: 2-4W
- **Servo Motor**: 0.5-1.5W

## Reasons for Selecting Sensors

- **RPLidar**: Provides precise distance measurements and 360-degree scans, making it ideal for SLAM (Simultaneous Localization and Mapping) or obstacle avoidance in dynamic environments.
- **Intel D435i Depth Camera**: Adds 3D vision, essential for depth-based navigation and recognizing objects.
