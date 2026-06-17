#include <WiFi.h>

const char* ssid = "ESP_32228D";  // This is the open Wi-Fi name (no password)
WiFiServer server(8888);          // TCP server on port 8888

void setup() {
  Serial.begin(115200);
  delay(1000);  // Give Serial time to start

  WiFi.softAP(ssid);  // Create open hotspot
  Serial.println("[INFO] Access Point started");
  Serial.print("[INFO] IP address: ");
  Serial.println(WiFi.softAPIP());  // Usually 192.168.4.1

  server.begin();
  Serial.println("[INFO] TCP server started");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("[INFO] Client connected");

    while (client.connected()) {
      String data = "aX=0.1|aY=0.2|aZ=0.3|tmp=25.0|gX=1.0|gY=2.0|gZ=3.0";
      client.println(data);
      Serial.println("[SENT] " + data);
      delay(1000);
    }

    client.stop();
    Serial.println("[INFO] Client disconnected");
  }
}