#include "ConfigServer.hpp"
#include "EEPROMUtils.hpp"


void ConfigServer::setup() {
    Serial.println("Start ConfigServer");
    Serial.print("Setting soft-AP ... ");
    Serial.println("Ready");
//    byte arduino_mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED};
    IPAddress ip(192, 168, 1, 1);
    IPAddress gateway(192, 168, 1, 1);
    IPAddress subnet(255, 255, 255, 0);
    WiFi.persistent(false);
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(ip, gateway, subnet);
    boolean result = WiFi.softAP(AP_WIFI_NETWORK_SSID, AP_WIFI_NETWORK_PASSWORD);
    WiFi.printDiag(Serial);
    if (!result) {
        Serial.println("Failed!");
    }


    server = new ESP8266WebServer(80);

    server->on("/", HTTP_GET, [this]() {
        server->send(200, "text/html", getConfigPage()
        );
    });

    server->on("/", HTTP_POST, [this]() {

        for (int i = 0; i < server->args(); i++) {
            Serial.print("argName: ");
            Serial.print(server->argName(i));
            Serial.print("  argVal: ");
            Serial.println(server->arg(i));

        }

        String wifiName = server->arg("wifi_name");
        EEPROMUtils::writeWifiName(wifiName.c_str(), wifiName.length());


        String wifiPasswd = server->arg("wifi_passwd");
        EEPROMUtils::writeWifiPasswd(wifiPasswd.c_str(), wifiPasswd.length());

        String url = server->arg("url");
        EEPROMUtils::writeUrl(url.c_str(), url.length());


        String apiKey = server->arg("apikey");
        EEPROMUtils::writeApiKey(apiKey.c_str(), apiKey.length());

        EEPROMUtils::writeEnabledRemoteControl(server->hasArg("active") && server->arg("active") == "on");

        EEPROMUtils::commit();


        server->send(200, "text/html", getConfigPage());
    });

/*    server->on("/restart", HTTP_POST, [this]() {
        ESP.reset()
        );
    });*/

    server->begin();
    Serial.println("HTTP server started");

}

String ConfigServer::getConfigPage() const {

    return ConfigPage::getPage(EEPROMUtils::readWifiName(), EEPROMUtils::readWifiPasswd(), EEPROMUtils::readUrl(),
                               EEPROMUtils::readApiKey(), EEPROMUtils::readEnabledRemoteControl());
}

void ConfigServer::loop() {
    server->handleClient();
}
