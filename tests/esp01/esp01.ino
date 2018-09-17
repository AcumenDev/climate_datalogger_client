#include "Adafruit_ESP8266.h"
#include <SoftwareSerial.h>
#include <Adafruit_BME280.h>
#include <stdlib.h>

#define ARD_RX_ESP_TX   2
#define ARD_TX_ESP_RX   3
#define ESP_RST         4
SoftwareSerial softser(ARD_RX_ESP_TX, ARD_TX_ESP_RX); // Arduino RX = ESP TX, Arduino TX = ESP RX

// Must declare output stream before Adafruit_ESP8266 constructor; can be
// a SoftwareSerial stream, or Serial/Serial1/etc. for UART.
Adafruit_ESP8266 wifi(&softser, &Serial, ESP_RST);
// Must call begin() on the stream(s) before using Adafruit_ESP8266 object.

#define ESP_SSID "vst" // Your network name here
#define ESP_PASS "" // Your network password here

#define HOST     "192.168.1.54"     // Host to contact  192.168.1.54
#define PAGE     "/api/input" // Web page to request  /api/input
#define PORT     8080                     // 80 = HTTP default port

#define LED_PIN  13


#define BME_280_ADDRESS 0x76
Adafruit_BME280 bme;

long lastTime = 0;


#define USER "akum"
#define TYPE 4
#define ROOM 1
#define NUM 1



void initBME() {
  bool status = bme.begin(BME_280_ADDRESS);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  }
}

void initEsp() {
  softser.begin(9600); // Soft serial connection to ESP8266
  char buffer[100];
  Serial.println(F("Adafruit ESP8266 Demo"));

  Serial.print(F("Checking firmware version..."));
  wifi.println(F("AT+GMR"));
  if (wifi.readLine(buffer, sizeof(buffer))) {
    Serial.println(buffer);
    wifi.find(); // Discard the 'OK' that follows
  } else {
    Serial.println(F("Error ESP8266 init"));
    return;
  }
}

void connectToWifi() {
  Serial.print(F("Connecting to WiFi..."));
  if (!wifi.connectToAP(F(ESP_SSID), F(ESP_PASS))) {
    Serial.println(F("FAIL"));// WiFi connection failed
    return;
  }

  Serial.print(F("OK\nSet DNS IP addr..."));
  wifi.println(F("AT+CIPDNS_DEF=1,\"77.88.8.1\""));
  if (wifi.find(F("OK"))) {
    Serial.print(F("OK\n"));

    return;
  }
  Serial.println(F("Error DNS"));
}


bool wifiAvailable() {
  Serial.print(F("Checking IP addr..."));
  wifi.println(F("AT+CIFSR"));
  char buffer[100];
  if (wifi.readLine(buffer, sizeof(buffer))) {
    Serial.println(buffer);
    wifi.find(); // Discard the 'OK' that follows
  }  else { // IP addr check failed
    Serial.println(F("error"));
    return false;
  }
  return true;
}


void postData(char* url, char* data) {
  Serial.print(F("Connecting to host..."));
  if (wifi.connectTCP(F(HOST), PORT)) {
  } else { // TCP connect failed
    Serial.println(F("D'oh!"));
    return;
  }

  Serial.print(F("OK\nRequesting page..."));
  if (wifi.sendPost(url, data)) {
    Serial.println("OK\nSearching for string...");
    // Search for a phrase in the open stream.
    // Must be a flash-resident string (F()).
  } else { // URL request failed
    Serial.println(F("error"));
  }

  if (!wifi.closeTCP()) {
    Serial.println(F("Error CLOSED connect"));
  }

}


void setup() {
  Serial.begin(9600);
  initBME();
  initEsp();

  connectToWifi();
}


static bool isWorkTime(unsigned long prevMillis, unsigned long currentMillis, int interval) {
  if (currentMillis < prevMillis) {//проверка обнуления миллисекунд раз в 50 дней
    prevMillis = currentMillis;
  }
  return (currentMillis - prevMillis) >= interval;
}

const char *floatToStr(float value) {
  char buf[8];
  return dtostrf(value, 2, 2, buf);
}


const char *floatToStr(float value, char* buff) {
  return dtostrf(value, 2, 2, buff);
}

//{
//  "user":"user1",
//  "type":"4",
//  "room":"1",
//  "num":"1",
//  "data":{
//     "t":"13.44",
//     "h":"12.33",
//     "p":"123123.43"
//  }
//}


void loop() {

  if (isWorkTime(lastTime, millis(), 1000 * 30))
  {

    char temp[8];
    floatToStr(bme.readTemperature(), temp);
    char humidity[8] ;
    floatToStr(bme.readHumidity(), humidity);
    char pressure[8] ;
    floatToStr(bme.readPressure(), pressure);

    Serial.print("T: ");
    Serial.println(temp);
    Serial.print("H: ");
    Serial.println(humidity);
    Serial.print("P: ");
    Serial.println(pressure);

    char buffer[95];
    sprintf(buffer, "{\"u\":\"%s\",\"t\":\"%d\",\"r\":\"%d\",\"n\":\"%d\",\"d\":{\"t\":\"%s\",\"h\":\"%s\",\"p\":\"%s\"}}",
            USER,
            TYPE,
            ROOM,
            NUM,
            temp,
            humidity,
            pressure);


    Serial.println( buffer);

    if (!wifiAvailable()) {
      connectToWifi();
    }

    postData(PAGE, buffer); 

    lastTime = millis();
  }
}
