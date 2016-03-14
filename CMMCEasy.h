#ifndef CMMCEasy_h
#define CMMCEasy_h

#endif
#include <Arduino.h>
#include <Ticker.h>
// #include "./CMMC_Blink.hpp"

class CMMC_Blink
{
  private:
    uint8_t _ledPin = 255;
    Ticker _ticker;


	public:
    static void _toggle() {
        int state = digitalRead(16);  // get the current state of GPIOpin pin
        digitalWrite(16, !state);     // set pin to the opposite state
        Serial.println(state);
    }

    void setPin(uint8_t pin) {
      _ledPin = pin;
    }

    void _setPin(int state) {
      digitalWrite(1, state);
    }
    void myblink(uint32_t ms) {
        Ticker _ticker;
        _ticker.detach();
        pinMode(16, OUTPUT);
        digitalWrite(16, LOW);

        delay(500);
        digitalWrite(16, HIGH);

        auto lambda = [](int _pin) {
            int state = digitalRead(_pin);  // get the current state of GPIOpin pin
            digitalWrite(_pin, !state);     // set pin to the opposite state
        };

        auto function  = static_cast<void (*)(int)>(lambda);
        _ticker.attach_ms(ms, function, 16);
}


    void blink(uint8_t ms) {
      Serial.print(_ledPin);
      Serial.print(" ");
      Serial.println(ms);
      if(_ledPin != 255) {
        // _ticker.detach();

        pinMode(_ledPin, OUTPUT);
        digitalWrite(_ledPin, LOW);

        int _nat = this->_ledPin;
        auto lambda = []() {
            int state = digitalRead(16);  // get the current state of GPIOpin pin
            digitalWrite(16, !state);     // set pin to the opposite state
            Serial.println(state);
        };
        //
        // auto ff  = static_cast<void (*)(int)>(lambda);
        // _ticker.attach_ms(25, _setPin, _ledPin);
        Serial.println("ATTACH");
        _ticker.attach_ms(ms, CMMC_Blink::_toggle);
      }
    }

};


class CMMCEasy
{
	public:
    CMMC_Blink blinker;

};
