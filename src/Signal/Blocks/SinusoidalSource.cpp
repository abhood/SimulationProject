#include "Signal/Blocks/SinusoidalSource.h"

using namespace ELCT350::Signal::Blocks;

#pragma region Constants
const double SinusoidalSource::TWO_PI = 2.0 * acos(-1.0);
#pragma endregion

#pragma region Constructor
SinusoidalSource::SinusoidalSource()
                : SimulationBlock(2), SignalBlock(0, 1)
{
}
#pragma endregion

#pragma region SignalBlock
void SinusoidalSource::step(double time, double timeStep)
{
  setOutputPortValue(Output, getParameter(Amplitude) * sin(TWO_PI * getParameter(Frequency) * time));
}
#pragma endregion