#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main() {

  std::vector<int> v;

  while (true) {
    int num;
    std::cin >> num;
    if (num == 0) {
      break;
    }
    v.push_back(num);
  }

  std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

  for (auto i : v) {
    std::cout << i << " ";
  }

  std::cout << std::endl;
  int index;
  std::cout << "please erase index: ";
  std::cin >> index;

  v.erase(v.begin() + index - 1);
  for (auto i : v) {
    std::cout << i << " ";
  }

  std::cout << std::endl;

  int number;
  std::cout << "please erase number: ";
  std::cin >> index;

  for (auto it = v.begin(); it != v.end();) {
    if (*it == number) {
      it = v.erase(it);
    } else {
      ++it;
    }
  }
  for (auto i : v) {
    std::cout << i << " ";
  }

  std::cout << std::endl;


  std::vector<int> v1;
  std::vector<int> v2;

  std::cout << "please input mid number: ";
  std::cin >> number;

  if (!v.empty()) {
    for (auto i : v) {
      if (i < number) {
        v1.push_back(i);
      } else {
        v2.push_back(i);
      }
    }
  }

  for (auto i : v1) {
    std::cout << i << " ";
  }

  std::cout << " v1.size()=" << v1.size() << std::endl;

  for (auto i : v2) {
    std::cout << i << " ";
  }

  std::cout << " v2.size()=" << v2.size() << std::endl;

  return 0;
}