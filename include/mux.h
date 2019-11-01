#ifndef CONTROLS_MUX_H
#define CONTROLS_MUX_H

#include <Arduino.h>
#include "analogmuxdemux.h"

namespace Mux {
    enum class MasterAddress : uint8_t
    {
        s1 = 12,
        s2 = 11,
        s3 = 10,
    };

    enum class SlaveAddress : uint8_t 
    {
        s1 = 9,
        s2 = 8,
        s3 = 7,
    };

    static const uint8_t read_pin = A0;
    static const uint8_t no_pins = 13;

    extern AnalogMux amx;
}

#endif