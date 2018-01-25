NUSound Arduino Workshop
========================
This repository houses the code and hardware notes for a simple wavetable synthesizer which uses an Arduino and capacitive touch sensing.

Hardware
========
1. Arduino Clone [Amazon Link](https://www.amazon.com/dp/B01EWOE0UU/_encoding=UTF8?coliid=I2GTGOF5FVA7Z9&colid=10SUQNNMJO8W9&psc=0)
2. Jumper Wires [Amazon Link](https://www.amazon.com/120pcs-Multicolored-Breadboard-Arduino-Raspberry/dp/B072L1XMJR/ref=sr_1_2_sspa?s=industrial&ie=UTF8&qid=1516673026&sr=1-2-spons&keywords=male+to+male+jumper+wires&psc=1`)
3. Conductive Tape or Aluminum Foil

Instructions
============
Build Hardware
--------------
1. Attach Conductive tape or alluminum foil to five resistors.  Attach tape/foil as close to resistor bead as possible.
2. Connect resistors in the following pattern:

| Pin (Tape End)        | Pin (No Tape End)     |
|:--------------------: |:---------------------:|
| Digital 2             | Digital 4             |
| Digital 6             | Digital 4             |
| Digital 8             | Digital 4             |
| Digital 10            | Digital 4             |

Compile and Upload Software
---------------------------
1. Download and install Arduino IDE from [The Arduino Website](https://www.arduino.cc/en/Main/Software).  If you are using Windows, you can also use the Windows Store version of the IDE if you already have it installed.
2. Download and install Processing from [The Processing Website](https://processing.org/download/).  
3. Open the Arduino.ino and upload it to the Arduino.  To do this, you will first have to select the correct board type and serial port using the tools menu.
4. Open the Processing.pde with Processing.  You should be able to play notes by touching the foil tape!