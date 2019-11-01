//
// Created by Artur Strzepka on 23/10/2019.
//
#ifndef SEQUENCER_MIDI_COMMUNICATION_H
#define SEQUENCER_MIDI_COMMUNICATION_H

#include <Arduino.h>
#include <MIDI.h>

extern midi::MidiInterface<HardwareSerial> MIDI;

void initMidi();
void handleNoteOn(byte channel, byte note, byte velocity);
void handleNoteOff(byte channel, byte note, byte velocity);

#endif //SEQUENCER_MIDI_COMMUNICATION_H
