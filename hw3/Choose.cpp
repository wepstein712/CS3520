/*
 * Java: when compiling the java equivalent it throws an error because you can take in any int but only return values for 0, 1, and 2. There is no default case in this swithc statement so if you passed any other value the function wouldn't return (which it is supposed to do).
 * C++: It compiles fine but when run it segmentation faults.
 * C++ Explanation: It seg-faults because when you run the last call to choose (choose(4)) you o not account for the rest of the valid inputs to the function and thusly some memory is accessed that isn't supposed to be, hence the failure. 
 */

#include <iostream>
#include <string>
using namespace std;


//takes a number and returns a string, sometimes
string static choose(int n) {
  switch (n) {
    case 0: return "zero";
    case 1: return "one";
    case 2: return "two";
  }
}

int main()
{
  std::cout << choose(0);
  std::cout << choose(2);
  std::cout << choose(4);

  return 0;
}
