#include <Wire.h>                       //library for communication with I2C devices

void setup() {
  Wire.begin();             // join I2C bus (address optional for master)
  Serial.begin(9600);       // setting baud rate, must be same in master and slave
}

int broj = 650;             // just for example

void loop() {
  
  byte x,y,z;   
  
  // number must be seperated so we could send it as bytes           
  x=broj/100;
  y=(broj/10)%10;
  z=broj%10;
  
  Wire.beginTransmission(1);    // transmit to device #1
  Wire.write(x);                // sends one byte
  delay(100);
  Wire.write(y);
  delay(100); 
  Wire.write(z); 
  Wire.endTransmission();        // stop transmitting
  
 
  delay(500);
}
