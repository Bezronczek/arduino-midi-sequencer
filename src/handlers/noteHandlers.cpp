#include "sequencer.h"
#include "lcd.h"

void handleNoteOn(byte channel, byte note, byte velocity) {
  lcd.home();
  lcd.setCursor(0, 0);
  lcd.print("Channel: ");
  lcd.print(channel);
  lcd.print("  ");
  lcd.setCursor(0, 1);
  lcd.print("Note: ");
  lcd.print(note);
  lcd.print("  ");
  lcd.setCursor(0, 2);
  lcd.print("Velocity: ");
  lcd.print(velocity);
  lcd.print("  ");
}

void handleNoteOff(byte channel, byte note, byte velocity) {
}