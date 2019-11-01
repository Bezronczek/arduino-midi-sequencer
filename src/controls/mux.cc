#include "mux.h"

namespace Mux {
    AnalogMux amx(
        (uint8_t) MasterAddress::s1,
        (uint8_t) MasterAddress::s2,
        (uint8_t) MasterAddress::s3,
        (uint8_t) SlaveAddress::s1,
        (uint8_t) SlaveAddress::s2,
        (uint8_t) SlaveAddress::s3,
        (uint8_t) read_pin
    );
}
