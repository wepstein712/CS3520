#include "IntArrayAlgorithms.hpp"
#include "IntArray.hpp"

void IntArrayAlgorithms::swap(IntArray & lhs, IntArray & rhs) {
  IntArray* temp = new IntArray(lhs.size());
  *temp = lhs;
  lhs = rhs;
  rhs = *temp;
  delete temp;
}

bool IntArrayAlgorithms::contains(const IntArray & arr, int val) {
  size_t s = arr.size();
  for (size_t i = 0 ; i < s; i++) {
    if (val == arr[i]) { return true; }
  }
  return false;
}

void IntArrayAlgorithms::sort(IntArray & arr) {
  int s = arr.size();
  for (int i = 0; i < s - 1; i++) {
   for (int j = 0; j < s-i-1; j++) {
     if (arr[j] > arr[j+1]) {
      int temp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1] = temp;
     }
   }
  }
}

int IntArrayAlgorithms::sum(const IntArray & arr) {
  int sum = 0; 
  size_t s = arr.size();
  for (size_t i = 0; i < s; i++) {
    sum+= arr[i];
  }
  return sum;
}

int IntArrayAlgorithms::product(const IntArray & arr) {
  int pro = 1;
  size_t s = arr.size();
  for (size_t i = 0; i < s; i++) {
    pro*= arr[i];
  }
  return pro;

}
