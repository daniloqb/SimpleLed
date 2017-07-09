#include "Arduino.h"
#include "SimpleLed.h"



SimpleLed::SimpleLed(byte pin_led){

  _pin_led    = pin_led;
  _brightness = SL_DEFAULT_BRIGHTNESS;
  _last_brightness = _brightness;
}


void SimpleLed::begin(){

  pinMode(_pin_led,  OUTPUT);
  analogWrite(_pin_led,  0);

  _fade_time = 0;
  _fade_offset = 0;
  _fade_min = 10;

  _val_led = 0;


  fade(0);
  fade_speed(SL_DEFAULT_FADE_SPEED);
}


int SimpleLed::brightness(){
  return _brightness;
}

int SimpleLed::brightness(int brightness){

  if ((brightness < 0) || (brightness > 100)){
    return -1;
  }
  _brightness = brightness;

  _val_led = _brightness;
  _val_led = map(_val_led,0,100,0,255);

  #if defined(PWMRANGE)
    _val_led =   map(_val_led,  0,255,0,PWMRANGE);
  #endif

 analogWrite(_pin_led,_val_led);



  return _brightness;
}

int SimpleLed::last_brightness(){
  return _last_brightness;
}

int SimpleLed::last_brightness(int brightness){

  _last_brightness = brightness;
  return _last_brightness;
}


boolean SimpleLed::fade(){
  return _fade_state;
}

boolean SimpleLed::fade(int state){

  if((state < 0) || (state > 1)){
    return false;
  }

  _fade_state = state;
  return true;
}



int SimpleLed::fade_speed(int speed){

  if((speed < SL_MIN_FADE_SPEED) || (speed > SL_MAX_FADE_SPEED)){
    return -1;
  }

  _fade_speed = speed;
  return _fade_speed;
}

int SimpleLed::fade_speed(){
  return _fade_speed;
}



void SimpleLed::update(){

  if(fade() == 1){
    led_fade();
  }

  Serial.print("Val: ");
  Serial.println(_val_led);
}




void SimpleLed::led_fade() {

 int brightness_;

if (millis() - _fade_time > (unsigned long)fade_speed()) {



 brightness_ = -abs(_fade_offset-100)+100;

  if(brightness_ < _fade_min){
   brightness_ = _fade_min;
   _fade_offset = 100 - abs(brightness_ - 100);
 }

 brightness(brightness_);
 _fade_time = millis();
 _fade_offset++;
 _fade_offset %= 200;

}

}


void SimpleLed::on(){
 fade(0);
 if(_last_brightness > 0)
   brightness(_last_brightness);
else
   brightness(SL_DEFAULT_BRIGHTNESS);
}

void SimpleLed::off(){
  fade(0);
  brightness(0);
}
