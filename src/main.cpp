#include <Homie.h>
#include <OnkyoRI.h>

#define ONKYO_PIN D2
#define SOFTWARE_VERSION "0.0.1"

OnkyoRI onkyo(ONKYO_PIN);
HomieNode homieNode("onkyo", "onkyo", "remote");

void loopHandler() {
  onkyo.processing();
}

bool onPower(const HomieRange &range, const String &value) {
  if (value.equalsIgnoreCase("ON") || value == "1") {
    onkyo.send(0x1AF);
  } else {
    onkyo.send(0x1AE);
  }
  return true;
}

bool onCommand(const HomieRange &range, const String &value) {
  onkyo.send(strtol(value.c_str(), nullptr, 0));
  return true;
}

void setup() {
  Serial.begin(115200);
  pinMode(ONKYO_PIN, OUTPUT);
  digitalWrite(ONKYO_PIN, LOW);
  Homie_setFirmware("onkyo", SOFTWARE_VERSION);
  Homie.setLoopFunction(loopHandler);
  homieNode.advertise("power").settable(onPower);
  homieNode.advertise("command").settable(onCommand);
  Homie.setup();
}

void loop() {
  Homie.loop();
}