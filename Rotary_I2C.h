#ifndef Rotary_I2C_h
#define Rotary_I2C_h

#include <Arduino.h>
#include <Wire.h>

class	Rotary_I2C
{
public:
void	encoder_set(int16_t rmin, int16_t rmax, int16_t rstep, int16_t rval, uint8_t rloop );
void	encoder_setValue(int16_t rval);
int16_t	encoder_getValue();

bool	encoder_isPressed();


private:

};

#endif // 