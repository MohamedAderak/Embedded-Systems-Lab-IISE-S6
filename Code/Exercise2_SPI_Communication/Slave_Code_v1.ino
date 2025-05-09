#include <SPI.h>

char receivedData;

void setup() {
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  if (SPSR & (1 << SPIF)) { 
    receivedData = SPDR;
    if (receivedData == 'A') {
      digitalWrite(8, !digitalRead(8));
    } 
    else if (receivedData == 'B') {
      digitalWrite(9, !digitalRead(9));
    }
  }
}
