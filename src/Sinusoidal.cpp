#include <cmath>
#include "Sinusoidal.h"

using namespace Leonard;

double sinusoidal(double time, double amplitude, double frequency, double phase, double offset)
{
  frequency *= 2 * 3.14;
  phase *= 3.14 / 180;
  return amplitude * sin(frequency * time + phase) + offset;
}

Sinusoidal::Sinusoidal(double amplitude, double frequency, double phase, double offset)
          : _amplitude(amplitude), _frequency(frequency * 2.0 * 3.14), _phase(phase * 3.14 / 180.0),
            _offset(offset)
{
}

double Sinusoidal::getValue(double time)
{
  return _amplitude * sin(_frequency * time + _phase) + _offset;
}