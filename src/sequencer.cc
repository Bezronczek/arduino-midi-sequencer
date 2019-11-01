#include "buttons.h"
#include "lcd.h"
#include "midi_communication.h"

SequencerLCD lcd;

void initLcd() {
  lcd.init();
  lcd.backlight();
  lcd.print("Ready");
}

void setup() {
  initLcd();
  initMidi();
  init_buttons();
}

void loop() {
  MIDI.read();
  read_buttons();
}
