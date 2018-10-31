/*
 * Java: The program runs and outputs the odd numbers in the array. 
 * C++ Explanation: Arrays and pointers are very similar however when you convert an array into a pointer you lose some information about its structure including how long it is. This means that when you try to make it an array again in the main function the compiler doesn't have enough information to actually make the array from that pointer.
 */

#include <iostream>
using namespace std;

//makes an array of odd numbers and returns it as a pointer
int* oddNumbers() {
  int numbers[] = {1, 3, 5, 7};
  return numbers;
}

int main()
{
  
  int* odd = oddNumbers();

  for (int i = 0; i < 4; i++) {
   std::cout << odd[i]  << endl;
  }

  return 0;
}
