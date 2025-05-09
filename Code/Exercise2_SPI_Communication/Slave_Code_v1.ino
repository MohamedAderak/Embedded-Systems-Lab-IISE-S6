#include <SPI.h>
volatile char receivedData;

void setup() {
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

ISR(SPI_STC_vect) {
  receivedData = SPDR;

  if(receivedData == 'A') {
    digitalWrite(8, !digitalRead(8));
  }
  else if(receivedData == 'B') {
    digitalWrite(9, !digitalRead(9));
  }
}

void loop() {}
