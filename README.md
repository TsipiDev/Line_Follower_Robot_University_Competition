# Line Follower Robot University Competition

## Description

This project was made as an entry to our university's 📟Embedded Systems📟 course competition. The goal of the competition and of this repository was to make a line follower robot🤖 from scratch that can complete all of the 3 stages in the competition.
Moreover this repository also serves as a guide📖 to how you can build our robot, from the components⚙️ you gonna need and the robot's code👨🏻‍💻 to building it and putting it all together. If you wanna build our model or create your own based on our robot then feel free just make sure you give us a mention in your project!! Our main focus📌 for this line follower was for it to be fast⚡️ and able to handle various "weather conditions"☁️ that could be present in the stages along with sharp turns and sudden stops, these factors heavily affected our design and coding decisions as well as which parts we picked.

## Table of Contents
- [Stages](#stages)
- [Requirements](#requirements)
- [Installation](#installation)
- [Code_Explaination](#code_explaination)
- [Credits](#credits)

## Stages

Stage 1:

![Alt text](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/stage1.jpg?raw=true)

Stage 2:

![Alt text](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/stage2.jpg?raw=true)

Stage 3:

![Alt text](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/stage3.jpg?raw=true)


## Requirements
Hardware:
- 1x Maker PI RP2040 Microcontroller  
- 1x Battery Holder for 4 AA Batteries  
- 1x Metal Caster Ball  
- 1x 2-Wheel, 1 Metal Caster Ball Chassis  
- 1x USB Micro A Cable (supports data transfer)  
- 2x DC N20 Motors  
- 3x TCRT5000 Analog/Digital Infrared Sensors  
- 4x AA Batteries 1.5V  

Software:
- Arduino IDE (with extensions installed)
- Final_LineFollower.ino File 

## Installation
Hardware:  
  
  **Step 1:**  
  Secure all the components on the chasis.**Make sure that the sensors are at the correct height and distance apart ( See Robot Picture for reference)**  

  - Robot Picture:
  ![Alt text](https://github.com/TsipiDev/Line_Follower_Robot_University_Competition/blob/main/Robot.jpeg?raw=true)

  **Step 2:**  
  Connect the components to the following pins:  
  - Left Sensor GP27
  - Center Sensor GP26
  - Right Sensor GP28
  - Left Motor Red GP8 (MA)
  - Left Motor Black GP9 (MA)
  - Right Motor Red GP10 (MB)
  - Right Motor Black GP11 (MB)
  - Red Wire of Battery Pack in the + of the VIN
  - Black Wire of Battery Pack in the - of the VIN

  **Step 3:**  
  Once everything is connected turn the RP2040 ON using the switch and see if everything powers up (Mostly Sensors and Microcontroller).<br>
  <br>
Software:  

  **Step 1:**  
  Download and install the latest version of Arduino IDE.  

  **Step 2:**
  Open the Arduino IDE and go to File > Preferences. In "Additional Board Manager URLs", paste:  
  https://downloads.arduino.cc/packages/package_index.json  
  Click OK  

  **Step 3:**  
  Go to Tools > Board > Boards Manager.Search for "mbed rp2040" or just "rp2040" and Install "Arduino Mbed OS RP2040 Boards".  

  **Step 4:**  
  Go to Tools > Board and select Raspberry Pi Pico (or another RP2040 board, depending on what's listed)  

  **Step 5:**
  Open the Final_LineFollower.ino file, connect the RP2040 to the computer with the Micro USB cable **(MAKE SURE THE BATTERY IS NOT CONNECTED TO THE BOARD)** and upload the code.  

## Code Explaination  
Coming soon.
  
  
## Credits
**✨Our team:**
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/TsipiDev"><img src="https://avatars.githubusercontent.com/u/182362978?v=4" width="100px;"/><br/><sub><b>Dimitris Vatousis</b></sub></a><br/><br>
      <a href="https://www.linkedin.com/in/dimitris-vatousis/"> <img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px;"/></a></td>  
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/ankamim"><img src="https://avatars.githubusercontent.com/u/185844696?v=4" width="100px;"/><br/><sub><b>Anna Kamilaki</b></sub></a><br/><br>
      <a href="https://www.linkedin.com/in/anna-kamilaki-19689a332/"> <img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px;"/></a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/KPISTOLAS"><img src="https://avatars.githubusercontent.com/u/122966880?v=4" width="100px;"/><br/><sub><b>Konstantinos Pistolas</b></sub></a><br/><br>
      <a href="https://www.linkedin.com/in/konstantinos-pistolas-aa7a12265/"> <img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px;"/></a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://www.linkedin.com/in/leonidas-vogiatzis-3a7bb1333/"><img src="https://media.licdn.com/dms/image/v2/D4D03AQEkCNxpv8eZTg/profile-displayphoto-shrink_800_800/profile-displayphoto-shrink_800_800/0/1729271548808?e=1746057600&v=beta&t=HjnmZ0X9XDFJjw2kk98G1xqML1nJ1XJPLPweyqTwfaY" width="100px;"/><br/><sub><b>Leonidas Vogiatzis</b></sub></a><br/><br>
      <a href="https://www.linkedin.com/in/leonidas-vogiatzis-3a7bb1333/"> <img src="https://upload.wikimedia.org/wikipedia/commons/c/ca/LinkedIn_logo_initials.png" width="20px;"/></a></td>
    </tr>  
  </tbody>
</table>

