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
    Ticker *_ticker;


	public:

    CMMC_Blink() {
      _ticker = new Ticker;
    }

    ~CMMC_Blink() {
      delete _ticker;
      _ticker = NULL;
    }

    void setPin(uint8_t pin) {
      pinMode(_ledPin, OUTPUT);
      digitalWrite(_ledPin, LOW);
      _ledPin = pin;
    }

    void blink(uint8_t ms) {
      Serial.print(_ledPin);
      Serial.print(" ");
      Serial.println(ms);
      if(_ledPin < 255) {
        _ticker->detach();
        static int _pin = this->_ledPin;
        auto lambda = []() {
            int state = digitalRead(_pin);  // get the current state of GPIOpin pin
            digitalWrite(_pin, !state);     // set pin to the opposite state
        };
        // auto ff  = static_cast<void (*)(int)>(lambda);
        _ticker->attach_ms(ms, lambda);
      }
      else {
        // noop
      }
    }


};


class CMMCEasy
{
	public:
    CMMC_Blink blinker;

};
