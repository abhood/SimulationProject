#include "Signal/Blocks/Ramp.h"

using namespace ELCT350::Signal::Blocks;

#pragma region Constructor
Ramp::Ramp()
    : SimulationBlock(2), SignalBlock(1, 1)
{
}
#pragma endregion

#pragma region SignalBlock
void Ramp::init()
{
  SignalBlock::init();

  _gain = getParameter(InitialCondition);
}

void Ramp::step(double time, double timeStep)
{
  setOutputPortValue(Output, _gain * getInputPortValue(Input));
  _gain += timeStep * getParameter(Slope);
}
#pragma endregion