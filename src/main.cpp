#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>
BLEMIDI_CREATE_INSTANCE("MIDI Pedal", MIDI);

constexpr uint8_t SWITCH_PIN = 15;
constexpr uint8_t LED_PIN = 2;
constexpr uint8_t PROGRAM_NUM = 0x0A;

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  MIDI.begin();
}

void loop() {
  static bool lastSwitchState = HIGH;
  bool currentSwitchState = digitalRead(SWITCH_PIN);

  if (lastSwitchState == HIGH && currentSwitchState == LOW) {
    MIDI.sendProgramChange(PROGRAM_NUM, 1);
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
  }

  lastSwitchState = currentSwitchState;
  delay(10);
}
