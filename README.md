# Engineering materials

This repository contains engineering materials of a self-driven vehicle's model participating in the WRO Future Engineers competition in the season 2024.

## Content

* `t-photos` contains 2 photos of the team
* `v-photos` contains 6 photos of the vehicle
* `video` contains the video.md file with the link to a video where driving demonstration exists
* `schemes` contains one or several schematic diagrams in form of JPEG, PNG or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.
* `src` contains code of control software for all components which were programmed to participate in the competition
* `models` is for the files for models used by 3D printers to produce the vehicle elements.
* `docs` contains documents such as the BOM and general principles to help setup the project.

## 1. Mobility Management

### Chassis Design and Selection

* **Chassis:** LaTraxx Rally RC car chassis, selected for its robust design, stability, and adaptability to modifications.
* **Advantages:**
  * High durability and suitable for various terrains.
  * Pre-existing servo mount and ESC compatibility for smooth integration.
* **Modifications:** Mounted custom brackets for sensors and Raspberry Pi using 3D-printed parts.

### Motors

* **Drive Motor:** DC motor controlled by an ESC.
  * **Reason for Selection:** Provides high torque and speed for quick acceleration.
  * **Engineering Considerations:**
    * Speed: Capable of achieving consistent lap times on the track.
    * Torque: Sufficient to handle inclines and sharp turns.
    * Power: Optimized for the 6V NiMH battery.

* **Steering:** Chassis-integrated servo motor for precise control.

### Assembly Instructions

1. Mount the Raspberry Pi and Arduino Nano on the chassis using custom 3D-printed brackets.
2. Secure the ultrasonic sensors at the front and sides to maximize obstacle detection.
3. Connect the servo and ESC to the Arduino Nano via PWM.
4. Ensure all wiring is neatly routed to avoid interference with moving parts.
5. Use zip ties and adhesive pads to stabilize components.

---

## 2. Power and Sense Management

### Power Sources

* **Main Battery:** 11.1V LiPo, stepped down for:
  * **Raspberry Pi 3** (via a buck converter).
  * **Arduino Nano** (via USB of Pi).
* **Motor Battery:** 6V NiMH dedicated to the DC motor.
* **Reasoning:**
  * Separate power sources prevent voltage drops affecting the control systems.
  * Reduces noise interference from high-current components.

### Sensors

* **Ultrasonic Sensors:**
  * **Placement:** One at the front and one on each side for 360° obstacle detection.
  * **Usage:** Measure distances to walls and obstacles for navigation and avoidance.
* **Raspberry Pi Camera:**
  * **Purpose:** Line detection for track navigation.
  * **Implementation:** Mounted on a tilt bracket for adjustable angles.
  
### Wiring Diagram

[Can be found here](./schemes/README.md)

---

## 3. Obstacle Management

### Strategy

* **Navigation:**
  * Use the Raspberry Pi camera for detecting lines, red and green traffic symbols and corners.
  * Ultrasonic sensors ensure collision-free movement.

* **Control Flow:**
  * Raspberry Pi handles high-level decision-making.
  * Arduino Nano processes real-time sensor data and actuates motors accordingly.

## 4. Additional Resources

### Bill of Materials (BOM)

