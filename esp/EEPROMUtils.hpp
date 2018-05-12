//
// Created by vst on 5/12/18.
//

#ifndef ESP_EEPROMUTILS_HPP
#define ESP_EEPROMUTILS_HPP

#include <EEPROM.h>

class EEPROMUtils {

    static const int EEPROM_SIZE = 256;

    static const int EEPROM_ADR_ENABLED_REMOTE_CONTROL = 0;

    static const int EEPROM_ADR_WIFI_NAME = 1;
    static const int EEPROM_MAX_LENGTH_WIFI_NAME = 32;

    static const int EEPROM_ADR_WIFI_PASWD = 33;
    static const int EEPROM_MAX_LENGTH_WIFI_PASWD = 63;

    static const int EEPROM_ADR_URL = 96;
    static const int EEPROM_MAX_LENGTH_URL = 40;

    static const int EEPROM_ADR_API_KEY = 136;
    static const int EEPROM_MAX_LENGTH_API_KEY = 36;

public:
    static void begin() {
        EEPROM.begin(EEPROM_SIZE);
    }

    static void commit() {
        EEPROM.commit();
    }

    static void writeEnabledRemoteControl(bool val) {
        EEPROM.write(EEPROM_ADR_ENABLED_REMOTE_CONTROL, (byte) val);
    }

    static bool readEnabledRemoteControl() {
        return EEPROM.read(EEPROM_ADR_ENABLED_REMOTE_CONTROL);
    }

    static void writeWifiName(const char *name, int size) {
        writeString(name, size, EEPROM_ADR_WIFI_NAME, EEPROM_MAX_LENGTH_WIFI_NAME);
    }

    static String readWifiName() {
        return readString(EEPROM_ADR_WIFI_NAME, EEPROM_MAX_LENGTH_WIFI_NAME);
    }


    static void writeWifiPasswd(const char *str, int size) {
        writeString(str, size, EEPROM_ADR_WIFI_PASWD, EEPROM_MAX_LENGTH_WIFI_PASWD);
    }

    static String readWifiPasswd() {
        return readString(EEPROM_ADR_WIFI_PASWD, EEPROM_MAX_LENGTH_WIFI_PASWD);
    }


    static void writeUrl(const char *str, int size) {
        writeString(str, size, EEPROM_ADR_URL, EEPROM_MAX_LENGTH_URL);
    }

    static String readUrl() {
        return readString(EEPROM_ADR_URL, EEPROM_MAX_LENGTH_URL);
    }


    static void writeApiKey(const char *str, int size) {
        writeString(str, size, EEPROM_ADR_API_KEY, EEPROM_MAX_LENGTH_API_KEY);
    }

    static String readApiKey() {
        return readString(EEPROM_ADR_API_KEY, EEPROM_MAX_LENGTH_API_KEY);
    }

private:

    static String readString(int adr, int maxSize) {
        String name;
        for (int i = adr; i < adr + maxSize; i++) {
            char item = EEPROM.read(i);
            if (item == '\0') {
                break;
            }
            name.concat(item);
        }
        return name;
    }

    static void writeString(const char *str, int size, int adr, int maxSize) {
        if (size > maxSize) {
            return;
        }

        int i = 0;
        for (; i < size; i++) {
            EEPROM.write(adr + i, str[i]);
        }

        if (i < maxSize) {
            EEPROM.write(adr + size, '\0');
        }
    }


};

#endif //ESP_EEPROMUTILS_HPP
