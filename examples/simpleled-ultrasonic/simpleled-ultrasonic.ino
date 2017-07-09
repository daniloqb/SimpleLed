/*
 * simpleled-ultrasonic.ino
 * 
 * Created by Danilo Queiroz Barbosa, JUl 09, 2017.
 * Member of electronicdrops.com
 * 
 * This example shows how to use the SimpleLed library.
 * 
 * This sketch uses an ultrasonic sensor.
 * 
 * how far  something is to the lamp the color will be green
 * how closer is something to the lamp the color will vary from yellow to red
 * 
 * 
 */


// class include
#include <SimpleLed.h> 


#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     13  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.





// These are the PWM pins that  control the colors.
const int ledPin = 9;

SimpleLed led(9);

void setup() {
  // put your setup code here, to run once:
  
  led.begin();    // set the pinModes

Serial.begin(9600);
}

void loop() {


  int cm = 0;
  for (int i =0; i < 30; i++){
    int s = sonar.ping_cm();
    if (s > 0) {
      cm += s;
    }
  }
   cm /= 30;


    Serial.println(cm);

    if(cm >= 15){
      led.off();
    }
    else {
      led.on();
    }

   led.update();

   delay(100);
}
