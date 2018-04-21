#ifndef DATA_LOGGER_HPP
#define DATA_LOGGER_HPP


#include <ESP8266WiFi.h>
#include <Adafruit_BME280.h>
#include "Temperature.pb.h"
#include "BaseMessage.pb.h"
#include "PBUtilsKey.hpp"

#include "Worker.hpp"
#include "DataLoggerClient.hpp"

#define BME_280_ADDRESS 0x76


class DataLogger : public Worker {

private:

    Adafruit_BME280 bme;

    long lastTime = 0;
    DataLoggerClient *client;


    void initBME();

    bool isWorkTime(unsigned long prevMillis, unsigned long currentMillis, int interval);


public:

    DataLogger(DataLoggerClient *client);


    void setup() override;

    void loop() override;


};

#endif
