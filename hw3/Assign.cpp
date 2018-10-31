/*
 * Java: when run it errors with a possible loss of information when converting n to type short (ln 12);
 * C++: No error is thrown, when run you get the output: 40000 -25536 -25536
 * C++ Explanation: the short is given a number too big to be represented with given it is a signed short. So when it converts the number you get is past the positive max a signed short can give you and is in the negative portion of the numbers a short can represent.
 */

#include <iostream>
using namespace std;
int main()
{
  int n = 40000;
  short m = n;
  int o = m;

  cout << n << " " << m << " " << o;

  return 0;
}
