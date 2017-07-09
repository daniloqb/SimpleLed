/*
 * simpleled-luminosity.ino
 * 
 * Created by Danilo Queiroz Barbosa, Jul 09, 2017.
 * Member of electronicdrops.com
 * 
 * 
 * This example shows how to use the Simple library.
 * 
 * ldr with a 4.7k
 * Using map function to set the correct value 
 * 
 * 
 *long map(long x, long in_min, long in_max, long out_min, long out_max)
 *{
 *  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 *}
 * 
 * 
 */


// class include
#include <SimpleLed.h> 


int ledPin = 9;
int ldrPin = A0;


SimpleLed led(ledPin); // LED device. The constructor receive a PWM pin number.

void setup() {
  // put your setup code here, to run once:
  
  led.begin();    // set the pinModes
  Serial.begin(9600);
}

void loop() {


 int ldrValue = analogRead(ldrPin);

 Serial.println(ldrValue);

  int bright = map(ldrValue,700,980,0,100);
  bright = constrain(bright,0,100);

Serial.println(bright);
Serial.println();
  led.brightness(bright);
  // update the lamp color.
  led.update();
    

delay(100);
}
