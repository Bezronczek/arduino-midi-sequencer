#include "buttons.h"

#include "lcd.h"
#include "midi_notes.h"
#include "midi_communication.h"

Buttons::Button buttons[] = {
    Buttons::Button(0, Buttons::ButtonType::note, Notes::C),
    Buttons::Button(1, Buttons::ButtonType::note, Notes::D),
    Buttons::Button(2, Buttons::ButtonType::note, Notes::E),
    Buttons::Button(3, Buttons::ButtonType::note, Notes::F),
    Buttons::Button(4, Buttons::ButtonType::note, Notes::G),
    Buttons::Button(5, Buttons::ButtonType::note, Notes::A),
    Buttons::Button(6, Buttons::ButtonType::note, Notes::B),
    Buttons::Button(7, Buttons::ButtonType::note, Notes::C2),
    Buttons::Button(8, Buttons::ButtonType::note, Notes::C_SHARP),
    Buttons::Button(9, Buttons::ButtonType::note, Notes::D_SHARP),
    Buttons::Button(10, Buttons::ButtonType::note, Notes::F_SHARP),
    Buttons::Button(11, Buttons::ButtonType::note, Notes::G_SHARP),
    Buttons::Button(12, Buttons::ButtonType::note, Notes::A_SHARP),
};

uint8_t size = sizeof(buttons) / sizeof(buttons[0]);
int octave = 4;


void on_note_button_press(int t_button_data) {
    lcd.clear();
    char message[20];
    int note = (t_button_data) + (OCTAVE_RANGE * octave);
    sprintf(message, "Note on:  %d", note);
    lcd.print(message);
    MIDI.sendNoteOn(note, 90, 1);
}

void on_note_button_release(int t_button_data) {
    lcd.clear();
    int note = (t_button_data) + (OCTAVE_RANGE * octave);
    char message[20];
    sprintf(message, "Note off: %d", note);
    lcd.print(message);
    MIDI.sendNoteOff(note, 90, 1);
}

void init_buttons() {
    for (uint8_t i = 0; i < size; i++) {
        buttons[i].on_press(on_note_button_press);
        buttons[i].on_release(on_note_button_release);
    }
}

void read_buttons() {
    for (uint8_t i = 0; i < size; i++) {
        buttons[i].read();
    }
}