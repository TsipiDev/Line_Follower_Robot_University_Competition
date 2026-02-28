#  Line Follower Robot – University Embedded Systems Competition

[![Made With Arduino](https://img.shields.io/badge/Made%20with-Arduino-blue?style=for-the-badge&logo=arduino)](https://www.arduino.cc/)
[![Platform: RP2040](https://img.shields.io/badge/Platform-RP2040-blueviolet?style=for-the-badge)](https://www.raspberrypi.com/documentation/microcontrollers/rp2040.html)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](./LICENSE)

![FinalRobot](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/Final%20Robot%20Build.jpeg?raw=true)

##  Overview

This project was made as an entry to our university's Embedded Systems course competition. The goal of the competition and of this repository was to make a line follower robot from scratch that can complete all of the 3 stages in the competition.
Moreover this repository also serves as a guide to how you can build our robot, from the components you gonna need and the robot's code to building it and putting it all together. If you wanna build our model or create your own based on our robot then feel free just make sure you give us a mention in your project!! Our main focus for this line follower was for it to be fast and able to handle various "weather conditions" that could be present in the stages along with sharp turns and sudden stops, these factors heavily affected our design and coding decisions as well as which parts we picked.


##  Table of Contents

- [ Stages](#-stages)
- [ Hardware & Software Requirements](#️-hardware--software-requirements)
- [ Installation Guide](#️-installation-guide)
- [ Code Explanation](#-code-explanation)
- [👨‍👩‍👧‍👦 Team & Credits](#-team--credits)


##  Stages  

**Stage 1**
![Stage 1](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/stage1.jpg?raw=true)

**Stage 2**
![Stage 2](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/stage2.jpg?raw=true)

**Stage 3**
![Stage 3](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/stage3.jpg?raw=true)


##  Hardware & Software Requirements

###  Hardware Components

- 1x Maker PI RP2040 Microcontroller  
- 2x DC Motors (Included with Chassis)  
- 1x 2-Wheel Chassis (Wheels Included)  
- 1x Metal Caster Ball  
- 3x TCRT5000 IR Sensors (Analog/Digital)  
- 1x USB Micro A Cable (with data support)  
- 1x Battery Holder (4x AAA)  
- 4x AAA Batteries (1.5V)

###  Software

- [Arduino IDE](https://www.arduino.cc/en/software)  
- RP2040 Board Support (`Arduino Mbed OS RP2040 Boards`)  
- This repo’s sketch file: `Final_LineFollower.ino`


#  Installation Guide

##  Hardware Setup: Building the Robot

### 1.  Assemble the Chassis
- **What’s the chassis?**  
  It’s the frame or “body” of your robot where all components (motors, sensors, wheels, microcontroller) are attached.

- **Steps:**
  1. Unpack all chassis parts and lay them out.
  2. Mount the wheels and motors onto the base using screws provided (Down side).
  3. Attach the metal caster ball at the front (Down side).
  4. Place the **RP2040 microcontroller** and **line sensors** securely on the chassis (Up side).
  5. Ensure all sensors face downward and are **parallel to the ground**.
  6. Use the image below to check if your setup matches:

   ![Robot Build](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/Robot.jpeg?raw=true)

### 2.  Wire All Components

- **Line Sensors:**
  - You have **three analog line sensors** that must be connected correctly:
    - **Left Sensor** → GP27
    - **Center Sensor** → GP26
    - **Right Sensor** → GP28

- **Motors:**
  - Connect the motor wires to the RP2040 pins:
    - **Left Motor:**
      - Forward → GP8
      - Backward → GP9
    - **Right Motor:**
      - Forward → GP10
      - Backward → GP11

  *Tip:* If the motor spins the wrong way, just switch the red and black wires.

- **Power (Battery):**
  - Use a **battery pack (4x AAA 1.5V)**:
    - Red wire → VIN +
    - Black wire → VIN -
  - Double-check polarity — wrong connections could damage the board.

### 3.  Power On the Robot

- Turn ON the switch on your **RP2040 board or battery pack**.
- You should see:
  - A **power LED** on the board.
  - Possibly lights on the motor driver and sensors.
  - If nothing happens, recheck battery connection and polarity.

##  Software Setup: Programming the Robot

> This is where you upload the brain of your robot — the code that makes it follow lines!

### 1.  Install Arduino IDE

- Go to: https://www.arduino.cc/en/software
- Click **“Windows Installer”** (or your OS).
- Download and install the Arduino IDE (just follow the installer steps).

### 2.  Add Board Manager URL

This tells Arduino IDE how to find RP2040 board support.

- Open the Arduino IDE.
- Go to: File > Preferences
- Find the box **“Additional Board Manager URLs”**.
- Paste this link:
  https://downloads.arduino.cc/packages/package_index.json
- Click OK.

### 3.  Install RP2040 Board Support

- Go to: Tools > Board > Boards Manager
- In the search bar, type: RP2040
- Install the package named **"Arduino Mbed OS RP2040 Boards"**

### 4.  Select Your Board

- Go to: Tools > Board
- Choose: Raspberry Pi Pico *(or whatever RP2040 variant you use)*

### 5.  Upload the Code to Your RP2040

- Open the file Final_LineFollower.ino in the Arduino IDE.
- Make sure:
  - Your RP2040 board is **connected via USB cable**.
  - **Batteries are disconnected** to avoid power conflict.
- Click the **Upload (✓)** button in the top left of Arduino IDE.
- Wait for it to compile and upload the code.

> When it says **"Done uploading"**, your code is successfully on the robot!

##  Final Steps & Test Run

1. Disconnect the USB cable.
2. Connect the battery pack.
3. Place the robot on a **black line over white surface**.
4. Turn it on.
5. Watch it follow the line!

If it doesn't follow well, check:
- Sensor alignment and height.
- Line contrast and lighting.
- PID values in the code (`Kp`, `Ki`, `Kd`) — tune if needed.


##  Code Explanation

###  Algorithm – PID Line Following

The robot follows a black line using a **PID controller** (Proportional–Integral–Derivative). The goal is to maintain the robot’s alignment with the line by continuously adjusting motor speeds based on real-time sensor data.

####  How PID Works:

- **Proportional (P):** Corrects based on how far the robot is from the center of the line.
- **Integral (I):** Accumulates past errors to correct long-term drift. (Set to 0 in our case.)
- **Derivative (D):** Predicts future error by measuring the rate of change.

**Formula:**  
PID = (Kp * error) + (Ki * sum of past errors) + (Kd * rate of error change)  
These values adjust the **left and right motor speeds** to steer the robot back to the center line, ensuring smooth, fast, and accurate movement.


###  Functions Breakdown

#### `setup()`
Initializes the microcontroller, sensors, motor driver pins, serial monitor, and onboard LED. Also shows a help message for serial commands.

#### `loop()`
Main execution loop:
- Reads serial input for PID tuning
- Detects the finish line (all 3 sensors on black)
- Computes line position with `readLineWeighted()`
- Calculates PID correction and updates motor speeds using `motorDrive()`

#### `readLineWeighted()`
Calculates the position of the line based on a weighted sum of the 3 IR sensor readings.  
Returns a value between 0 (left) and 7000 (right), or uses previous error direction if the line is lost.

#### `motorDrive(int leftSpeed, int rightSpeed)`
Drives both motors using PWM control. The speed is calculated by the PID controller and constrained between 0–255. Only forward direction is used in this build.


## 👨‍👩‍👧‍👦 Team & Credits

Meet the awesome team behind the bot:

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/TsipiDev">
        <img src="https://avatars.githubusercontent.com/u/182362978?v=4" width="100px;" alt=""/><br/><sub><b>Dimitris Vatousis</b></sub>
      </a><br/>
      <a href="https://www.linkedin.com/in/dimitris-vatousis/"><img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px"/></a>
    </td>
    <td align="center">
      <a href="https://github.com/ankamim">
        <img src="https://avatars.githubusercontent.com/u/185844696?v=4" width="100px;" alt=""/><br/><sub><b>Anna Kamilaki</b></sub>
      </a><br/>
      <a href="https://www.linkedin.com/in/anna-kamilaki-19689a332/"><img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px"/></a>
    </td>
    <td align="center">
      <a href="https://github.com/KPISTOLAS">
        <img src="https://avatars.githubusercontent.com/u/122966880?v=4" width="100px;" alt=""/><br/><sub><b>Konstantinos Pistolas</b></sub>
      </a><br/>
      <a href="https://www.linkedin.com/in/konstantinos-pistolas-aa7a12265/"><img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px"/></a>
    </td>
    <td align="center">
      <a href="https://github.com/Leon1dasV">
        <img src="https://avatars.githubusercontent.com/u/175399369?v=4" width="100px;" alt=""/><br/><sub><b>Leonidas Vogiatzis</b></sub>
      </a><br/>
      <a href="https://www.linkedin.com/in/leonidas-vogiatzis-3a7bb1333/"><img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px"/></a>
    </td>
  </tr>
</table>


##  License

This project is licensed under the [MIT License](./LICENSE).  
Feel free to use, modify, and share — just give credit where it's due 🤝



