#pragma once
#include "Signal/SignalBlock.h"

namespace ELCT350
{
  namespace Signal
  {
    namespace Blocks
    {
      class SinusoidalSource final : public SignalBlock
      {
      public:
        #pragma region Enumerations
        enum Parameters
        {
          Amplitude,
          Frequency
        };

        enum OutputPorts
        {
          Output
        };
        #pragma endregion

        #pragma region Constructor
        SinusoidalSource();
        #pragma endregion

        #pragma region SignalBlock
        void step(double time, double timeStep) override;
        #pragma endregion
      private:
        #pragma region Constants
        static const double TWO_PI;
        #pragma endregion
      };
    }
  }
}