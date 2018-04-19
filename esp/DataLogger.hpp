#ifndef DATA_LOGGER_HPP
#define DATA_LOGGER_HPP


#include <ESP8266WiFi.h>
#include <Adafruit_BME280.h>
#include "Temperature.pb.h"
#include "BaseMessage.pb.h"
#include "PBUtilsKey.hpp"

#include "Worker.hpp"

#define BME_280_ADDRESS 0x76




#define ESP_SSID "vst" // Your network name here
#define ESP_PASS "2365hj6578" // Your network password here

#define HOST     "192.168.1.54"     // Host to contact  192.168.1.54
#define PAGE "/api/input" // Web page to request  /api/input
#define PORT     9999                     // 80 = HTTP default port

#define LED_PIN  13

#define USER "akum"
#define TYPE 4
#define ROOM 1
#define NUM 1


class DataLogger : public Worker {

    Adafruit_BME280 bme;

    long lastTime = 0;
    WiFiClient client;


  public:
    void setup() override;
    void loop() override;
  private:
    void connectToWifi() ;
    void initBME();
    bool isWorkTime(unsigned long prevMillis, unsigned long currentMillis, int interval);
};

#endif
