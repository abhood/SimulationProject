#include "Signal/SignalBlock.h"

using namespace ELCT350::Signal;
using namespace std;

#pragma region Constructors
SignalBlock::SignalBlock(size_t numInputPorts, size_t numOutputPorts)
           : _numInputPorts(numInputPorts), _numOutputPorts(numOutputPorts),
             _inputPorts(make_unique<double[]>(_numInputPorts)),
             _outputPorts(make_unique<double[]>(_numOutputPorts))
{
}
#pragma endregion

#pragma region Modifiers
void SignalBlock::setInputPortValue(size_t inputPortIndex, double value)
{
  _inputPorts[inputPortIndex] = value;
}

void SignalBlock::setOutputPortValue(size_t outputPortIndex, double value)
{
  _outputPorts[outputPortIndex] = value;
}

void SignalBlock::zeroPortValues(unique_ptr<double[]>& portArray, size_t arraySize)
{
  for (size_t i = 0; i < arraySize; ++i)
    portArray[i] = 0.0;
}
#pragma endregion

#pragma region Observers
double SignalBlock::getInputPortValue(size_t inputPortIndex) const
{
  return _inputPorts[inputPortIndex];
}

double SignalBlock::getOutputPortValue(size_t outputPortIndex) const
{
  return _outputPorts[outputPortIndex];
}
#pragma endregion

#pragma region SimulationBlock
void SignalBlock::init()
{
  zeroPortValues(_inputPorts, _numInputPorts);
  zeroPortValues(_outputPorts, _numOutputPorts);
}
#pragma endregion