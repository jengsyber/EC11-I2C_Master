#include <Wire.h>
#include "Rotary_I2C.h"


int16_t value1, lastvalue1;
int16_t value2, lastvalue2;
int16_t value3, lastvalue3;
int16_t value4, lastvalue4;

boolean pressed1, lastpressed1;
boolean pressed2, lastpressed2;
boolean pressed3, lastpressed3;
boolean pressed4, lastpressed4;

Rotary_I2C Rotary;


// Select I2C BUS
void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
 // Serial.print(bus);
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
 
   TCA9548A(0);
  Rotary.encoder_set(0, 10, 1, 0, 1);
   TCA9548A(1);
  Rotary.encoder_set(0, 20, 1, 0, 0);
   TCA9548A(2);  
  Rotary.encoder_set(0, 50, 1, 0, 0);
   TCA9548A(3);  
  Rotary.encoder_set(0, 100, 1, 0, 0);
   
  // TCA9548A(2);
  //Rotary.encoder_setValue(50);

        
}

void loop() {
  
   TCA9548A(0);
    value1 = Rotary.encoder_getValue();
   TCA9548A(1);
    value2 = Rotary.encoder_getValue();
   TCA9548A(2);
    value3 = Rotary.encoder_getValue();
   TCA9548A(3);
    value4 = Rotary.encoder_getValue();

  if((value1 != lastvalue1) || (value2 != lastvalue2) || (value3 != lastvalue3) || (value4 != lastvalue4)) {
    Serial.print("#1: "+ String(value1));
    Serial.print(", #2: "+ String(value2));
    Serial.print(", #3: "+ String(value3));
    Serial.println(", #4: "+ String(value4));
    lastvalue1 = value1;
    lastvalue2 = value2;
    lastvalue3 = value3;
    lastvalue4 = value4;
  }


  TCA9548A(0);
    pressed1 = Rotary.encoder_isPressed();
  TCA9548A(1);
    pressed2 = Rotary.encoder_isPressed();
  TCA9548A(2);
    pressed3 = Rotary.encoder_isPressed();
  TCA9548A(3);
    pressed4 = Rotary.encoder_isPressed();

  
  if((pressed1 != lastpressed1) || (pressed2 != lastpressed2)|| (pressed3 != lastpressed3)|| (pressed4 != lastpressed4)) {
    if(pressed1) Serial.println("Switch #1");
    if(pressed2) Serial.println("Switch #2");
    if(pressed3) Serial.println("Switch #3");
    if(pressed4) Serial.println("Switch #4");

    lastpressed1 = pressed1;
    lastpressed2 = pressed2;
    lastpressed3 = pressed3;
    lastpressed4 = pressed4;


  }

  
}


