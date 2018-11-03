//
// Created by vst on 5/22/18.
//

#ifndef ESP_TEMPERATURESENSOR_HPP
#define ESP_TEMPERATURESENSOR_HPP

#include <OneWire.h>
#include <DallasTemperature.h>


class TemperatureSensor {
    OneWire *oneWire;
    DallasTemperature *ds;
    uint8_t sensorAdr[8];


    const uint8_t *searchSensors();

public:
    TemperatureSensor(uint8_t pin);

    float getTemperature();
};


#endif //ESP_TEMPERATURESENSOR_HPP
