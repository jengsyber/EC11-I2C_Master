
#include "Rotary_I2C.h"
#include <Wire.h>

int16_t addresss = 0x51;

// Set encoder wheel parameters
void Rotary_I2C::encoder_set(int16_t rmin, int16_t rmax, int16_t rstep, int16_t rval, uint8_t rloop) {
  Wire.beginTransmission(addresss);
  Wire.write((uint8_t)(rval & 0xff)); Wire.write((uint8_t)(rval >> 8));
  Wire.write(0); Wire.write(rloop);
  Wire.write((uint8_t)(rmin & 0xff)); Wire.write((uint8_t)(rmin >> 8));
  Wire.write((uint8_t)(rmax & 0xff)); Wire.write((uint8_t)(rmax >> 8));
  Wire.write((uint8_t)(rstep & 0xff)); Wire.write((uint8_t)(rstep >> 8));
  Wire.endTransmission();
}

// Set encoder wheel value
void Rotary_I2C::encoder_setValue(int16_t rval) {
  Wire.beginTransmission(addresss);
  Wire.write((uint8_t)(rval & 0xff)); Wire.write((uint8_t)(rval >> 8));
  Wire.endTransmission();
}

// Read encoder wheel value
int16_t Rotary_I2C::encoder_getValue() {
  Wire.requestFrom(addresss, 2);
  return((uint16_t)Wire.read() | ((uint16_t)Wire.read() << 8));
}

// Read encoder switch state
bool Rotary_I2C::encoder_isPressed() {
  Wire.requestFrom(addresss, 3);
  Wire.read(); Wire.read();
  return(Wire.read());
}
