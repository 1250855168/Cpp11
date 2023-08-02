

#include <iostream>
#include <list>

int main() {

  std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto i : l) {
    std::cout << i << " ";
  }

  std::cout << std::endl;

  return 0;
}