#include <SimpleLed.h>



SimpleLed led(9);

void setup() {
  // put your setup code here, to run once:
  led.begin();
  led.fade(1);
  led.fade_speed(30);
  

  
 
}

void loop() {
  // put your main code here, to run repeatedly:

led.update();

  

}
