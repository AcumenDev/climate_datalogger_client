#ifndef CONFIG_SERVER_HPP
#define CONFIG_SERVER_HPP

#include "Worker.hpp"
#include "Config.hpp"
#include "ConfigPage.hpp"
#include <ESP8266WebServer.h>

#include <ESP8266WiFi.h>

class ConfigServer : public Worker {


    ESP8266WebServer *server;

    String webPage();

public:
    void setup() override;

    void loop() override;

    String getConfigPage() const;
};

#endif
