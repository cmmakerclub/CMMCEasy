#ifndef CMMCBlink_h
#define CMMCBlink_h
#include <Arduino.h>
#include <Ticker.h>

class CMMC_Blink
{
  private:
    unsigned int _ledPin = 254;
    Ticker *_ticker;

	public:
    void setPin(uint8_t pin) {
      pinMode(_ledPin, OUTPUT);
      digitalWrite(_ledPin, LOW);
      _ledPin = pin;
    }

    CMMC_Blink() {
      this->_ticker = new Ticker;
    };

    CMMC_Blink(Ticker *ticker) {
      this->_ticker = ticker;
    };

    void blink(int ms, uint8_t pin) {
      this->setPin(pin);
      this->blink(ms);
    }

    void blink(int ms) {
        if (_ledPin == 254) return;
        static int _pin = this->_ledPin;
        this->_ticker->detach();
        auto lambda = []() {
            int state = digitalRead(_pin);  // get the current state of GPIOpin pin
            digitalWrite(_pin, !state);     // set pin to the opposite state
        };
        // auto function  = static_cast<void (*)(int)>(lambda);
        this->_ticker->attach_ms(ms, lambda);
      }

};


#endif
