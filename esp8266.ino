#include <SoftwareSerial.h>
#include <ESP8266wifi.h>

WiFiClient client;
const char *host = "";
const int tcpPort = 000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();

  WiFi.begin("", "");// wifi network name and passwork
  Serial.print("Connecting";
  
  while(Wifi.status()!=WL_CONNECTED))
  {
    delay(500);
    Serial.print(".");
    }
    Serial.println();

   Serial.print("Connected, IP address: ");
   Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

    while(!client.connected()) // not connectd to the server
    { 
      if(!client.connect(host, tcpPort))
      {
        Serial.print("Connecting to server...");
        delay(500);
        }
      }

     while(client.available())
     {
      char val = client.read();
      Serial.println(val);
      }
}
