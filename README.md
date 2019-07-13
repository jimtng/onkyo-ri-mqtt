# onkyo-ri-mqtt

A super simple implementation of an mqtt bridge to Onkyo's RI interface using an ESP8266. This allows you to send an arbitrary command to Onkyo's RI port via MQTT. The implementation is based on [Homie](https://github.com/homieiot/homie-esp8266), which greatly simplifies the code required.

## Background

My LG TV is connected to my Onkyo receiver TX-SR603. 

I have already set up the LG TV remote to do volume up/down and mute using the LG Magic Remote, but it is not able to control the receiver's power.

I would like the receiver to turn on/off automatically based on the power state of the LG TV. This is achieved by connecting both the LG TV and this bridge to OpenHAB.

## Hardware and Wiring

I use a Wemos D1 Mini and connect its D2 pin directly to RI using a 3.5mm mono plug. The tip / centre is the data pin and the sleeve is connected to GND.

## Dependencies
- Built using Platform IO and Visual Studio Code
- [Homie v3](https://github.com/homieiot/homie-esp8266)
- [Onkyo-RI library](https://github.com/docbender/Onkyo-RI)

## Relevant RI Commands

- 0x1A0 Switch Input to Video 3
- When Video 3 is selected:
  - 0x1A2 Volume Up
  - 0x1A3 Volume Down
  - 0x1A4 Mute
  - 0x1A5 Unmute
  - 0x1AE Standby
  - 0x1AF Turn on and switch to Video 3
