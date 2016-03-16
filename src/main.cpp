#include <Arduino.h>
#include <Ticker.h>
#include "../CMMCEasy.h"

// #include "../CMMC_Blink.hpp"


void setup() {
  Serial.begin(115200);
  Serial.println("OK");

  // CMMC_Blink blinker;
  // blinker.setPin(LED_BUILTIN);
  // blinker.blink(30);
  // delay(1000);
  // blinker.blink(100);
  CMMCEasy easy;

  easy.blinker->setPin(LED_BUILTIN);
  easy.blinker->blink(500);
  delay(2000);
  easy.blinker->blink(60);

// CMMC_Blink blinker;
// blinker.setPin(LED_BUILTIN);
// blinker.myblink(300);
    // int LED_BUILTIN = LED_BUILTIN;

    // pinMode(LED_BUILTIN, OUTPUT);
    // digitalWrite(LED_BUILTIN, LOW);
    //
    // static int _pin = LED_BUILTIN;
    // auto lambda = []() {
    //     int state = digitalRead(_pin);  // get the current state of GPIOpin pin
    //     digitalWrite(_pin, !state);     // set pin to the opposite state
    // };
    //
    // t.attach_ms(100, lambda);
    //
}


void loop() {

}
