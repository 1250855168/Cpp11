#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <ostream>
#include <thread>
#include <utility>

/**
 * @brief thread future functional chrono 学习
 *
 * @param a_
 * @param a
 * @param b
 * @param c
 */

void test(int a_, int a, double b, const char *c) {
  std::cout << a_ << a << b << c << std::endl;
}

template <class F, class... Args>
auto xxx(F &&f, Args &&...args) -> std::future<decltype(f(args...))> {
  using return_type = decltype(f(args...));

  auto task = std::make_shared<std::packaged_task<return_type()>>(
      std::bind(std::forward<F>(f), std::forward<Args>(args)...));

  auto t = task->get_future();

  std::thread(std::move(*task)).detach();

  return t; // 获取结果
}

void timer_handler(int seconds) {
  std::this_thread::sleep_for(std::chrono::seconds(seconds));
  std::cout << "x" << std::endl;
}

int main() {

  auto x = xxx(test, 1, 2, 3.0, "123");

  int seconds = 5;

  std::thread timer_thread(timer_handler, seconds);

  timer_thread.join();

  return 0;
}