#include "DataLogger.hpp"

void DataLogger::setup() {
    Serial.println("Start dataLoger");
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);
    initBME();
    //connectToWifi();
}


void DataLogger::loop() {
    if (!isWorkTime(lastTime, millis(), 1000 * 60)) {
        return;
    }


    float temp = bme.readTemperature();
    float humidity = bme.readHumidity();
    float pressure = bme.readPressure();
    Serial.print("T: ");
    Serial.println(temp);
    Serial.print("H: ");
    Serial.println(humidity);
    Serial.print("P: ");
    Serial.println(pressure);


    Notify notify = Notify_init_zero;
    notify.current = temp;
    notify.has_current = true;

    Temperature temperature = Temperature_init_zero;
    temperature.notify = notify;
    temperature.has_notify = true;

    if (client->connect()) {
        client->send(&temperature);
    } else {
        Serial.println("Error connection");
    }

    lastTime = millis();
}


bool DataLogger::isWorkTime(unsigned long prevMillis, unsigned long currentMillis, int interval) {
    if (currentMillis < prevMillis) {//проверка обнуления миллисекунд раз в 50 дней
        prevMillis = currentMillis;
    }
    return (currentMillis - prevMillis) >= interval;
}

void DataLogger::initBME() {
    bool status = bme.begin(BME_280_ADDRESS);
    delay(500);
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
}

DataLogger::DataLogger(DataLoggerClient *client) : client(client) {}
