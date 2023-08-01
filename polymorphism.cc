#include <iostream>
#include <iterator>
#include <ostream>

/*

函数重载

操作符重载

两个属于 静态绑定
*/

class A {
public:
  virtual void init() { std::cout << "A init()" << std::endl; }

  virtual void destory() { std::cout << "A destory()" << std::endl; }

  virtual void printf(int a = 250) { std::cout << "a=" << a << std::endl; }

  A() {
    init();
    std::cout << " A()" << std::endl; //构造函数 只能进行静态绑定
  }

  virtual ~A() {
    destory();
    std::cout << " ~A()" << std::endl; //析构函数 只能进行静态绑定
  }
};

class B : public A {
public:
  B() {
    init();
    std::cout << " B()" << std::endl; //构造函数 只能进行静态绑定
  }

  virtual void printf(int b = 360) { std::cout << "b=" << b << std::endl; }

  ~B() {
    destory();

    std::cout << " ~B()" << std::endl; //析构函数 只能进行静态绑定
  }
};

void p(A *a) { a->printf(); } //打印 b = 250 采用默认值

int main() {

  B b;

  p(&b);

  return 0;
}