#include "MqttClient.h"

#include "Arduino.h"

MqttClient::MqttClient() {
  setUpWiFi();
  espClient = WiFiClient();
  client = PubSubClient(espClient);
  client.setServer(MQTT_SERVER, MQTT_SERVERPORT);
}

void MqttClient::connect() {
  while (!client.connected()) {
    if (!client.connect(MQTT_CLIENT_NAME, MQTT_USERNAME, MQTT_PASSWORD)) {
      delay(5000);
    }
  }
}

void MqttClient::loop() {
  if (!client.connected()) {
    this->connect();
  }
  client.loop();
}

void MqttClient::publishTemperature(float temperature) {
  char *temp = new char[4];
  dtostrf(temperature, 0, 1, temp);
  client.publish(MQTT_TEMPERATURE_PUBLISH_TOPIC, temp);
}

void MqttClient::publishHumididty(float humididty) {
  char *hum = new char[4];
  dtostrf(humididty, 0, 1, hum);
  client.publish(MQTT_HUMIDITY_PUBLISH_TOPIC, hum);
}

void MqttClient::setUpWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
