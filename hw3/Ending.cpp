/*
 * Java: On run got error of string index out of bounds.
 * C++: When run it prints out "orld! 8"
 * C++ Explanation: It prints this out because the for loop starts at the 8th index of the in string and then continues another 7 steps. However the entire string is only 14 in length so the for loop goes through the rest of the string an then acesses the next chunk of memory next to where the string was stored (hence the space). It also goes over the end-string character here.
 */

#include <string>
#include <iostream>
using namespace std;

int main()
{
  string in = "Hello, world!";
  int length = 16;
  string out = "";

  for (int i = length / 2; i < length; i++) {
    out += in[i];

  }
  cout << out << " " << out.length();
 
   return 0;
}
