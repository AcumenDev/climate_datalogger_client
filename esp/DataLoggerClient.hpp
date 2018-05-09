#ifndef DATA_LOGGER_CLIENT_HPP
#define DATA_LOGGER_CLIENT_HPP

#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include "PBUtilsKey.hpp"

#define ESP_SSID "vst" // Your network name here
#define ESP_PASS "2365hj6578" // Your network password here

#define HOST     "92.63.106.235"     // Host to contact  192.168.1.54
#define PAGE "/api/input" // Web page to request  /api/input
#define PORT     9999


class DataLoggerClient {
private:

    bool static encodeApiKey(pb_ostream_t *stream, const pb_field_t *field, void *const *arg);

    WiFiClient tcpClient;

    bool _auth = false;

    //  WiFiClientSecure tcpClient;
    bool auth(int type, int version);

    void printBytes(const uint8_t *buffer, size_t bufferSize);

public:
    bool connect();

    bool connectWifi();

    bool connectServer();


    bool send(BaseMessage *message);

    bool send(Temperature *message);

};


#endif