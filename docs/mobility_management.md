# Mobility Management

## Vehicle Chassis

The project is based on the LaTrax 1/18 Rally chassis (Model #75054-5), which provides a solid foundation for the autonomous vehicle. Key specifications include:

- **Length**: 265 mm (10.4 inches)
- **Width (Track)**: 125 mm (4.92 inches) both front and rear
- **Height**: 90 mm (3.5 inches)
- **Wheelbase**: 165 mm (6.5 inches)
- **Weight**: 554 g (19.5 ounces) with battery, 430 g (15.2 ounces) without battery
- **Chassis Material**: Molded composite Nylon monocoque  

This chassis was chosen for its compact size, lightweight design, and durability.

## Management

### Motor Selection and Implementation

The LaTrax chassis comes with a **370 brushed motor**. For autonomous operation, this motor is retained and controlled using the following components:

- **ESC**: Comes with Latrax chassis
  The model’s ESC is an extemely powerful electronic device capable of delivering high current.

### Steering System

The original steering system uses a bellcrank mechanism. For autonomous control, this has been modified to use a servo motor, controlled by:

- **Arduino Nano**:
  This allows for accurate steering control managed by the Jetson Orin Nano.

### Drive System

- **Type**: Shaft-driven 4WD
- **Transmission**: 14T pinion / 54T spur
- **Gear Ratio**: 2.5:1 (internal), 9.64:1 (overall, stock)
- **Differential**: Gear type
- **Gear Pitch**: 0.5 Mod  

This 4WD system provides excellent traction and stability, which is crucial for autonomous operation in various terrains.

## Component Mounting

A custom **base plate** has been designed and fabricated to mount all the additional components required for autonomous operation. This includes:

- RPLidar
- Intel D435i RealSense Depth Camera
- Nvidia Jetson Orin Nano
- L298N motor driver
- ESC
- 2 Halo ring switches

The base plate serves as a central mounting point, ensuring all components are securely attached and properly positioned. Additional custom mounts have been created for:

- **Camera mount**: Attaches the Intel D435i camera to the base plate.
- **Base mount**: Connects the entire setup (base plate with all components) to the LaTrax chassis.  

These custom mounts ensure proper alignment and stability of all components during operation.

## Engineering Principles

### Speed

The stock motor and gearing provide a balance between speed and torque. The overall drive ratio of 9.64:1 allows for good low-speed control, which is essential for precise autonomous movement.

### Torque

The gearing system provides ample torque for the vehicle's size and weight. This ensures good acceleration and climbing ability, which are important for navigating various terrains autonomously.

### Power

The **370 brushed motor**, combined with the stock 6V from the NiMH battery, provides sufficient power for the vehicle's operations. The power delivery is managed by the ESC, allowing for fine control of the vehicle's movements.
