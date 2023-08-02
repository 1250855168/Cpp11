
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <mutex>
#include <ostream>
/*
如果将 operator<< 的声明中的模板参数 U 改为 T，即：

friend std::ostream &operator<<(std::ostream &o, const list<T> &l);
那么会导致编译错误，因为此时 list 类的模板参数 T 和 operator<< 的模板参数 T
重名了。这个错误可以通过编译器的错误提示得到解决。

具体来说，如果使用 T 代替 U，那么 operator<< 函数的声明和定义就不能成为 list
类的友元函数了，因为此时声明的函数和 list
类中的模板参数重名，编译器会认为这不是一个模板函数声明，从而导致编译错误。

因此，为了避免这种错误，我们需要在 operator<<
的声明和定义中使用不同的模板参数，例如我的代码和你的代码都使用了 U
作为模板参数，这样就避免了和 list 类中的模板参数重名的问题。*/

template <class T> class Node {
private:
  T m_data;
  Node *next;

public:
  Node<T>(T data = 0) : m_data(data), next(nullptr) {}

  Node<T>(const Node<T> &other) = delete;

  void set_data(const T &data) { m_data = data; }
  T get_data() const { return m_data; }

  void setNextData(T &data) { next->m_data = data; }

  T getNextData() const { return next->m_data; }

  void setNext(Node<T> &n) { next = &n; }

  Node *getNext() const { return next; }
};

template <class T> class list {

private:
  Node<T> *first;
  Node<T> *last;

  std::mutex mut;

public:
  //这个在友元函数 为了避免重名 我们应该重新定义一个模板U
  template <typename U>
  friend std::ostream &operator<<(std::ostream &o, list<U> &l);
  list<T>() : first(nullptr), last(nullptr) {}
  ~list<T>() {
    Node<T> *node = first;
    while (node) {
      Node<T> *t = node->getNext();
      delete node;
      node = nullptr;
      node = t;
    }
  }
  bool insert(T data) {
    if (first == nullptr) {
      first = new Node<T>;
      last = first;
      last->set_data(data);
      return true;
    } else {
      Node<T> *n = new Node<T>();
      last->setNext(*n);
      last = last->getNext();
      last->set_data(data);
      return true;
    }
    return false;
  }

  bool insert(T data, int index) {
    Node<T> *n1 = findNode(index - 1);
    if (n1 == nullptr) {
      return false;
    }
    Node<T> *n = new Node<T>(data);
    n->setNext(n1->getNext());
    n1->setNext(*n);
    if (n->getNext() == nullptr) {
      last = n;
    }
  }

  bool delNode(int index) {
    if (first == findNode(index)) {
      Node<T> *n2 = findNode(index + 1);
      delete first;
      first = n2;
      return true;
    }
    Node<T> *n1 = findNode(index - 1);
    if (n1 == nullptr) {
      return false;
    }
    Node<T> *n2 = findNode(index + 1);
    if (n2 == nullptr) {
      return false;
    }
    n1->setNext(*n2);
    return true;
  }

  // Node<T> *findNode(int index) {
  //   Node<T> *n = first;
  //   int i = 0;
  //   while (n) {
  //     n = n->getNext();
  //     i++;
  //   }
  //   return (n == nullptr) ? nullptr: n;
  // }

  Node<T> *findNode(int index) {
    Node<T> *n = first;
    int i = 1;
    while (n && i < index) {
      n = n->getNext();
      i++;
    }
    return (n && i == index) ? n : nullptr;
  }
};
//两个模板类的U T 应该不一样
template <typename U> std::ostream &operator<<(std::ostream &o, list<U> &l) {
  std::lock_guard<std::mutex> lg(l.mut);
  Node<U> *node = l.first;
  while (node) {
    o << node->get_data() << " ";
    node = node->getNext();
  }
  o << std::endl;
  return o;
}


// template <typename T>   //两个模板类的U T 应该不一样
// std::ostream &operator<<(std::ostream &o, const list<T> &l) {
//   std::lock_guard<std::mutex> lg(l.mut);
//   Node<T> *node = l.first;
//   while (node) {
//     o << node->get_data() << " ";
//     node = node->getNext();
//   }
//   o << std::endl;
//   return o;
// }

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