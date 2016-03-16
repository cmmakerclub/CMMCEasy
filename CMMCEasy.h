#ifndef CMMCEasy_h
#define CMMCEasy_h

#endif
#include <Arduino.h>
#include "./CMMC_Blink.hpp"

class CMMCEasy
{
  private:
    // Ticker *_ticker1;

	public:
    CMMC_Blink blinker;

    CMMCEasy() {
      // _ticker1 = new Ticker;
      // blinker = new CMMC_Blink;
    };

    ~CMMCEasy() {
      // delete _ticker1;
      // delete blinker;
    };


};
