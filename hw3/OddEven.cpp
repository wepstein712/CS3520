/*
 * Java: OUtput is as expected of the numbers 1-8 in pairs each row.
 * C++: Print out the same number and then becomes nonsense;
 * C++ Explanation: When the array becomes the pointer it no longer knows what it is and assigning it as an array no longer works because it has lost the information about its length. Also since both oddNumbers and evenNumbers use doReturn on a variable called numbers they overwrite eachother.
 */

#include <iostream>
using namespace std;

//returns the copy of the given array
int* doReturn(int ret[]) {
  return ret;
}

//makes an array of numbers and then returns it.
int* oddNumbers() {
  int numbers[] = {1, 3, 5, 7};
  return doReturn(numbers);
}


//makes an array of numbers and then returns it
int* evenNumbers() {
  int numbers[] = {2, 4, 6, 8};
  return doReturn(numbers);
}

int main()
{
  int* odd = oddNumbers();
  int *even = evenNumbers();


  for (int i = 0; i < 4; i++) {
    std::cout << odd[i] << " " << even[i] << endl;
  } 

  return 0;
}
