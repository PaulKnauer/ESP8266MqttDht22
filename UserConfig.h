#ifndef UserConfig_h
#define UserConfig_h

#define WLAN_SSID        "yourssid"
#define WLAN_PASSWORD    "yourwifipassword"

#define DELAY 60000


#define MQTT_CLIENT_NAME "OfficeDht22Sensor"
#define MQTT_SERVER      "192.168.2.18"
#define MQTT_SERVERPORT  1883
#define MQTT_USERNAME    ""
#define MQTT_PASSWORD    ""

#define MQTT_TEMPERATURE_PUBLISH_TOPIC "/Office/DHT22/Temperature"
#define MQTT_HUMIDITY_PUBLISH_TOPIC "/Office/DHT22/Humidity"

#endif
