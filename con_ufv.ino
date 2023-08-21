#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

#define EAP_ANONYMOUS_IDENTITY ""
#define EAP_IDENTITY "CPF"
#define EAP_PASSWORD "SENHA DO SAPIENS"
#define SSID "WIFI-UFV2"


const char* testURL = "https://www.google.com/";


void setup() {
  Serial.begin(115200);

  WiFi.begin(SSID, WPA2_AUTH_PEAP, EAP_ANONYMOUS_IDENTITY, EAP_IDENTITY, EAP_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando-se à rede Wi-Fi...");
  }
  Serial.println("Conectado à rede Wi-Fi!");
}

void loop() {
  HTTPClient https;
  WiFiClientSecure client;
  client.setInsecure();
  
  if (https.begin(client, testURL)) {
    if (https.GET() > 0) {
      String data = https.getString();
      Serial.println(data);
    }
    else{
      Serial.println('Error');
    }

    https.end();
  }

  delay(10000);
}
