#include <WiFi.h>
#include <Wire.h>

// Wi-Fi AP Settings
const char* ssid = "ESP_32228D";
WiFiServer server(8888);

// I2C Address of MPU6500 (same as MPU6050)
const uint8_t MPU_ADDR = 0x68;

void setup() {
  Serial.begin(115200);

  // Start I2C
  Wire.begin(21, 22);
  delay(100);

  // Wake up MPU (clear sleep bit)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);  // PWR_MGMT_1
  Wire.write(0x00);  // Set to zero (wakes up MPU)
  Wire.endTransmission();

  // Wi-Fi Access Point
  WiFi.softAP(ssid);
  Serial.println("[INFO] Access Point started.");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
  Serial.println("[INFO] TCP server started on port 8888.");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("[INFO] Client connected.");

    while (client.connected()) {
      int16_t aX, aY, aZ, gX, gY, gZ;
      readMPU(aX, aY, aZ, gX, gY, gZ);

      String data = "aX=" + String(aX) +
                    "|aY=" + String(aY) +
                    "|aZ=" + String(aZ) +
                    "|gX=" + String(gX) +
                    "|gY=" + String(gY) +
                    "|gZ=" + String(gZ);

      client.println(data);
      Serial.println(data);
      delay(500);
    }

    client.stop();
    Serial.println("[INFO] Client disconnected.");
  }
}

void readMPU(int16_t &aX, int16_t &aY, int16_t &aZ,
             int16_t &gX, int16_t &gY, int16_t &gZ) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);  // Start at ACCEL_XOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14);

  aX = (Wire.read() << 8) | Wire.read();
  aY = (Wire.read() << 8) | Wire.read();
  aZ = (Wire.read() << 8) | Wire.read();
  Wire.read(); Wire.read();  // Skip temperature
  gX = (Wire.read() << 8) | Wire.read();
  gY = (Wire.read() << 8) | Wire.read();
  gZ = (Wire.read() << 8) | Wire.read();
}
