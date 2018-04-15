#ifndef CONFIG_SERVER_HPP
#define CONFIG_SERVER_HPP

#include "Worker.hpp"

#include <ESP8266WiFi.h>
class ConfigServer : public Worker {
  public:
    void setup() override;
    void loop() override;
};
#endif
