//
// Created by vst on 5/26/18.
//

#ifndef ESP_VALUE_HPP
#define ESP_VALUE_HPP


class Value {
    float value = 0;


public:
    float getValue() const {
        return value;
    }

    void setValue(float value) {
        Value::value = value;
    }

};


#endif //ESP_VALUE_HPP
