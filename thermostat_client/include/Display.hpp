//
// Created by vst on 5/13/18.
//

#ifndef ESP_DISPLAY_HPP
#define ESP_DISPLAY_HPP

#include "TM1637.h"

class Display {
    TM1637 *tm;

public:
    Display(uint8_t clk, uint8_t data) {
        Serial.println("Display started");
        // Serial.println("clk" + clk);
        // Serial.println("data" + data);
        tm = new TM1637(clk, data);
        tm->init();
        tm->set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST =
        tm->display(3, 1);
        tm->display(2, 2);
        tm->display(1, 3);
        tm->display(0, 4);
    }

    void draw(float value) {
        tm->displayNum(value);
    }

};


#endif //ESP_DISPLAY_HPP
