#include <algorithm>
#include <functional>
#include <iostream>
#include <set>

int main() {
  // 创建一个 set 并插入元素
  // std::set<int, decltype([](const int &a, const int &b) { return a > b; })>
  std::set<int, std::greater<int>> mySet;
  mySet.insert(5);
  mySet.insert(2);
  mySet.insert(8);
  mySet.insert(1);

  // 使用迭代器遍历 set
  std::cout << "Set elements: ";
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // 检查元素是否存在于 set 中
  int num = 8;
  if (mySet.count(num) > 0) {
    std::cout << num << " is present in the set." << std::endl;
  } else {
    std::cout << num << " is not present in the set." << std::endl;
  }

  // 删除元素
  mySet.erase(2);

  // 使用范围循环遍历 set
  std::cout << "Set elements after erasing: ";
  for (const auto &element : mySet) {
    std::cout << element << " ";
  }
  std::cout << std::endl;

  // 清空 set
  mySet.clear();

  // 检查 set 是否为空
  if (mySet.empty()) {
    std::cout << "Set is empty." << std::endl;
  } else {
    std::cout << "Set is not empty." << std::endl;
  }

  return 0;
}