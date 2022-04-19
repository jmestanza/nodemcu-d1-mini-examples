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

// sin count;
int sin_count = 0;

void scan_wifi_networks(){
  Serial.println("Scanning available networks...");
  int numSsid = WiFi.scanNetworks();
    for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(String(thisNet) + ") " + WiFi.SSID(thisNet)+ "\n");
  }
}


void setup() {
// Setup serial port
  Serial.begin(115200);
  
//  scan_wifi_networks();

// Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
//
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

//    GET_REQUEST(urlReadChannelField);
      // thingSpeak period in seconds
      int thingSpeakUpdateTime = 15; 
      // points we want to see
      int points = 8;
      int T = thingSpeakUpdateTime*points;
      float fo = 1/float(T);
      float wo = 2*PI*fo;
      Serial.printf("wo");
      Serial.println(wo);
      Serial.println();
      float sin_value = sin(wo*sin_count*15);
      Serial.printf("Sin Value");
      Serial.println(sin_value);
      Serial.println();
      if(sin_count == points - 1){
        sin_count = 0;
      } else {
        sin_count++;
      }
      GET_REQUEST(urlWriteChannelFeed+String(sin_value));

  }
  delay(15000);

}
