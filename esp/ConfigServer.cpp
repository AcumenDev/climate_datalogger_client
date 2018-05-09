#include "ConfigServer.hpp"


void ConfigServer::setup() {
    Serial.println("Start ConfigServer");
    Serial.print("Setting soft-AP ... ");
    Serial.println("Ready");
//    byte arduino_mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED};
    IPAddress ip(192, 168, 1, 1);
    IPAddress gateway(192, 168, 1, 1);
    IPAddress subnet(255, 255, 255, 0);
    WiFi.softAPConfig(ip, gateway, subnet);
    boolean result = WiFi.softAP(AP_WIFI_NETWORK_SSID, AP_WIFI_NETWORK_PASSWORD);
    WiFi.printDiag(Serial);
    if (result) {

        //    ESP8266WebServer server(80);


    } else {
        Serial.println("Failed!");
    }


    server = new ESP8266WebServer(80);


    static const char configPage[] PROGMEM = "<!DOCTYPE html><html lang='en'><head><title>TermostatConаig</title></head><body><h3>Config page</h3><form action='/update' method='post'><table><tr><td>Wifi name:</td><td><input type='text' size='40' name='wifi_name'></td></tr><tr><td>Wifi password:</td><td><input type='text' size='40' name='wifi_passwd'></td></tr><tr><td colspan='2'><hr></td></tr><tr><td>Url:</td><td><input type='text' size='40' name='url'></td></tr><tr><td>ApiKey:</td><td><input type='text' size='40' name='apikey'></td></tr><tr><td colspan='2'><hr></td></tr><tr><td colspan='2'>To enable collect of indications and control?<input type='checkbox' name='enable'></td></tr></table><br><input type='submit' value='Save'></form></body></html>";

    server->on("/", [this](){
        server->send(200, "text/html", FPSTR(configPage));
    });

/*    server->on("/", []() {
        server->send(200, "text/html", "test server");
    });*/
    /* server.on("/socket1On", []() {
         digitalWrite(D0_pin, HIGH);
         server.send(200, "text/html", webPage());
         delay(100);

     });
     server.on("/socket1Off", []() {
         digitalWrite(D0_pin, LOW);
         server.send(200, "text/html", webPage());
         delay(100);


     });*/
    server->begin();
    Serial.println("HTTP server started");

}

void ConfigServer::loop() {

    server->handleClient();

}


String ConfigServer::webPage() {
    String web;
    web += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/> <meta charset=\"utf-8\"><title>ESP 8266</title><style>button{color:red;padding: 10px 27px;}</style></head>";
    web += "<h1 style=\"text-align: center;font-family: Open sans;font-weight: 100;font-size: 20px;\">ESP8266 Web Server</h1><div>";
    //++++++++++ LED-1  +++++++++++++
    web += "<p style=\"text-align: center;margin-top: 0px;margin-bottom: 5px;\">----LED 1----</p>";
    /*  if (digitalRead(D0_pin) == 1)
      {
          web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">ON</div>";
      }
      else
      {*/
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">OFF</div>";
    //  }
    web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"socket1On\"><button>ON</button></a>&nbsp;<a href=\"socket1Off\"><button>OFF</button></a></div>";
    // ++++++++ LED-1 +++++++++++++


    // ========REFRESH=============
    web += "<div style=\"text-align:center;margin-top: 20px;\"><a href=\"/\"><button style=\"width:158px;\">REFRESH</button></a></div>";
    // ========REFRESH=============


    web += "</div>";
    return web;
}
