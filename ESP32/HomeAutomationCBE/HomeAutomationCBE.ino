#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>

#include "secrets.h"

#define AWS_THING_NAME "esp32"
#define AWS_IOT_PUBLISH_TOPIC   "esp32/publish"
#define AWS_IOT_SUBSCRIBE_TOPIC "MyTopic"

// https://snjqtga625.execute-api.ap-south-1.amazonaws.com/loading/iot?ID=1&item=Light 

const size_t bufferSize = JSON_OBJECT_SIZE(2) + 22;
DynamicJsonBuffer jsonBuffer(bufferSize);

WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(512);

// the setup function runs once when you power the board or press reset
void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  Serial.begin(115200);
  connectWiFi();
  connectAWS();

  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

  // Create a message handler
  client.onMessage(messageHandler);
}

void messageHandler(String &topic, String &payload) {
  Serial.println("Receiving MQTT message:");
  Serial.println(topic + " " + payload);
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(payload);
  String relayStatus = root["status"];
  String Item = root["item"];
  if(relayStatus == "1" && Item == "Fan"){
    digitalWrite(2, LOW);
  }
  else if(relayStatus == "0" && Item == "Fan"){
    digitalWrite(2, HIGH);
  }
  else if(relayStatus == "1" && Item == "Light"){
    digitalWrite(4, LOW);
  }
  else if(relayStatus == "0" && Item == "Light"){
    digitalWrite(4, HIGH);
  }
  else{
    Serial.println("Wrong_JSON");
  }
}

// the loop function runs over and over again forever
void loop() {
  // Sends and receives packets
  client.loop();
  
  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
  // Create a message handler
  client.onMessage(messageHandler);

  // Publish to a topic
  //client.publish(AWS_IOT_PUBLISH_TOPIC, "{\"message\": \"Hello from ESP32!\"}");
}
