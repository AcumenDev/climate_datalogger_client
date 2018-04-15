#ifndef DATA_LOGGER_CLIENT_HPP
#define DATA_LOGGER_CLIENT_HPP
#include <WiFiClientSecure.h>

class DataLoggerClient {

  WiFiClientSecure client;
  public:

    bool auth(int type, int version, char[] apiKey ) {

    }
};


#endif
