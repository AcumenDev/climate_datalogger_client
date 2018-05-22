//
// Created by vst on 5/22/18.
//

#include <cstdint>
#include "TemperatureSensor.hpp"


TemperatureSensor::TemperatureSensor(uint8_t pin) {
    searchSensors();
    this->oneWire = new OneWire(pin);
    this->ds = new DallasTemperature(oneWire);
    this->ds->begin();
}

float TemperatureSensor::getTemperature() {
    ds->requestTemperatures();
    return ds->getTempC(sensorAdr);
}

const uint8_t *TemperatureSensor::searchSensors() {

    DEBUG_PRINTLN("")
    int number = 0;
    while (oneWire->search(sensorAdr)) {
        ++number;
        DEBUG_PRINT((int) number);
        DEBUG_PRINT(" : ")
        for (int i = 0; i < 8; i++) {
            DEBUG_PRINT(' ')
            DEBUG_PRINT(sensorAdr[i], HEX)
        }
        DEBUG_PRINTLN("")
        //return addr;
    }

    if (number == 0) {
        DEBUG_PRINTLN("Sensors not found!")
    }
}