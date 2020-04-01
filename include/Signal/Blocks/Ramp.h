#pragma once
#include "Signal/SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class Ramp final : public SignalBlock
      {
      public:
        #pragma region Enumerations
        enum Parameters
        {
          InitialCondition,
          Slope
        };

        enum InputPorts
        {
          Input
        };

        enum OutputPorts
        {
          Output
        };
        #pragma endregion

        #pragma region Constructor
        Ramp();
        #pragma endregion

        #pragma region SignalBlock
        void init() override;
        void step(double time, double timeStep) override;
        #pragma endregion
      private:
        #pragma region Variables
        double _gain;
        #pragma endregion
      };
    }
  }
}