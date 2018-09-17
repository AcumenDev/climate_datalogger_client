#ifndef DATA_LOGGER_HPP
#define DATA_LOGGER_HPP


#include <ESP8266WiFi.h>
#include "Temperature.pb.h"
#include "BaseMessage.pb.h"
#include "PBUtilsKey.hpp"

#include "Worker.hpp"
#include "DataLoggerClient.hpp"
#include "Value.hpp"
#include "TemperatureSensor.hpp"


class DataLogger : public Worker {

private:
    Value value;


    long lastTime = 0;
    DataLoggerClient *client;
    TemperatureSensor * temperatureSensor;


    bool isWorkTime(unsigned long prevMillis, unsigned long currentMillis, int interval);


public:

    DataLogger(DataLoggerClient *client);


    void setup() override;

    void loop() override;


};

#endif
