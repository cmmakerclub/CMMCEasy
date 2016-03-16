#ifndef CMMCEasy_h
#define CMMCEasy_h
#include <Arduino.h>
#include <Ticker.h>

class CMMC_Blink
{
  private:
    unsigned int _ledPin = LED_BUILTIN;

	public:

    void setPin(uint8_t pin) {
      pinMode(_ledPin, OUTPUT);
      digitalWrite(_ledPin, LOW);
      _ledPin = pin;
    }

    Ticker *_ticker;
    CMMC_Blink() {
      _ticker = new Ticker;
    };

    void blink(int ms) {
        _ticker->detach();
        pinMode(_ledPin, OUTPUT);
        digitalWrite(_ledPin, LOW);
        // static int _pin = this->_ledPin;

        auto lambda = [](int ppp) {
            int state = digitalRead(ppp);  // get the current state of GPIOpin pin
            digitalWrite(ppp, !state);     // set pin to the opposite state
        };

        auto function  = static_cast<void (*)(int)>(lambda);
        Serial.printf("%d ms pin = 16 \n", ms);
        _ticker->attach_ms(ms, function, 16);
      }

};


#endif
