#include <array>
#include <iostream>

int main() {

  std::array<int, 10> a{};
  int i = 0;
  while (true) {
    int number;
    std::cin >> number;
    if (number == 0) {
      break;
    }
    a.at(i++) = number;
  }

  for (auto i : a) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}