#pragma once

#include "SimulationBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    class SignalBlock : public virtual SimulationBlock
    {
    public:
      #pragma region Modifiers
      void setInputPortValue(size_t portIndex, double portValue);
      #pragma endregion

      #pragma region Observers
      double getOutputPortValue(size_t portIndex) const;
      #pragma endregion

      #pragma region SimulationBlock
      virtual void init() override;
      #pragma endregion
    protected:
      #pragma region Constructors
      SignalBlock(size_t numInputPorts, size_t numOutputPorts);
      #pragma endregion

      #pragma region Modifiers
      void setOutputPortValue(size_t portIndex, double portValue);
      #pragma endregion

      #pragma region Observers
      double getInputPortValue(size_t portIndex) const;
      #pragma endregion
    private:
      #pragma region Variables
      size_t _numInputPorts;
      size_t _numOutputPorts;
      std::unique_ptr<double[]> _inputPorts;
      std::unique_ptr<double[]> _outputPorts;
      #pragma endregion

      #pragma region Modifiers
      void zeroPortValues(std::unique_ptr<double[]>& portArray, size_t arraySize);
      #pragma endregion
    };
  }
}