| **Component**              | **Quantity** | **Description**                                                                 | **Cost (USD)** | **URL**                                                                                      |
|----------------------------|--------------|---------------------------------------------------------------------------------|----------------|---------------------------------------------------------------------------------------------|
| Raspberry Pi 3 Model B+    | 1            | Main processor for navigation and control                                       | $38.50        | [Buy from Cytron](https://www.cytron.io/p-raspberry-pi-3-model-b-plus)                                                   |
| Arduino Nano               | 1            | Microcontroller for sensor and motor control                                    | $15.99         | [Buy on Amazon](https://www.amazon.com/LAFVIN-Board-ATmega328P-Micro-Controller-Arduino/dp/B07G99NNXL/ref=sr_1_1?crid=71U2SXKJZXP7&dib=eyJ2IjoiMSJ9.6QPRL9EGieCqVheJYNSvYCP4nyMaBegrye565UbAFrxZOYUEGVIXBW5Mn3SU9cxVzplyvGeIZ4oi-K5SLso7Bxtwd-eY0-WxvNcv7afrlNnAro9WHJALr3apcBQgHmIEBUgLOiy90Prhtw6UN2BxDilqh75NCfdNzhNLDKJUmYYRbqi6RGdml_f0gTqQe_uJj8OcWCBIXTN6dFRPu4zwrztHJGfWkHP3L01tbLZ3rWg.RzZMGGNH1eTKJeOCwRYh0YzUVpSfilnZgrgyjc9rzTI&dib_tag=se&keywords=arduino+nano&qid=1732380145&sprefix=arduinonano%2Caps%2C327&sr=8-1)                                                   |
| Pi Camera                  | 1            | Camera module for vision-based navigation                                       | $45.99        | [Buy on Amazon](https://www.amazon.com/Arducam-Raspberry-Autofocus-Acrylic-15-22pin/dp/B0BX6N6V98/ref=sr_1_4?crid=2CK71C51H02H8&dib=eyJ2IjoiMSJ9.x1ghcwxmsLLod8krHJqeaPhEey0oz2kK6Pu8L05Qy2h9AHH02mpJOX2gEmHRbk3KRAKpjnzPA9kUgju2tkZyaKDChpvHKvy4OtrCX7PTywZ8IT3lLbHoq2nBLeyPizWmYvFGBfWEGHsLPW9euTmH46HDFu1oU5_NVCMQuVPUvb64e1CebawPR6uaaICt0xyJxEQxjDSwQm62X-trRN2C_K0URHNqu3sNRqH-aB69kTQ.419T1WFngBJn_x_bqXKpwvVJWto271EiDv5Ry-kfrvI&dib_tag=se&keywords=pi+3+camera&qid=1732380202&sprefix=pi+3+camera%2Caps%2C369&sr=8-4)                                                   |
| Ultrasonic Sensor (HC-SR04)| 1-3          | Distance measurement for wall following                                         | $3.00 each     | [Buy on Amazon](https://www.amazon.com/)                                                   |
| 11.1V 3S LiPo Battery      | 1            | Power supply for the system                                                     | $98.99         |[Zeee](https://zeeebattery.com/collections/zeee-3s-lipo-battery/products/zeee-3s-lipo-battery-5200mah-11-1v-80c-ec5-2pack)|
| Step-Down Voltage Regulator| 1            | Converts 11.1V to required voltage levels for the Pi and motors                 | $6.71         | [Buy on Amazon](https://www.amazon.com/Seloky-Converter-Adjustable-Electronic-Stabilizer/dp/B0DBVYP91F/ref=sr_1_4?crid=546U3U3MR4IS&dib=eyJ2IjoiMSJ9.WFmcMhr5wKG96ZSaMiTTM3Rk3hGcs4Yrw2gcYfWnbx3aCwqpwm6VQOqyvbbgak7fEgdPmnRpUHv-1tMCsjKjbEKyfK_UoX7fDrrWQ89cfzPQk4pOJBeKvIbRRqxBNTsOdCtaJwO4t7ZF2h5XskhpVawcxM2cpSoeHlwjlYThAE-piEJZKkE-NfC9_SPqmGwOzSftQy6aJWygZVpXluHDlm-OPMOyACqB5XRGDQHDAWQ.2YdcJS5iNRfqxQ25i1hVJzenz3whBM6beoRCd10Tadk&dib_tag=se&keywords=dc+to+dc+buck+converter&qid=1732382288&sprefix=dc+to+dc+buck%2Caps%2C355&sr=8-4)                                                   |
| 1/18 LaTraxx Rally RC Chassis   | 1            | Chassis and mechanical structure                                                | $119.95        | [HobbyTown](https://www.hobbytown.com/traxxas-1-18-latrax-rally-rtr-4wd-electric-rally-car-green-blue-tra75054-5-grnx/p1460077)                                                   |
| 3D printed base plate              | 1   |         |    | [STL file](../models/base-plate.stl)  |
| 3D printed base plate mount              | 2   |         |    | [STL file](../models/base-plate-mount.stl) |
| 3D printed camera mount            | 1   |         |    | [STL file](../models/camera-mount.stl) |
| Illuminated Halo Ring Switch       | 2   |    | $9.49 | [Amazon](https://www.amazon.com/API-ELE-warranty-Latching-Button-Metal1NO1NC/dp/B07932GYNH/ref=sr_1_3?dib=eyJ2IjoiMSJ9.1q0NmsreDNOKpu5DB3cH1ONQg1gf6ojqqeubPkY6kXO_CI5WLatggDoZGZv6hJPEVEiX1cHP410bNaktRFsaX9XwBjIhHZh5JMM9NfJ_wGqIxY43ioeJQyoe98AfHeKBxIviiXuJkxEXYDx2x6ZL-7N-2TClm3P1OMpS2ap4mL913wBktLpatHpV7ijA0_xPTXH6aUFIt_eZTm5MI-jt7kQ4aWVwZ166vSu3_jdTOnY.mfo9PLJnSCuErvc5PZ1wwbi_DOIoTPvlxrf5Wpt1Kqg&dib_tag=se&keywords=halo%2Bswitch&qid=1726309742&sr=8-3&th=1) |
| Screw Pack (M2, M3)                | 1   |   | $8.19  |  [Amazon](https://www.amazon.com/gp/product/B01FXGHO2M/?th=1) |
| Micro SD Card (32GB)               | 1   | Must be at least 32GB  | $49.99 | [Amazon](https://www.amazon.com/Samsung-MicroSDXC-Adapter-MB-ME64GA-AM/dp/B06XX29S9Q/?utm_source=GitHub&utm_medium=link&th=1) |
| Jumper Wire Pack          | 1   |  >15cm  | $6.98 | [Amazon](https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD2BWPY/ref=sr_1_1_sspa?adgrpid=87137554968&dib=eyJ2IjoiMSJ9.hN9xWohZ0eiut9PloEXT2-Muw3wl-m-QeSlHHYd8tRhe9o3CJL74B7kLnJLznKdCWcE2VJOgBGZaB3piHh-47KBzR1oY2RngpyFSxIYHmfaMNvsv11u0RK7ejJCcheDQdqWzNI3Q166vTtwjLkLXzCDNuIN4xqQ6oEYu1wNIhaZYn2d640pxtPIv0SI7EeFCNnYdCsSiHYXyED2PaJjTQMnIhKw8H8ObP5nGZc-Hivg.EuxqF69DjQmqJzMnqKrpkXjfZVR_QMJS4oM8kfcLBZQ&dib_tag=se&hvadid=673520525205&hvdev=c&hvlocphy=9067654&hvnetw=g&hvqmt=b&hvrand=7339871033264311669&hvtargid=kwd-488861710272&hydadcr=7782_13673687&keywords=jumper+wires&qid=1726309685&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) |
