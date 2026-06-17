#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>

const char* ssid = "ESP_32228D";
WiFiServer server(8888);
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.softAP(ssid);
  Serial.println("[INFO] AP Started");
  Serial.print("[INFO] IP: ");
  Serial.println(WiFi.softAPIP());
  server.begin();

  // Initialize MPU
  if (!mpu.begin()) {
    Serial.println("[ERROR] MPU6050 not found!");
    while (1);
  }
  Serial.println("[INFO] MPU6050 ready");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("[INFO] Client connected");

    while (client.connected()) {
      sensors_event_t a, g, temp;
      mpu.getEvent(&a, &g, &temp);

      String data = "aX=" + String(a.acceleration.x) +
                    "|aY=" + String(a.acceleration.y) +
                    "|aZ=" + String(a.acceleration.z) +
                    "|tmp=" + String(temp.temperature) +
                    "|gX=" + String(g.gyro.x) +
                    "|gY=" + String(g.gyro.y) +
                    "|gZ=" + String(g.gyro.z);

      client.println(data);
      Serial.println("[SENT] " + data);
      delay(1000);
    }

    client.stop();
    Serial.println("[INFO] Client disconnected");
  }
}
