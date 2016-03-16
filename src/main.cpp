#include <Arduino.h>
#include <Ticker.h>
#include "../CMMCEasy.h"

// #include "../CMMC_Blink.hpp"


void setup() {
  Serial.begin(115200);
  Serial.println("OK");

  CMMCEasy easy;

  easy.blinker.blink(100, LED_BUILTIN);
  delay(2000);
  easy.blinker.blink(20, LED_BUILTIN);
  delay(2000);
  easy.blinker.blink(500, LED_BUILTIN);
  delay(5000);
  easy.blinker.blink(100, LED_BUILTIN);
  delay(1000);
  easy.blinker.blink(1000);
  delay(1000);
  easy.blinker.blink(100);

}


void loop() {

}
