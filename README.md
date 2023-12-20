# 6CH Relay Remote OSC Commands via ESP32

Trigger OSC commands using a 6-channel relay to an ESP32. 

https://github.com/jshea2/6ButtonRemote_ESP32-OSC/assets/70780576/42421413-7f7d-44b2-85ef-39831e2f9d9f

Equipment:
- ESP32
- [6CH Relay Remote](https://www.amazon.com/gp/product/B08PL29N3R/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1)

Recommended Equipment:
- [Mini Breadboard](https://www.amazon.com/gp/product/B071KCZZ4K/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1)
- [Jumper Wires](https://www.amazon.com/gp/product/B07GD25V8D/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1)
- Wago Connectors
- Micro USB Cable

## Software Setup:
- Clone this repository to VSCode
  - Make sure Platformio extension is installed
- Install dependencies
- Modify `main.cpp`


const char* ssid = `"SSID"`;


const char* pwd = `"PASSWORD"`;


const IPAddress ip(`10, 101, 100, 105`);


const IPAddress gateway(`10, 101, 100, 1`);


const IPAddress subnet(`255, 255, 255, 0`);

const char* host = `"10.101.100.24"`; //This is the Computer receiving the OSC Messages

const char *oscaddress = `"/go/RM5B1"`; // Button 1


const char *oscaddress2 = `"/go/RM5B2"`; // Button 2


const char *oscaddress3 = `"/go/RM5B3"`; // Button 3


const char *oscaddress4 = `"/go/RM5B4"`; // Button 4


const char *oscaddress5 = `"/go/RM5B5"`; // Button 5


const char *oscaddress6 = `"/go/RM5B6"`; // Button 6



- Save changes
- Flash ESP32 with code

## Hardware Setup:
![515MJcuiiPS _AC_SX679_6](https://github.com/jshea2/6ButtonRemote_ESP32-OSC/assets/70780576/bc3c9ed8-ab2f-4873-9918-7798e89e7e22)

<img src="https://github.com/jshea2/6ButtonRemote_ESP32-OSC/assets/70780576/8f5237dd-62fb-4a9b-8e35-d615854dfd39" width="200">
<img src="https://github.com/jshea2/6ButtonRemote_ESP32-OSC/assets/70780576/b650f7ce-3f78-41d3-a7cf-540f8f8a089b" width="200">
<img src="https://github.com/jshea2/6ButtonRemote_ESP32-OSC/assets/70780576/a8518ef5-ecdd-479d-a4b4-29dc72a8030c" width="200">

<br>

This project was designed for USC School of Dramatic Arts production, [Ghosts of USC: A Historical Immersive Haunt](https://dramaticarts.usc.edu/ghosts-of-usc-a-historical-immersive-haunt/). There were 5 of these units for each room to trigger 6 cues. Stage Management discretly used the remotes to trigger QLab. This system triggered sound and lighting cues.

