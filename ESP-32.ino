#include <WiFi.h>
#include <HTTPClient.h>

const int BUTTON_PIN = 27;

const char* WIFI_SSID = "WIFI_NAME";
const char* WIFI_PASSWORD = "WIFI_PASSWORD";

const char* SECRET = "SECRET_HERE";

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi connected!");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  static bool lastState = HIGH;
  bool state = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && state == LOW) {
    Serial.println("BUTTON PRESSED");

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;

      String url = "http://PC_IP:5000/shutdown?token=";
      url += SECRET;

      http.begin(url);

      int responseCode = http.GET();

      Serial.print("HTTP response: ");
      Serial.println(responseCode);

      http.end();
    }
  }

  lastState = state;
  delay(20);
}
