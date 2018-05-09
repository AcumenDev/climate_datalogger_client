#include "ConfigServer.hpp"
#include "DataLogger.hpp"
#include "DataLoggerClient.hpp"

Worker *work;
bool runType = 1;

void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    Serial.println();
    pinMode(14, INPUT_PULLUP);
    runType = digitalRead(14);

    if (runType) {
        work = new DataLogger(new DataLoggerClient());
    } else {
        work = new ConfigServer();
    }

    work->setup();
}


void loop() {
    work->loop();
}
