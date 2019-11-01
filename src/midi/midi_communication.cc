//
// Created by Artur Strzepka on 23/10/2019.
//
#include "midi_communication.h"
#include "clock.h"

MIDI_CREATE_DEFAULT_INSTANCE();

uint8_t pulse = 0;
boolean is_playing = false;

void onClock() {
    if (!is_playing) return;
    pulse++;
    if (pulse % 6 == 0) {
        on_sixteenth();
    }
    if (pulse == 24) {
        pulse = 0;
        on_beat();
    }
};

void onStart() {
    is_playing = true;
}

void onStop() {
    is_playing = false;
    stop_clock();
}

void initMidi() {
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    MIDI.setHandleClock(onClock);
    MIDI.setHandleStart(onStart);
    MIDI.setHandleStop(onStop);

    MIDI.begin(MIDI_CHANNEL_OMNI);
}