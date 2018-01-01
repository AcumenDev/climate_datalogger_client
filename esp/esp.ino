#include "ConfigServer.hpp"
#include "DataLogger.hpp"


DataLogger* dataLogger;
ConfigServer* configServer;

bool status = 1;

void setup() {
 // Serial.begin(115200);
  Serial.println();
  pinMode(14, INPUT_PULLUP);
  status = digitalRead(14);


  if (status) {
    dataLogger = new DataLogger();
    dataLogger->setup();
  } else {
    configServer = new ConfigServer();
    configServer->setup();
  }
}


void loop() {
  if (status) {
    dataLogger->loop();
  } else {
    configServer->loop();
  }
}
