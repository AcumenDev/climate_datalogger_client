#include "ConfigServer.hpp"
#include "DataLogger.hpp"

Worker * work;
bool runType = 1;

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(14, INPUT_PULLUP);
  runType = digitalRead(14);

  if (runType) {
    work = new DataLogger();
  } else {
    work = new ConfigServer();
  }

  work->setup();
}


void loop() {
  work->loop();
}
