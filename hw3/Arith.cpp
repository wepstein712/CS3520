/*
 * Java: in Java you get a / 0 exception because in the calculation of you divide 2 by 3 which as an int is rounded down to 0, then you divde 1 by 0.
 * C++:  the error you get running the c++ code is a floating point error.
 * C++ Explanation: The reason you get a floating point error is because you are trying to divide by 0 when dealing with ints, which get rounded. If you used floats or doubles the error goes away and the math resolves fine.
 */

#include <iostream>
using namespace std;

// divives 3 numbers in an interesting way
int static divide(int x, int y, int z) 
{
  return x / (y / z);
}

int main()
{
  int n = divide (3,  2, 1);
  int m = divide (1, 2, 3);
  int w = n * m;
  cout << w;

  return 0;
}
