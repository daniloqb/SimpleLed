/*
 * simpleled-fade.ino
 * 
 * Created by Danilo Queiroz Barbosa, Jul 09, 2017.
 * Member of electronicdrops.com
 * 
 * This example shows how to use the SimpleLed library.
 * 
 * In this sketch the fade function is set.
 * 
 * 
 */


// class include
#include <SimpleLed.h> 

const int ledPin = 9;



SimpleLed led(ledPin); // LED device. The constructor receive a PWM pin number.
 
void setup() {
  // put your setup code here, to run once:
  
  led.begin();    // set the pinModes

  
  led.fade(1);   // activate the fade function
  led.fade_speed(60); // it's possible to set the fade color.
}

void loop() {

  // update the lamp color.
  led.update();
    

}
