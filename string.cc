#include <condition_variable>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <mutex>
#include <ostream>
#include <string>

/*在 C++11 标准中，std::string
的实现必须是线程安全的。这意味着多个线程可以同时读取同一个 std::string
对象，而不会导致不一致的结果或竞争条件。

然而，需要注意的是，对于 std::string
对象的写操作并不线程安全。当多个线程同时修改同一个 std::string
对象时，可能会发生竞争条件，导致未定义的行为或程序崩溃。因此，在多线程环境中修改
std::stringE
对象时，需要采取适当的同步措施，例如使用互斥锁或读写锁来保护修改操作的原子性和顺序性。*/


class mString {
private:
  char *m_data;

  int m_size;

  std::mutex m;
  std::condition_variable cv;

public:
  mString(const char *s = nullptr) : m_data(nullptr), m_size(0) {
    if (s != nullptr) {
      m_size = strlen(s);

      m_data = new char[m_size + 1];

      memcpy(m_data, s, sizeof(m_size + 1));
    }
  }

  mString(const mString &other) {
    m_size = other.m_size;

    m_data = new char[m_size + 1];

    memcpy(m_data, other.m_data, m_size + 1);
  }

  mString(mString &&other) {
    m_data = other.m_data;
    m_size = other.m_size;
    other.m_data = nullptr;
  }

  mString &operator=(const mString &other) {
    if (this != &other) {
      delete[] m_data;

      m_size = other.m_size;

      m_data = new char[m_size + 1];

      memcpy(m_data, other.m_data, m_size + 1);
    }

    return *this;
  }

  char operator[](const int index) const { return *(m_data + index); }

  char &operator[](const int index) { return *(m_data + index); }

  bool operator<(const mString &other) {
    int i;
    for (i = 0; i < m_size && i < other.m_size; i++) {
      if (*(m_data + i) == *(other.m_data + i)) {
        continue;
      }
      if (*(m_data + i) < *(other.m_data + i)) {
        return true;
      } else {
        return false;
      }
    }
    return m_size < other.m_size;
  }

  bool operator<=(const mString &other) {

    int i;
    for (i = 0; i < m_size && i < other.m_size; i++) {
      if (*(m_data + i) == *(other.m_data + i)) {
        continue;
      }
      if (*(m_data + i) < *(other.m_data + i)) {
        return true;
      } else {
        return false;
      }
    }
    return m_size <= other.m_size;
  }

  bool operator>(const mString &other) {
    int i;
    for (i = 0; i < m_size && i < other.m_size; i++) {
      if (*(m_data + i) == *(other.m_data + i)) {
        continue;
      }
      if (*(m_data + i) > *(other.m_data + i)) {
        return true;
      } else {
        return false;
      }
    }
    return m_size > other.m_size;
  }

  bool operator>=(const mString &other) {
    int i;
    for (i = 0; i < m_size && i < other.m_size; i++) {
      if (*(m_data + i) == *(other.m_data + i)) {
        continue;
      }
      if (*(m_data + i) < *(other.m_data + i)) {
        return true;
      } else {
        return false;
      }
    }
    return m_size >= other.m_size;
  }

  bool operator==(const mString &other) {
    int i = 0;
    if (m_size == other.m_size) {
      while (*(m_data + i) == *(other.m_data + i) && i <= m_size) {
        i++;
      }
    }
    return i == other.m_size + 1;
  }

  bool operator!=(const mString &other) {
    int i = 0;
    if (m_size == other.m_size) {
      while (*(m_data + i) == *(other.m_data + i) && i <= m_size) {
        i++;
      }
    }
    return !(i == other.m_size + 1);
  }

  friend std::ostream &operator<<(std::ostream &o, mString &other);

  friend std::istream &operator>>(std::istream &i, mString &other);

  ~mString() { delete[] m_data; }

  mString operator+(mString &other) {

    mString s;

    s.m_data = new char[m_size + other.m_size + 1];

    s.m_size = m_size + other.m_size;

    memcpy(s.m_data, other.m_data, other.m_size + 1);

    strcat(s.m_data, other.m_data);

    return s;
  }

  mString &operator+=(mString &other) {

    this->m_size = this->m_size + other.m_size;

    mString s(*this);

    delete[] m_data;
    m_data = new char[m_size + other.m_size + 1];

    std::memcpy(this->m_data, s.m_data, s.m_size);

    strcat(this->m_data, other.m_data);

    return *this;
  }
};

std::ostream &operator<<(std::ostream &o, mString &other) {

  std::lock_guard<std::mutex> lg(other.m); //保证线程安全

  o << other.m_data;

  return o;
}

std::istream &operator>>(std::istream &i, mString &other) {

  std::lock_guard<std::mutex> lg(other.m); //保证线程安全

  if (other.m_size != 0) {
    delete[] other.m_data;
  }

  char buf[1024];

  i >> buf;

  other.m_size = strlen(buf);

  other.m_data = new char[other.m_size + 1];

  memcpy(other.m_data, buf, other.m_size + 1);

  return i;
}

int main() {

  mString s("123");

  mString s1(s);

  s1 = s;

  mString s2 = s1 + s;

  std::cout << s2 << std::endl;

  s2 += s1;
  std::cout << s2 << std::endl;

  std::cout << s1[1] << std::endl;

  std::cout << (s1 >= s) << std::endl;
  std::cout << (s1 > s) << std::endl;

  std::cout << (s1 <= s) << std::endl;
  std::cout << (s1 < s) << std::endl;

  std::cout << (s1 == s) << std::endl;
  std::cout << (s1 != s) << std::endl;

  std::string c;
  std::getline(std::cin, c);

  std::cout << c << std::endl;

  std::cin >> s;

  std::cout << s << std::endl;

  return 0;
}