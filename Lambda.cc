// #include <iostream>

// int main() {
//   int x = 5;
//   int y = 10;

//   auto f1 = [x]() { std::cout << "f1: x = " << x << "\n"; };
//   auto f2 = [&x]() { x *= 2; };
//   auto f3 = [=]() { std::cout << "f3: x = " << x << ", y = " << y << "\n"; };
//   auto f4 = [&]() {
//     x *= 2;
//     y *= 2;
//   };

//   f1(); // 输出 f1: x = 5
//   f2();
//   f1(); // 输出 f1: x = 5，因为 f2 中的修改不影响外部变量 x 的值
//   f3(); // 输出 f3: x = 5, y = 10
//   f4();
//   f3(); // 输出 f3: x = 10, y = 20

//   return 0;
// }

#include <iostream>

int main() {
  int x = 5;

  auto f1 = [x]() mutable {
    std::cout << "f1: x = " << x
              << "\n"; //使用它的细节  它虽然不会改变X外部的
                       //但是如果你连续调用两次 他自己里面的X会保留下来被改变
    x *= 2;
  };
  auto f2 = [&x]() {
    x *= 2;
    std::cout << "f2: x = " << x << "\n";
  };

  f1(); // 输出 f1: x = 5
  f1(); // 输出 f1: x = 5，因为使用了 mutable 关键字，x

  std::cout << x << std::endl;
  f2();

  f1(); // 输出 f1: x = 10，因为 f2 中修改了 x 的值，所以 f1 中的 x
  //  也被修改了

  return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <vector>

// int main() {
//   std::vector<std::function<int(int)>> v;
//   v.push_back([](int x) { return x + 1; });
//   v.push_back([](int x) { return x * 2; });
//   v.push_back([](int x) { return x - 3; });

//   int x = 5;
//   for (auto f : v) {
//     x = f(x);
//   }

//   std::cout << "Result: " << x << "\n"; // 输出 8
//   return 0;
// }

// #include <functional>
// #include <iostream>

// auto make_incrementer(int n) {
//   return [n](int x) { return x + n; };
// }

// int main() {
//   auto inc = make_incrementer(5);
//   std::cout << inc(6) << "\n"; // 输出 11
//   return 0;
// }

// #include <algorithm>
// #include <iostream>
// #include <vector>

// void for_each(std::vector<int> &v, void (*f)(int)) {
//   for (auto i : v) {
//     f(i);
//   }
// }

// int main() {
//   std::vector<int> v = {1, 2, 3, 4, 5};
//   for_each(v, [](int i) { std::cout << i << " "; });
//   std::cout << "\n";
//   return 0;
// }