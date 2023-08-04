#include <deque>
#include <iostream>
#include <list>
#include <ostream>
#include <stack>

using namespace std;

int main() {

  deque<int> d{1, 2, 3, 4, 5};
  list<int> l{5, 4, 3, 2, 1};

  stack<int, list<int>> s(l);

  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }

  s.push(1);
  s.emplace(2);

  cout << s.top() << endl;

  cout << s.size() << endl;

  cout << s.empty() << endl;


  return 0;
}