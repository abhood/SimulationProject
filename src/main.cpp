#include <iostream> //places contents of iostream header here (includes definitions of classes and functions which
                    //we'll use to interface with the screen. Here, io stands for input/output)
#include <fstream> //file i/o streams
#include "Sinusoidal.h"

using namespace std; //indicates that we will be using types declared under the std (standard) namespace.
                     //Namespaces are used to avoid name collisions. Think of them like lastnames. Two people can be
                     //called John, and you differentiate them by their lastname. Two types can have the same name if
                     //are in separate namespaces.

using namespace Leonard;

/**
 * The entry point function is the function that is automatically called when the executable is run. In C++ its
 * signature is such that it returns an integer, and takes in an integer and an array of strings as arguments.
 * These are the command-line arguments invoked when running the program.
 * 
 * @param[in] argc the number of command-line arguments (will be at least 1)
 * @param[in] argv an array containing the command-line arguments (the 0th value in the array will always be the
 * program name
 *
 * @return the error code (if the program exited cleanly, it should return 0. Otherwise, return an integer
 * corresponding to the error that occurred.
 **/

void foo(Sinusoidal& sin1, SinusoidalInheritance& sin2)
{
  cout << "SinClassType: " << sin1.getType() << endl;
  cout << "SinInheritanceType: " << sin2.getType() << endl;
}

int main(int argc, char* argv[])
{
  ifstream input("config/input.txt");
  double stopTime, timeStep;
  double amplitude, frequency, phase, offset;
  input >> stopTime >> timeStep
        >> amplitude >> frequency >> phase >> offset;

  Sinusoidal sinClass(amplitude, frequency, phase, offset);
  ofstream output("output.csv");
  output << "Time,Sinusoidal" << endl;
  for (double time = 0.0; time <= stopTime; time += timeStep)
    output << time << ',' << sinClass.getValue(time) << endl;

  SinusoidalInheritance sin2Class;
  foo(sinClass, sin2Class);

  return 0;
}
