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

   // disable all of the unused peripherals. This will reduce the power consumption further 
   // some of these might generate interrupts that will wake our arduino from sleep.

   // This won't compile for ATmega16A - since PRR0 is not defined.
   // will work Arduino Uno or atmega328P
   /*
   power_adc_disable();
   power_spi_disable();
   power_timer0_disable();
   power_timer2_disable();
   power_twi_disable();
   */

   power_all_disable(); //disable all modules

   sleep_mode(); // --> gonna sleep

   // waking up - The program continues from here after waking up
   sleep_disable();
   //re-enable the peripherals
   power_all_enable();

   detachInterrupt(0);
}
