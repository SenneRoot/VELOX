# VELOX

## Introduction

Welcome to VELOX – your gateway to enhancing the speed limits of your Tenways eBike!

VELOX, which stands for **Velocity Enhancement Limit Override X**, is an open-source project aimed at unlocking the potential for increased speed on Tenways eBikes. Our goal is to provide a method to push the boundaries of your eBike's performance.

### Tested models

VELOX has been tested on the following bike model:
- **Tenways CGO 600 Pro**

### Project Goals

The primary objective of VELOX is to empower eBike enthusiasts by offering a solution to elevate the speed limits of their Tenways eBikes. We aim to create a reliable and user-friendly enhancement system that allows riders to experience an amplified velocity.

### Key Features

- **Speed Enhancement:** VELOX offers a controlled method to boost your eBike's speed.
- **User Accessibility:** We aim for a user-friendly interface, making the speed enhancement process straightforward and accessible to all skill levels.

### VELOX PCB

<img src="https://github.com/SenneRoot/VELOX/assets/19331519/a7c199f3-26df-416a-96e1-d0385ec92912" width="500" height="500">
<img src="https://github.com/SenneRoot/VELOX/assets/19331519/dd6fd7a9-e229-4743-9f28-0228c357f167" width="500" height="500">

### Tenways Display-Controller Connection

Tenways employs a 5-pin M6 connector for the display-controller link, featuring the following pinout:

![image](https://github.com/SenneRoot/VELOX/assets/19331519/3c28364e-e618-40ed-aa12-fe8a45441b0e)![image](https://github.com/SenneRoot/VELOX/assets/19331519/890d7ecd-7e0f-4b5d-b129-87f5c4db6df4)


| Pin |     | Function                             |
|-----|-----|--------------------------------------|
| 1   | VCC | Battery+ input                       |
| 2   | Kp  | Power control wire of the controller |
| 3   | GND | GND                                  |
| 4   | RX  | Data receive of the display          |
| 5   | TX  | Data transmit of the display         |

### Dependencies

VELOX relies on the following libraries:
- [megaTinyCore](https://github.com/SpenceKonde/megaTinyCore) - Arduino support for all tinyAVR 0/1/2-Series.
- [EEPROMWearLevel](https://github.com/PRosenb/EEPROMWearLevel) - EEPROMWearLevel bases on the EEPROM library included in the Arduino framework.
It reduces EEPROM wear by writing every new value to an other EEPROM location.

### How to Contribute

We welcome contributions from the community to improve VELOX. Whether you're a developer or enthusiast, your input can help shape a better and more efficient speed enhancement solution for Tenways eBikes. Feel free to explore the code, submit bug reports, propose new features, or join discussions to contribute to this exciting project!

### Disclaimer

VELOX is intended for educational and experimental purposes only. Please be mindful of local laws and regulations regarding eBike modifications. Use VELOX responsibly and at your own risk. VELOX is not responsible for any damages that may occur.

Join us in revolutionizing the speed potential of Tenways eBikes with VELOX!
