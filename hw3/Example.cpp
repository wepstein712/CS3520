/*
 * Java: Prints correct values, then throws an ArrayIndexOutOfBoundsException.
 * C++: Prints correct values, then an extra large value.
 * C++ Explanation: The loop accesses an out-of-bounds element in the array "vals". The value off the end of the array is used and the program continues running.
 */

// example C++ program
#include <iostream>
#include <string>

int sqr(int x) {
  return x * x;
}

int main() {
  int vals[] = { 1, 2, 3, 4 };

  std::string text = " squared is ";
  for(int i = 0; i <= 4; i++) {
    std::cout << vals[i] << text << sqr(vals[i]) << std::endl;
  }

  return 0;
}
