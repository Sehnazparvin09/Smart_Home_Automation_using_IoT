#define BLYNK_TEMPLATE_ID "TMPL3SWRrH0Ko"
#define BLYNK_TEMPLATE_NAME "HOME AUTOMATION"
#define BLYNK_AUTH_TOKEN "EhT-XIQHtRaPMUp8UZrvP-dXBpZe5LMG"

#define  BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char  auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "YOUR_WIFI";
char pass[]  = "YOUR_WIFI_PASSWORD";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D0, HIGH);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D0,  LOW);
     Serial.println("LED OFF");
  }
}


BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D1, HIGH);
    Serial.println("FAN ON");
  }
  if(value == 0)
  {
     digitalWrite(D1,  LOW);
     Serial.println("FAN OFF");
  }
}



void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  
}

void loop()
{
  Blynk.run();
}