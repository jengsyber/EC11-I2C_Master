#include <Wire.h>
#include "Rotary_I2C.h"


int16_t value1, lastvalue1;

boolean pressed1, lastpressed1;

Rotary_I2C Rotary;

void setup() {
  Serial.begin(115200);
  Wire.begin();
 
                  //(min, max, step, val, loop)
  Rotary.encoder_set(0, 10, 1, 0, 0);
  //Rotary.encoder_setValue(5);   
        
}

void loop() {
  
  value1 = Rotary.encoder_getValue();


  if(value1 != lastvalue1) {
    Serial.println("#1: "+ String(value1));

    lastvalue1 = value1;


  }



  pressed1 = Rotary.encoder_isPressed();

  
  if(pressed1 != lastpressed1) {
    if(pressed1) Serial.println("Switch #1");
 
    lastpressed1 = pressed1;


  }

  
}


