#include "SimulationBlock.h"

using namespace ELCT350;
using namespace std;

#pragma region Constructors
SimulationBlock::SimulationBlock(size_t numParameters)
               : _parameters(make_unique<double[]>(numParameters))
{
}
#pragma endregion

#pragma region Modifiers
void SimulationBlock::setParameter(size_t parameterIndex, double parameter)
{
  _parameters[parameterIndex] = parameter;
}
#pragma endregion

#pragma region Observers
double SimulationBlock::getParameter(size_t parameterIndex) const
{
  return _parameters[parameterIndex];
}
#pragma endregion