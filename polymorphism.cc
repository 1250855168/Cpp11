#include <iostream>
#include <iterator>

/*

函数重载

操作符重载

两个属于 静态绑定
*/

class A {
public:
  virtual void init() { std::cout << "A init()" << std::endl; }

  virtual void destory() { std::cout << "A destory()" << std::endl; }

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

  ~B() {
    destory();

    std::cout << " ~B()" << std::endl; //析构函数 只能进行静态绑定
  }
};

int main() {

  A *a = new B();

  delete a;

  return 0;
}