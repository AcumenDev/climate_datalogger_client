//
// Created by vst on 5/22/18.
//

#include <cstdint>
#include "TemperatureSensor.hpp"


TemperatureSensor::TemperatureSensor(uint8_t pin) {

    this->oneWire = new OneWire(pin);
    searchSensors();
    this->ds = new DallasTemperature(oneWire);
    this->ds->begin();

}

float TemperatureSensor::getTemperature() {
    ds->requestTemperatures();
    return ds->getTempC(sensorAdr);
}

const uint8_t *TemperatureSensor::searchSensors() {


    Serial.print("TemperatureSensor\nsearch ");
    int number = 0;
    while (oneWire->search(sensorAdr)) {
        ++number;
        Serial.print(number);
        Serial.print(" : ");
        for (int i = 0; i < 8; i++) {
            Serial.print(" ");
            Serial.print(sensorAdr[i], HEX);

        }
        Serial.println(" ");
        //return addr;
    }

    if (number == 0) {
        Serial.println("Sensors not found!");
    }
}