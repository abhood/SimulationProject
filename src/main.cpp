#include "Signal/Blocks/Ramp.h"
#include "Signal/Blocks/SinusoidalSource.h"
#include <fstream>

using namespace ELCT350;
using namespace ELCT350::Signal::Blocks;
using namespace std;

const double STOP_TIME = 5.0;
const double TIME_STEP = 0.01;

int main()
{
  //Create blocks and set parameters
  SinusoidalSource source;
  source.setParameter(SinusoidalSource::Amplitude, 1.0);
  source.setParameter(SinusoidalSource::Frequency, 3.0);

  Ramp ramp;
  ramp.setParameter(Ramp::InitialCondition, 2.0);
  ramp.setParameter(Ramp::Slope, 0.5);

  //Initialize before simulation
  source.init();
  ramp.init();

  ofstream output("output.csv");
  output << "time,ramp" << endl;
  for (double time = 0.0; time < STOP_TIME; time+= TIME_STEP)
  {
    source.step(time, TIME_STEP);
    ramp.setInputPortValue(Ramp::Input, source.getOutputPortValue(SinusoidalSource::Output));
    ramp.step(time, TIME_STEP);

    output << time << ',' << ramp.getOutputPortValue(SinusoidalSource::Output) << endl;
  }
  return 0;
}
