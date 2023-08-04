#include <algorithm>
#include <deque>
#include <iostream>

int main() {

  std::deque<int> d{};

  while (true) {
    int number;
    std::cin >> number;
    if (number == 0) {
      break;
    }
    auto it = std::lower_bound(d.begin(), d.end(), number);
    d.insert(it, number);
  }

  std::for_each(d.begin(), d.end(), [](int a) { std::cout << a << " "; });

  std::cout << std::endl;

  std::cout << "please input erase ";
  int number;
  std::cin >> number;

  for (auto it = d.begin(); it != d.end();) {

    if (*it == number) {
      d.erase(it);
    } else {
      ++it;
    }
  }

  std::for_each(d.begin(), d.end(), [](int a) { std::cout << a << " "; });

  std::cout << std::endl;

  return 0;
}