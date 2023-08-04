#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {

  std::list<int> l{1, 2, 3};

  std::for_each(l.begin(), l.end(), [](int a) { std::cout << a << " "; });

  std::cout << std::endl;

  std::list<int> l1(2, 3);
  std::for_each(l1.begin(), l1.end(), [](int a) { std::cout << a << " "; });

  std::cout << std::endl;

  std::list<int> l2(l);
  std::for_each(l2.begin(), l2.end(), [](int a) { std::cout << a << " "; });

  std::cout << std::endl;

  std::list<int> l3(l.begin(), --l.end());
  std::for_each(l3.begin(), l3.end(), [](int a) { std::cout << a << " "; });

  std::cout << std::endl;

  std::vector<int> nums = {};

  std::list<int> numbers{1, 2, 4, 5, 4, 4, 9, 4, 5, 4, 5};

  //   std::cout << "请输入一组整数（输入0结束）：" << std::endl;

  //   int input;
  //   while (std::cin >> input && input != 0) {
  //     auto it = std::lower_bound(numbers.begin(), numbers.end(), input,
  //                                [](int a, int b) { return a < b; });
  //     numbers.insert(it, input);
  //   }

  //   std::cout << "please input number:";
  //   while (true) {
  //     int number;
  //     std::cin >> number;
  //     if (number == 0) {
  //       break;
  //     }
  //     nums.emplace_back(number);
  //   }

  // std::sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });

  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  //   std::cout << "please erase number:";
  //   int number;
  //   std::cin >> number;
  //   for (auto it = nums.begin(); it != nums.end();) {
  //     if (*it == number) {
  //       it = nums.erase(it);
  //     } else {
  //       it++;
  //     }
  //   }

  //使用Lambda表达式移除容器中元素
  std::cout << "please erase number:";
  int number;
  std::cin >> number;
  numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
                               [number](int a) { return a == number; }));

  // 输出移除后的结果
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}