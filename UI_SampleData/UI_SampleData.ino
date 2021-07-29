double x = 0.0;//unit: m
double y = 0.0;//unit: m
double a = 0.0;//unit: rad (0~6.2831853071796)
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void SerialDoubleWrite(double d) {
  byte * b = (byte *) &d;
  Serial.write(b,4);
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
  Serial.print("S");
  SerialDoubleWrite(x);
  SerialDoubleWrite(y);
  SerialDoubleWrite(a);
  Serial.print("E"); 
  delay(1000);
}
