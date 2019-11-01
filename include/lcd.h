#include <LiquidCrystal_I2C.h>

class SequencerLCD : public LiquidCrystal_I2C {
public:
    void print_bpm(uint8_t bpm);
    void clear_bpm();
    SequencerLCD();
private:
    void set_bpm_cursor();
};

extern SequencerLCD lcd;
void initLcd();
