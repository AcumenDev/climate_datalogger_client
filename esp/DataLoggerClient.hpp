#ifndef DATA_LOGGER_CLIENT_HPP
#define DATA_LOGGER_CLIENT_HPP

#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include "PBUtilsKey.hpp"
#include "EEPROMUtils.hpp"


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