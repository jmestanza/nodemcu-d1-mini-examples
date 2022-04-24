#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

#define WIFI_SSID "NAME_OF_WIFI_NETWORK"
#define WIFI_PASS "PASSWORD_OF_WIFI_NETWORK"

void scan_wifi_networks(){
  Serial.println("Scanning available networks...");
  int numSsid = WiFi.scanNetworks();
    for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(String(thisNet) + ") " + WiFi.SSID(thisNet)+ "\n");
  }
}

void connect_to_wifi(String WifiSsid, String WifiPass){

// Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
// Connecting to WiFi...
  Serial.print("Connecting to " + String(WIFI_SSID) + "\n");

// Loop continuously while WiFi is not connected
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(5000);
    Serial.print(".");
  }
  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.print(WiFi.localIP());
  Serial.println();
}


void setup() {
// Setup serial port
  Serial.begin(115200);

  scan_wifi_networks();

// Uncomment this line once you know you've checked that WIFI_SSID appears on the look up
//  connect_to_wifi(WIFI_SSID, WIFI_PASS);

}

void loop() {
}
