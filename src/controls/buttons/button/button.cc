#include "button.h"
#include "mux.h"

namespace Buttons {
    Button::Button(uint8_t t_pin, ButtonType t_type, int t_button_data)
    : m_pin{t_pin}
    , m_type{t_type}
    , m_button_data{t_button_data}
    , m_button_state{LOW}
    , m_last_button_state{LOW}
    , m_on_press_cb{0}
    {
    };

    void Button::on_press(void (*cb)(int t_button_data)) {
        m_on_press_cb = cb;
    }

    void Button::on_release(void (*cb)(int t_button_data)) {
        m_on_release_cb = cb;
    }

    uint8_t Button::read_pin() {
        return Mux::amx.DigitalRead(m_pin);
    }

    void Button::read() {
        boolean reading = read_pin();

        if(reading != m_last_button_state) {
            m_last_debounce_time = millis();
        }

        if((millis() - m_last_debounce_time) > m_debounce_time) {
            if (reading != m_button_state) {
                m_button_state = reading;
                if (m_button_state == HIGH) {
                    m_on_press_cb(m_button_data);
                }
                if (m_button_state == LOW) {
                    m_on_release_cb(m_button_data);
                }
            }
        }

        m_last_button_state = reading;
    }
}
