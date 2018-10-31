/*
 * Java: java code will not compile because the variable downto might not have been initialized.
 * C++: C++ compiles fine and runs, over the runs I got it only printed blastoff but not any numbers.
 * C++ Explanation: downto isnt initialized so its value is undefined beahvior, it happens to be greater than 10 so none of the numbers print and the program only prints blastoff. 
 */
#include <iostream>
using namespace std;


//count down to blastoff function
void static countdown() {
  int downto;
  for (int i = 10; i >= downto; i--) {
    std::cout << i;
  }
  std::cout << "Blastoff";
}


int main()
{
  countdown();

  return 0;
}
