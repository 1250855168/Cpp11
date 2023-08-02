#include "list.hpp"
#include <iostream>

template <typename T1, typename T2> auto add(T1 a, T2 b) -> decltype(a + b) {
  return a + b;
}

int main() {

  list<int> l;

  l.insert(1);
  l.insert(3);
  l.insert(7);

  l.findNode(1);

  l.delNode(1);

  std::cout << l;

  return 0;
}