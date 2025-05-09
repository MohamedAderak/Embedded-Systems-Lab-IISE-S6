#include <SPI.h>
volatile char receivedData;

void setup() {
  pinMode(10, INPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {

}

ISR(SPI_STC_vect) {  
  receivedData = SPDR;  
  if (receivedData == 'C') {  
    digitalWrite(8, !digitalRead(8));  
    digitalWrite(9, !digitalRead(9));  
  } else if (receivedData == 'D') {  
    digitalWrite(8, LOW);  
    digitalWrite(9, LOW);  
  }  
}  
