#pragma once
#include <memory>

namespace ELCT350
{
  class SimulationBlock
  {
  public:
    #pragma region Destructor
    virtual ~SimulationBlock() {};
    #pragma endregion

    #pragma region Modifiers
    void setParameter(size_t parameterIndex, double parameter);
    virtual void init() = 0;
    virtual void step(double time, double timeStep) = 0;
    #pragma endregion

    #pragma region Observers
    double getParameter(size_t parameterIndex) const;
    #pragma endregion
  protected:
    #pragma region Constructor
    SimulationBlock(size_t numParameters);
    #pragma endregion
  private:
    #pragma region Variables
    std::unique_ptr<double[]> _parameters;
    #pragma endregion
  };
}