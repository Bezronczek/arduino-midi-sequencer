//
// Created by Artur Strzepka on 24/10/2019.
//

#ifndef SEQUENCER_CLOCK_H
#define SEQUENCER_CLOCK_H

#include <Arduino.h>

#define RES 3

uint8_t get_bpm();
void on_sixteenth();
void on_beat();
void add_to_avg(uint8_t val);
void calc_bpm();
void on_midi_clock();

// controls
void stop_clock();

#endif //SEQUENCER_CLOCK_H
