#include <iostream>
#include <map>
#include <utility>

int main() {

  std::map<char, int> m;

  m.insert(std::make_pair('c', 1));

  m.insert(std::make_pair('a', 2));

  m.insert(std::make_pair('d', 3));

  for (auto i : m) {
    std::cout << i.first << " " << i.second << std::endl;
  }

  int a = 42;
  uintptr_t uintptr = reinterpret_cast<uintptr_t>(&a);  /* 指向 void 的指针 */ 
  int *intPtr = reinterpret_cast<int *>(uintptr);

  std::cout << *intPtr << std::endl;

  auto i = m.find('a');
  if (i != m.end()) {
    std::cout << i->first << " " << i->second << std::endl;
    i = m.erase(i);
    std::cout << i->first << " " << i->second << std::endl;
  }

  return 0;
}