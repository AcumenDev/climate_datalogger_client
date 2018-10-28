//
// Created by vst on 5/13/18.
//

#ifndef ESP_DISPLAY_HPP
#define ESP_DISPLAY_HPP
#include "TM1638lite.h"

class Display {
    TM1638lite * tm;

  public:
    Display(uint8_t clk, uint8_t data) {
      Serial.println("Display started");
     // Serial.println("clk" + clk);
     // Serial.println("data" + data);
      tm = new TM1638lite(16, clk, data);
      tm->reset();

      tm->displayHex(0, 8);
      tm->displayHex(1, 9);
      tm->displayHex(2, 10);
      tm->displayHex(3, 11);
      tm->displayHex(4, 12);
      tm->displayHex(5, 13);
      tm->displayHex(6, 14);
      tm->displayHex(7, 15);
 delay(2000);

    }

};


#endif //ESP_DISPLAY_HPP
