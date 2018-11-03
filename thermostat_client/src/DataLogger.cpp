#include "DataLogger.hpp"
#include "Config.hpp"

void DataLogger::setup() {
    Serial.println("Start dataLoger");
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);
    //connectToWifi();
    display = new Display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
}


void DataLogger::loop() {
    if (!isWorkTime(lastTime, millis(), 1000 * 60)) {
        return;
    }

    value.setValue(temperatureSensor->getTemperature());

    Serial.print("T: ");
    Serial.println(value.getValue());


    Notify notify = Notify_init_zero;
    notify.current = value.getValue();
    notify.has_current = true;

    Temperature temperature = Temperature_init_zero;
    temperature.notify = notify;
    temperature.has_notify = true;

    if (client->connect()) {
        client->send(&temperature);
    } else {
        Serial.println("Error connection");
    }
    display->draw(value.getValue());

    lastTime = millis();
}


bool DataLogger::isWorkTime(unsigned long prevMillis, unsigned long currentMillis, int interval) {
    if (currentMillis < prevMillis) {//проверка обнуления миллисекунд раз в 50 дней
        prevMillis = currentMillis;
    }
    return (currentMillis - prevMillis) >= interval;
}

DataLogger::DataLogger(DataLoggerClient *client) : client(client) {
    temperatureSensor = new TemperatureSensor(SENSOR_PIN);

}
