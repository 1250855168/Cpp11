#include <iostream>
#include <iterator>
#include <ostream>
#include <utility>

class Complex {
private:
  double real;
  double vir;

public:
  explicit Complex(double r = 0.0, double v = 0.0) : real(r), vir(v) {}

  Complex(const Complex &other) {
    this->real = other.real, this->vir = other.vir;
  }

  Complex(Complex &&other) {}

  friend Complex operator+(const Complex &c1, const Complex &c2);
  friend Complex operator+(const double &c1, const Complex &c2);
  friend Complex operator+(const Complex &c1, const double &c2);

  friend Complex operator-(const Complex &c1, const Complex &c2);
  friend Complex operator-(const double &c1, const Complex &c2);
  friend Complex operator-(const Complex &c1, const double &c2);

  friend Complex operator*(const Complex &c1, const Complex &c2);
  friend Complex operator*(const double &c1, const Complex &c2);
  friend Complex operator*(const Complex &c1, const double &c2);

  Complex operator/(const Complex &other) const {
    double denominator = other.real * other.real + other.vir * other.vir;
    Complex temp(this->real * other.real - this->vir * other.vir,
                 this->real * this->vir + other.vir * other.real);
    double real_part = (temp.real) / denominator;
    double vir_part = (temp.vir) / denominator;
    return Complex(real_part, vir_part);
  }
  friend Complex operator/(const double &num, const Complex &c);
  friend Complex operator/(const Complex &c1, const double &c2);

  Complex &operator--() {
    --real;
    --vir;
    return *this;
  }

  Complex operator--(int) {
    Complex temp(*this);
    --this->real;
    --this->vir;
    return temp;
  }
  Complex &operator++() {
    ++this->real;
    ++this->vir;
    return *this;
  }
  Complex operator++(int) {
    Complex temp(*this);
    ++this->real;
    ++this->vir;
    return temp;
  }

  void print() const {
    std::cout << this->real;
    if (this->vir > 0) {
      std::cout << "+" << this->vir << "i";
    } else if (this->vir < 0) {
      std::cout << this->vir;
    }
    std::cout << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &o, Complex &);
  friend std::istream &operator>>(std::istream &i, Complex &);

  friend bool operator==(const Complex &c1, const Complex &c2);
  friend bool operator!=(const Complex &c1, const Complex &c2);
};

// +
Complex operator+(const Complex &c1, const Complex &c2) {
  return Complex(c1.real + c2.real, c1.vir + c2.vir);
}
Complex operator+(const double &c1, const Complex &c2) {
  return Complex(c1 + c2.real, c2.vir);
}
Complex operator+(const Complex &c1, const double &c2) {
  return Complex(c1.real + c2, c1.vir);
}

//  -
Complex operator-(const Complex &c1, const Complex &c2) {
  return Complex(c1.real - c2.real, c1.vir - c2.vir);
}

Complex operator-(const double &c1, const Complex &c2) {
  return Complex(c1 - c2.real, c2.vir);
}

Complex operator-(const Complex &c1, const double &c2) {
  return Complex(c1.real - c2, c1.vir);
}

// *
Complex operator*(const Complex &c1, const Complex &c2) {
  return Complex(c1.real * c2.real - c1.vir * c2.vir,
                 c1.real * c2.vir + c1.vir * c2.real);
}

Complex operator*(const double &c1, const Complex &c2) {
  return Complex(c2.real * c1, c2.vir * c1);
}

Complex operator*(const Complex &c1, const double &c2) {
  return Complex(c1.real * c2, c1.vir * c2);
}

//  /
Complex operator/(const double &num, const Complex &c) {
  double denominator = c.real * c.real + c.vir * c.vir;
  double real_part = num * c.real / denominator;
  double vir_part = -num * c.vir / denominator;
  return Complex(real_part, vir_part);
}

Complex operator/(const Complex &c1, const double &c2) {
  return Complex(c1.real / c2, c1.vir / c2);
}

std::ostream &operator<<(std::ostream &o, Complex &c) {

  o << c.real;
  if (c.vir > 0) {
    std::cout << "+" << c.vir << "i";
  } else if (c.vir < 0) {
    std::cout << c.vir;
  }
  std::cout << std::endl;

  return o;
}
std::istream &operator>>(std::istream &i, Complex &c) {

  i >> c.real >> c.vir;

  return i;
}

bool operator==(const Complex &c1, const Complex &c2) {
  if (c1.vir == c2.vir && c1.real == c1.real) {
    return true;
  }
  return false;
}
bool operator!=(const Complex &c1, const Complex &c2) {
  if (c1.vir == c2.vir && c1.real == c1.real) {
    return false;
  }
  return true;
}

int main() {
  Complex x(1, 2);
  Complex x1(1, -2);
  x.print();

  Complex t = x + 6.0;
  t.print();

  Complex t1 = 6.0 - x;
  t1.print();

  Complex t2 = x - 3.0;
  t2.print();

  Complex t3 = x * x;
  t3.print();

  Complex t4 = x / x1;
  t4.print();

  std::cout << "xxxxxxxxxxx" << std::endl;

  (x++).print();
  x.print();

  (++x).print();
  x.print();

  (x--).print();
  x.print();

  (--x).print();
  x.print();

  Complex test;

  std::cin >> test;
  std::cout << test;

  if (test == x) {
    std::cout << "==";
  }

  if (test != x) {
    std::cout << "!=";
  }

  std::cout << std::endl;

  return 0;
}