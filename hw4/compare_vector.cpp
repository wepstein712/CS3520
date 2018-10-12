#include <iostream>
#include <vector>
using namespace std;


void at_access(vector<int> &arr) {
  int size = arr.size();
  for (int i = 0; i < size; i++) {
    arr.at(i) = 0;
  }

}

void bracket_access(vector<int> &ar) {
  int size = ar.size();
  for (int j = 0; j < size; j++) {
    ar[j] = 7;
  }
 
}

int main() {
 // std::vector<int> a1 (1000, 1);
 // std::vector<int> a2 (100000, 3);

  std::vector<int> a3 (100000000, 4);


 /* at_access(a1);
  bracket_access(a1);
  at_access(a2);
  bracket_access(a2);
*/ 
 at_access(a3);
  bracket_access(a3);

}
