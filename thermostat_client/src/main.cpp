#include "Config.hpp"
#include "ConfigServer.hpp"
#include "DataLogger.hpp"
#include "DataLoggerClient.hpp"
#include "Display.hpp"
#include "EEPROMUtils.hpp"

Worker *work;
bool runType = 1  ;

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();
  pinMode(16, INPUT_PULLUP);
  runType = digitalRead(16);
  Display *display = new Display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
  EEPROMUtils::begin();
  if (runType) {
    work = new DataLogger(new DataLoggerClient());
  } else {
    work = new ConfigServer();
  }
  work->setup();
}

void loop() { work->loop(); }
