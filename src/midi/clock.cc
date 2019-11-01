//
// Created by Artur Strzepka on 31/10/2019.
//

#include "clock.h"
#include "lcd.h"

// counters
uint8_t bpm_arr[RES] = {0};
uint8_t sixteenth = 0;
int beat = 0;

// calc_bpm vars
unsigned long last_tick = 0;
unsigned long tick_interval = 0;

uint8_t get_bpm() {
    uint16_t acc = 0;
    for(auto item : bpm_arr) {
        acc += item;
    }
    return acc / RES;
}

void on_sixteenth() {
    sixteenth++;
    calc_bpm();
    if (sixteenth == 16) {
        sixteenth = 0;
    }
}

void on_beat() {
    beat++;
    lcd.print_bpm(get_bpm());
}

void add_to_avg(uint8_t val) {
    for(uint8_t i = 0; i < RES - 1; i++) {
        bpm_arr[i] = bpm_arr[i + 1];
    }
    bpm_arr[RES - 1] = val;
}

void calc_bpm() {
    unsigned long current_tick = micros();
    tick_interval = (current_tick - last_tick) / 1000;

    if (last_tick > 0 && current_tick > 0) {
        add_to_avg((60000 / tick_interval) / 4);
    }
    last_tick = current_tick;
}

void on_midi_clock() {

}

void stop_clock() {
    beat = 0;
    sixteenth = 0;
    lcd.clear_bpm();
}