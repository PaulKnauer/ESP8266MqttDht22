#include "UserConfig.h"
#include "MqttClient.h"
#include "Dht22.h"

MqttClient *client;
Dht22 *dht22;

const int pinDHT22 = 2;

void setup() {
  client = new MqttClient();
  client->connect();
  dht22 = new Dht22();
}

void loop() {
  client->loop();
  dht22->read();
  client->publishTemperature(dht22->getTemperature());
  client->publishHumididty(dht22->getHumidity());
  delay(DELAY);
}
