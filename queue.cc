#include <iostream>
#include <ostream>
#include <queue>

int main() {

  std::queue<int> q; //可以是list deque 不可以是vector
  int numebr;
  std::cin >> numebr;
  while (numebr != 0) {
    q.push(numebr);
    std::cin >> numebr;
  }

  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;

  return 0;
}