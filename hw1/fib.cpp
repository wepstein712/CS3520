#include <iostream>

int fib(int n) {
  if (n == 0 || n == 1) {
    return n;
  }

  int fn = fib(n - 1) + fib(n - 2);
  return fn;
}

int
main()
{
  int N;
  std::cin >> N;
  if (N > 0) {
    for (int i = 1; i <= N; i++) {
      std::cout << fib(i) << '\n';
    }
  } else {
    std::cout << "Input Error";
  }

  return 0;
}
