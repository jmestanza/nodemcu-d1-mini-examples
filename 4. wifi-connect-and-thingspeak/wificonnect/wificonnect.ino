#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

#define WIFI_SSID "NAME_OF_WIFI_NETWORK"
#define WIFI_PASS "PASSWORD_OF_WIFI_NETWORK"

String WRITE_API_KEY = "9P1OHJPZML8GSCTZ";
String READ_API_KEY = "36J9F0G6OZ5HTJ6Y";


// WRITE CHANNEL Feed
String urlWriteChannelFeed = "https://api.thingspeak.com/update?api_key=9P1OHJPZML8GSCTZ&field1=";

// READ CHANNEL FIELD
String results = "2";
String urlReadChannelField = "https://api.thingspeak.com/channels/1680534/fields/1.json?api_key="+READ_API_KEY+"&results=" + results;

int sin_cnt = 0;


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
    delay(100);
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

  connect_to_wifi(WIFI_SSID, WIFI_PASS);
}

void GET_REQUEST(String url){
    WiFiClientSecure client;
    client.setInsecure();
    HTTPClient https;
    Serial.println("Requesting " + url);
    if (https.begin(client, url)) {
      int httpCode = https.GET();
      Serial.println("============== Response code: " + String(httpCode));
      if (httpCode > 0) {
        Serial.println(https.getString());
      }
      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }  
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
      int tot_points = 8;
      float sin_value = sin(2*PI*sin_cnt/tot_points);
      sin_cnt = (sin_cnt + 1)% tot_points;
      GET_REQUEST(urlWriteChannelFeed+String(sin_value));

  }
  delay(15000);

}
