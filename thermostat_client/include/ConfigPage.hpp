//
// Created by vst on 5/12/18.
//

#ifndef ESP_CONFIGPAGE_HPP
#define ESP_CONFIGPAGE_HPP

#include <WString.h>

class ConfigPage {


public:
    static String getPage(String wifiName, String wifiPasswd, String url, String apiKey, bool active) {
        String page;

        page += "<h3>Config page</h3><form action='/' method='post'><table><tr><td>Wifi name:</td><td><input type='text' size='40' name='wifi_name' value='";
        page += wifiName;
        page += "'></td></tr><tr><td>Wifi password:</td><td><input type='text' size='40' name='wifi_passwd' value='";
        page += wifiPasswd;
        page += "'></td></tr><tr><td colspan='2'><hr></td></tr><tr><td>Url:</td><td><input type='text' size='40' name='url' value='";
        page += url;
        page += "'></td></tr><tr><td>ApiKey:</td><td><input type='text' size='40' name='apikey' value='";
        page += apiKey;
        page += "'></td></tr><tr><td colspan='2'><hr></td></tr><tr><td colspan='2'>To enable collect of indications and control?<input type='checkbox' name='active'";
        if (active) {
            page += "checked='checked'";
        }
        page += "'></td></tr></table><br><input type='submit' value='Save'></form>";
        return page;

    }

};


#endif //ESP_CONFIGPAGE_HPP
