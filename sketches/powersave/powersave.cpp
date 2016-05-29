#include <Arduino.h>
#include <avr/power.h>
#include <avr/sleep.h>

const int8_t buttonPin = 10; // PD2 - INT0
const int8_t ledPin = 0; //PB0 - Led pin

void pinInterrupt()
{
  // detachInterrupt(0);
}

void setup()
{
   pinMode(buttonPin, INPUT_PULLUP);
   pinMode(ledPin, OUTPUT);
   attachInterrupt(0, pinInterrupt, LOW);
}

void loop()
{
   digitalWrite(ledPin, HIGH);
   delay(1000);
   digitalWrite(ledPin, LOW);

   // INT0 -> PD2
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);
   sleep_enable();
   attachInterrupt(0, pinInterrupt, LOW);
   sleep_mode(); // --> gonna sleep

   // waking up - The program continues from here after waking up
   sleep_disable();
   detachInterrupt(0);
}
