#ifndef CONTROLS_BUTTONS_BUTTON_H

#define CONTROLS_BUTTONS_BUTTON_H
#include <Arduino.h>

namespace Buttons {
    enum class ButtonType {
        note,
    };

    class Button {
        public:
            // type name(fptr type (*cbName)(params))
            void on_press(void (*cb)(int t_button_data));
            void on_release(void (*cb)(int t_button_data));
            void read();
            uint8_t read_pin();

            Button(uint8_t pin, ButtonType type, int button_data);
        private:
            uint8_t m_pin;
            ButtonType m_type;
            int m_button_data;

            boolean m_button_state{LOW};
            boolean m_last_button_state{LOW};
            uint16_t m_last_debounce_time{0};
            uint16_t m_debounce_time {50};


            void (*m_on_press_cb)(int t_button_data);
            void (*m_on_release_cb)(int t_button_data);
    };
}


#endif