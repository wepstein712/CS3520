/*
 * Java: You get a stack overflow error
 * C++: You get a segmentation fault
 * C++ Explanation: You segmentation fault for the same reason as the java program failed, you had too many things on the stack and as the stack point exceeded its alotted memory the program tried to access something it wasn't supposed to and seg-fault. 
*/

#include <iostream>
using namespace std;

//calculated the sum/ diffference recursively from 1 - n
double static compute (int x) {
 if (x <= 0) {return 0.0;}

  double localdata1;
  double localdata2;
  double localdata3;
  double localdata4;
  double localdata5;
  
  localdata1 = compute(x - 1);
  localdata2 = compute(x - 2);
  localdata3 = compute(x - 3);
  localdata4 = compute(x - 4);
  localdata5 = compute(x - 5);

  return localdata1 - localdata2 + localdata3 - localdata4 +localdata5;
}

int main()
{
  cout << compute(1000000);

  return 0;
}
