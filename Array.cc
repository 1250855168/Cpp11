#include <iostream>
#include <ostream>

template <class T, int size> class Array {
private:
  T *data;

public:
  Array() { data = new T[size]; }
  ~Array() { delete[] data; }

  const T &operator[](int index) const { return data[index]; }
  T &operator[](int index) { return data[index]; }

    template <class U, int size_>
    friend std::ostream &operator<<(std::ostream &o, Array<U, size_> &t);

};

template <class U, int size_>
std::ostream &operator<<(std::ostream &o, Array<U, size_> &t){
  for (int i = 0; i < size_; i++) {
    o << t[i] << " ";
  }
  std::cout << std::endl;
  return o;
}

int main() {

  Array<int, 10> t;

  t[0] = 1;
  t[1] = 2;

  std::cout << t;

  return 0;
}