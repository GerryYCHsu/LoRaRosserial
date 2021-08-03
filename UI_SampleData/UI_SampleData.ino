#include <ArduinoJson.h>
double x = 0.0;//unit: m
double y = 0.0;//unit: m
double a = 0.0;//unit: rad (0~6.2831853071796)
StaticJsonDocument<200> doc;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  a += 1.57075;
  if(a > 6){
    a = 0.0;
    x++;
    if(x > 100){
      x = 0.0;
      y++;
      if(y > 100){
        y = 0.0;  
      }
    }  
  }
  doc["x"] = x;
  doc["y"] = y;
  doc["a"] = a;
  serializeJson(doc, Serial);
  delay(1000);
}
