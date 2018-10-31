/*
 * Java: You get an array out of bounds exception when you run
 * C++: Runs fine, get "0 = 6" as result.
 * C++ Explanation: The reason the mutliplication gets to 0 is because the for loop runs out of the end of the array into whatever memory is next.
 */
#include <iostream>
using namespace std;

int main()
{
  int a[] = {1, 2, 3};
  int total = 1;

  for (int i = 0; i <=3; i++) {
     total *=a[i];
  }

  cout << total << " = 6";

  return 0;
}
