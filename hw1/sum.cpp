#include <iostream>

int
main()
{
  int sum = 0; 
  int n = 0;
  std::cin >> n;
  do {
    sum += n;
  } while (!std::cin.eof() && std::cin >> n);
  
  std::cout << sum << '\n';

  return 0;
}
