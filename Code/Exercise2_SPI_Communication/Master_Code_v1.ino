#include <SPI.h>

void setup() {
  SPI.begin();  
  pinMode(10, OUTPUT); 
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(10, LOW);  
  SPI.transfer('A');  
  digitalWrite(10, HIGH);  
  delay(500);  

  digitalWrite(9, LOW);  
  SPI.transfer('B');  
  digitalWrite(9, HIGH);  
  delay(500);  
}
