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

## Setup

Please see [Homie Setup](https://homieiot.github.io/homie-esp8266/docs/develop-v3/quickstart/getting-started/)

## MQTT Usage

Two MQTT topics are exposed for writing:
- `homie/device-name/onkyo/power/set`: `ON`|`OFF`. Internally this sends the command 0x1AF to turn it on and 0x1AE to turn it off. I've set the audio input to Video 3 for this purpose.

- `homie/device-name/onkyo/command/set`: A string representation of the numeric value to be sent to the RI port. It can be in either decimal or Hexadecimal notation, e.g. `0x20`

## Relevant RI Commands

- 0x1A0 Switch Input to Video 3
- When Video 3 is selected:
  - 0x1A2 Volume Up
  - 0x1A3 Volume Down
  - 0x1A4 Mute
  - 0x1A5 Unmute
  - 0x1AE Standby
  - 0x1AF Turn on and switch to Video 3
