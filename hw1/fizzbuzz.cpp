#include <iostream>

int
main()
{
  int x = -1;
  int y = -1;
  std::cin >> x >> y;
  for (int i = 1; i <= 20; i++) {
    if (i % x == 0 ) {
      std::cout << "Fizz";
    }
    if (i % y == 0) {
      std::cout << "Buzz";
    }
    if (i % x != 0 && i % y != 0) {
      std:: cout << i; 
    }

    std::cout << '\n';
  }

  return 0;
}
