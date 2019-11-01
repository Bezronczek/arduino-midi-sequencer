//
// Created by Artur Strzepka on 01/11/2019.
//

#include "lcd.h"
SequencerLCD::SequencerLCD() : LiquidCrystal_I2C(0x27, 20, 4) {}

void SequencerLCD::print_bpm(uint8_t bpm) {
    set_bpm_cursor();
    if (bpm < 100) {
        print(" ");
    }
    print(bpm);
}

void SequencerLCD::clear_bpm() {
    set_bpm_cursor();
    print("   ");
}

void SequencerLCD::set_bpm_cursor() {
    setCursor(17, 0);
}