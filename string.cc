#include <cstring>
#include <iostream>
#include <ostream>

class mString {
private:
  char *m_data;

  int m_size;

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

  mString(const mString &&other) {
    m_size = other.m_size;

    m_data = new char[m_size + 1];

    memcpy(m_data, other.m_data, m_size + 1);
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

  char operator[](int index) { return *(m_data + index); }

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

  o << other.m_data;

  return o;
}

std::istream &operator>>(std::istream &i, mString &other) {

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

  std::cin >> s;

  std::cout << s << std::endl;

  return 0;
}