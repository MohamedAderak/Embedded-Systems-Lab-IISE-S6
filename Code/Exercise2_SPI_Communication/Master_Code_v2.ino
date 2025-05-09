#include <SPI.h> 

void setup() { 
  SPI.begin(); 
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
} 

void loop() { 
  int potValue = analogRead(A0); 
  float voltage = potValue * (5.0 / 1023); 

  if (voltage > 3.0) { 
    digitalWrite(10, LOW); 
    SPI.transfer('C');
    digitalWrite(10, HIGH); 
  } else { 
    digitalWrite(10, LOW); 
    SPI.transfer('D');
    digitalWrite(10, HIGH); 
  } 
  delay(200); 
} 
