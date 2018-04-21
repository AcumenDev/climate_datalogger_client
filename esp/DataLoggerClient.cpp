#include "DataLoggerClient.hpp"


bool DataLoggerClient::auth(int type, int version) {
    Serial.println("Send auth ");
    Serial.print("type= ");
    Serial.println(type);
    Serial.print("version= ");
    Serial.println(version);
    /*  Serial.print("apiKey= ");
      Serial.print(apiKey);*/


    Auth auth = Auth_init_default;
    auth.type = type;
    auth.has_type = true;
    auth.version = version;
    auth.has_version = true;
    auth.apiKey.funcs.encode = encodeApiKey;

    BaseMessage baseMessage = BaseMessage_init_default;

    baseMessage.auth = auth;
    baseMessage.has_auth = true;

    return send(&baseMessage);
}

bool DataLoggerClient::connectWifi() {

    WiFi.begin(ESP_SSID, ESP_PASS);

    Serial.print("Connecting to wifi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

bool DataLoggerClient::connectServer() {
    Serial.printf("\n[Connecting to %s ... ", HOST);
    if (tcpClient.connect(HOST, PORT)) {
        Serial.println("connected]");
        return true;
    }
    return false;
}

bool DataLoggerClient::send(BaseMessage *baseMessage) {
    // Serial.println("[Sending a request]");

    uint8_t buffer[100];
    bool status;

    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

    status = pb_encode(&stream, BaseMessage_fields, baseMessage);
    if (!status) {
        printf("Encoding baseMessage failed: %s\n", PB_GET_ERROR(&stream));
        return false;
    }

    // size_t message_length = stream.bytes_written;

    /* uint8_t bufferSizePacket[10];
     pb_ostream_t streamSizePacket = pb_ostream_from_buffer(bufferSizePacket, sizeof(bufferSizePacket));

     status = pb_encode_varint(&streamSizePacket, stream.bytes_written);
     if (!status) {
         printf("Encoding size failed: %s\n", PB_GET_ERROR(&stream));
         return false;
     }*/

    Serial.print("[Sending a request size]");
    Serial.println(stream.bytes_written);//+ streamSizePacket.bytes_written);

    // printBytes(bufferSizePacket, streamSizePacket.bytes_written);
    printBytes(buffer, stream.bytes_written);
    Serial.println();

    // tcpClient.write((const uint8_t *) bufferSizePacket, streamSizePacket.bytes_written);
    tcpClient.write((const uint8_t *) buffer, stream.bytes_written);

    Serial.println("[Send]");

    return true;
}

bool DataLoggerClient::encodeApiKey(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    const char str[] = "53ae8ff6-3d8c-11e8-b467-0ed5f89f718b";
    Serial.print("apiKey= ");
    Serial.print(str);
    if (!pb_encode_tag_for_field(stream, field))
        return false;

    return pb_encode_string(stream, (uint8_t *) str, strlen(str));
}


void DataLoggerClient::printBytes(const uint8_t *buffer, size_t bufferSize) {
    for (uint32_t i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i], HEX);
        Serial.print(' ');
    }
}

bool DataLoggerClient::send(Temperature *message) {
    BaseMessage baseMessage = BaseMessage_init_default;

    baseMessage.temperature = *message;
    baseMessage.has_temperature = true;
    return send(&baseMessage);
}

bool DataLoggerClient::connect() {


    Serial.println("Check wifi");
    if (WiFi.status() != WL_CONNECTED) {
        _auth = false;
        if (!connectWifi()) {
            return false;
        }
    }

    Serial.println("Check connect");
    if (tcpClient.status() == 0) {
        _auth = false;
        if (!connectServer()) {
            return false;
        }

    }

    Serial.println("Check auth");
    if (!_auth) {
        if (auth(1, 1)) {
            /////todo ждем ответа
            uint8_t buf[100];
            Serial.println("Read response auth");
            int countSteps = 0; //// timeOut 10*100 = 2 sec
            while (countSteps < 20) {
                while (tcpClient.available()) {
                    int count = tcpClient.peekBytes(buf, 100);
                    Serial.print("Recv bytes ");
                    Serial.println(count);
                    pb_istream_t stream = pb_istream_from_buffer(buf, count);
                    BaseMessage baseMessage = BaseMessage_init_default;
                    bool pb_decode(pb_istream_t *stream, const pb_field_t fields[], void *dest_struct);
                    if (pb_decode(&stream, BaseMessage_fields, &baseMessage)) {
                        tcpClient.read(buf, count);///clean buffer socket

                        Serial.println("Read BaseMessage_fields");
                        Serial.print("has_auth ");
                        Serial.println(baseMessage.has_auth);
                        if (baseMessage.has_auth) {
                            Serial.print("auth.has_state ");
                            Serial.println(baseMessage.auth.has_state);
                            if (baseMessage.auth.has_state) {
                                Serial.print("auth.state ");
                                Serial.println(baseMessage.auth.state);
                                if (baseMessage.auth.state == 0) {
                                    _auth = true;
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }

                delay(100);
                countSteps++;
                Serial.print("wait ");
                Serial.print(countSteps * 100);
                Serial.println("ms");
            }
        }
    }


    return true;
}
