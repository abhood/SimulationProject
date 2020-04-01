#pragma once

double sinusoidal(double time, double amplitude, double frequency, double phase, double offset);

namespace Leonard
{
  class Sinusoidal
  {
  public:
    Sinusoidal(double amplitude, double frequency, double phase, double offset);

    double getValue(double time);

    virtual int getType() { return 1; }
  private:
    double _amplitude;
    double _frequency;
    double _phase;
    double _offset;
  };

  class SinusoidalInheritance : public Sinusoidal
  {
  public:
    SinusoidalInheritance() : Sinusoidal(1, 1, 1, 1) {};

    virtual int getType() override { return 2; }
  };
}