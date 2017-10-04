
#include "Fixed.class.hpp"

int main() {
  Fixed    a(1.1f);
      Fixed    b(1.1f);
      Fixed    c(2.2f);
      Fixed    d(3.3f);
  std::cout << (b - c) << std::endl;
  return 0;
  }