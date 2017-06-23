#ifndef SIMPLELED_H
#define SIMPLELED_H

#endif

#include "Arduino.h"

/*
 * SimpleLed -
 *
 * This device controls a Simple Led Lamp for mutiple purposes.
 *

 *  The available functions are:
 *  - on;
 *  - off;
 *  - blink;
 *  - choose brightness: 0 - 100.  0 - led off
 *

 *  - fade effect
 *  - it is possible to chance the fade speed from  0 to 10000
 *
 *  This device controls 1 PWM port
 *
*/

  const int MIN_FADE_SPEED = 0;
  const int MAX_FADE_SPEED = 10000;
  const int DEFAULT_FADE_SPEED = 200;

  const int DEFAULT_BRIGHTNESS = 100;



class SimpleLed{

  private:

    int _brightness;
    int _last_brightness;

    byte _fade_state;
    byte _fade_speed;
    long _fade_time;
    int _fade_offset;
    int _fade_min;


    byte _pin_led;
    int  _val_led;

    void led_fade();

  public:
    SimpleLed(byte pin_led);
    void begin();

    int brightness();
    int brightness(int brightness_);
    int last_brightness();
    int last_brightness(int brightness_);
    boolean fade();
    boolean fade(int state);
    int fade_speed();
    int fade_speed(int speed);

    void on();
    void off();
    void update();

};
