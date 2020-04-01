#pragma once
#include <vector>

namespace ELCT350
{
  class SignalBlock
  {
  public:
    virtual ~SignalBlock() {};

    void setParameter(size_t parameterIndex, double parameter);
    double getParameter(size_t parameterIndex) const;

    void setPortValue(size_t portIndex, double portValue);
    double getPortValue(size_t portIndex) const;

    virtual void step(double time, double timeStep) = 0;
  protected:
    SignalBlock(size_t numParameters, size_t numPorts);
  private:
    std::vector<double> _parameters;
    std::vector<double> _ports;
  };
}