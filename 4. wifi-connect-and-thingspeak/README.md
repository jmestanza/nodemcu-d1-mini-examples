# Connect to WiFi and use Thingspeak

Please create an account in MathWorks so you can use ThingSpeak for this example.

Checkout this link: https://thingspeak.com/login?skipSSOCheck=true.

After creating your account, please visit https://thingspeak.com/channels.

There you can create a `New Channel` and follow the example.

In this example we will send random numbers to a Channel in Thingspeak between 24 and 26 simulating the output of a temperature sensor.

Let's see what has been added to the code since last time.

```c
String WRITE_API_KEY = "9P1OHJPZML8GSCTZ";
String READ_API_KEY = "36J9F0G6OZ5HTJ6Y";

// WRITE CHANNEL FEED
String urlWriteChannelFeed = "https://api.thingspeak.com/update?api_key=9P1OHJPZML8GSCTZ&field1=";
// READ CHANNEL FIELD
String urlReadLastEntry = "https://api.thingspeak.com/channels/1680534/fields/1/last.json?api_key=36J9F0G6OZ5HTJ6Y";
```

The first thing we notice is ThingSpeak credentials and urls.

In this case we've set the code to write some value on the first field (field1).

`WRITE API_KEY`, `READ_API_KEY` and the urls used in the example are obtained in the `API Keys` tab of Thingspeak.

API_KEYs are needed in the url because by default the channels are private.

```c
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
      GET_REQUEST(urlWriteChannelFeed+String(float(random(24*100,26*100))/100.0));
      GET_REQUEST(urlReadLastEntry);
  }
  delay(15000);

}
```

In this piece of code we're checking if we're still connected and if so, we send a random value to the `field1` every 15 seconds.

Why 15 seconds? Because that's the minimum interval in which a request can be made with the Free License of ThingSpeak.

If all the steps went well you should see in your channel that your Field 1 Chart is being updated🥳🎉.

Also, if you go to the Serial Monitor you would be able to see the last entry on that channel.
