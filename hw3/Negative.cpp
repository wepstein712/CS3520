/*
 *  * Java: Java code is able to differentiate between the two variables named numbers, prints out -1, ..., -8.
 *   * C++: C++ code outputs -1,...,-4 twice
 *    * C++ Explanation: The varibales of the same name in different functions write over eachother and give the repeated -1 -> -4 array twice. In addition these pointers are local only, so once they the function returns the are no longer in the global scale.   
 */

#include <iostream>
#include <array>
using namespace std;


//makes an array of ints and returns a pointer to it
static int* numbers() {
  int numbers[] = {-5, -6, -7, -8};
  int *ret = numbers;
  return ret;
}

static void displayBoth (int others[]) {

  int numbers[4] = {-1, -2, -3, -4};

  for (int i = 0; i < 4; i++) {
    cout << numbers[i] << endl;
  }

  for (int i = 0; i < 4; i++) {
    cout << others[i] << endl;
  }

}

int main()
{
  displayBoth(numbers());

  return 0;
}
