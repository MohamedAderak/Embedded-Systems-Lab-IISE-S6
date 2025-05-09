#include <SPI.h>

char receivedData;
const int led1 = 8;
const int led2 = 9;

void setup() {
  pinMode(SS, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  SPCR |= _BV(SPE);
}

void loop() {
  if (SPSR & (1 << SPIF)) {
    receivedData = SPDR;
    if (receivedData == 'C') {
      digitalWrite(led1, !digitalRead(led1));
      digitalWrite(led2, !digitalRead(led2));
    } 
    else if (receivedData == 'D') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
    SPSR &= ~(1 << SPIF);
  }
}
