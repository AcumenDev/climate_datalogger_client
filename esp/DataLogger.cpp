#include "DataLogger.hpp"

void DataLogger::setup() {
    Serial.println("Start dataLoger");
    initBME();
    //connectToWifi();
}


void DataLogger::loop() {
    if (!isWorkTime(lastTime, millis(), 1000 * 30)) {
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

/*  char buffer[95];
  sprintf(buffer, "{\"u\":\"%s\",\"t\":\"%d\",\"r\":\"%d\",\"n\":\"%d\",\"d\":{\"t\":\"%s\",\"h\":\"%s\",\"p\":\"%s\"}}",
          USER,
          TYPE,
          ROOM,
          NUM,
          String(temp).c_str(),
          String(humidity).c_str(),
          String(pressure).c_str());*/

/*  Serial.println( buffer);*/

    Notify notify = Notify_init_zero;
    notify.current = temp;
    notify.has_current = true;

    Temperature temperature = Temperature_init_zero;
    temperature.notify = notify;
    temperature.has_notify = true;

    if (client->connect()) {
        client->send(&temperature);
    }else{
        Serial.println("Error connection");
    }
    /* Serial.printf("\n[Connecting to %s ... ", HOST);
     if (client.connect(HOST, PORT)) {
         Serial.println("connected]");

         Serial.println("[Sending a request]");
         uint8_t buf[] = {1};
     //    client.write((const uint8_t *) buffer, message_length);
         //    client.print(String("POST /api/input") + " HTTP/1.1\r\n" +
         //                 "Host: " + HOST + ":" + PORT + "\r\n" +
         //                 "Connection: close\r\n"
         //                 "Content-Type: application/json\r\n"
         //                 "Content-Length: " + strlen(buffer) +
         //                 "\r\n\r\n" + buffer + "\r\n\r\n");
         //    Serial.print(String("POST /api/input") + " HTTP/1.1\r\n" +
         //                 "Host: " + HOST + ":" + PORT + "\r\n" +
         //                 "Connection: close\r\n"
         //                 "Content-Type: application/json\r\n"
         //                 "Content-Length: " + strlen(buffer) +
         //                 "\r\n\r\n" + buffer + "\r\n\r\n");

         Serial.println("[Response:]");
         while (client.connected()) {
             if (client.available()) {
                 String line = client.readStringUntil('\n');
                 Serial.println(line);
             }
         }
         client.stop();
         Serial.println("\n[Disconnected]");
     } else {
         Serial.println("connection failed!]");
         client.stop();
     }*/

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
