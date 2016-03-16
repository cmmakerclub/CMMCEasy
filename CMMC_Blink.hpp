#ifndef CMMCBlink_h
#define CMMCBlink_h
#include <Arduino.h>
#include <Ticker.h>

class CMMC_Blink
{
  private:
    unsigned int _ledPin = 0;
    Ticker *_ticker;

	public:
    void setPin(uint8_t pin) {
      pinMode(_ledPin, OUTPUT);
      digitalWrite(_ledPin, LOW);
      _ledPin = pin;
    }

    CMMC_Blink() {
      _ticker = new Ticker;
    };

    CMMC_Blink(Ticker *ticker) {
      _ticker = ticker;
    };

    void blink(int ms, uint8_t pin) {
      this->setPin(pin);
      this->blink(ms);
    }

    void blink(int ms) {
        if (_ledPin == 0) return;
        static int _pin;
        _ticker->detach();
        _pin = this->_ledPin;
        auto lambda = [](int ppp) {
            int state = digitalRead(ppp);  // get the current state of GPIOpin pin
            digitalWrite(ppp, !state);     // set pin to the opposite state
        };
        auto function  = static_cast<void (*)(int)>(lambda);
        _ticker->attach_ms(ms, function, _pin);
      }

};


#endif
