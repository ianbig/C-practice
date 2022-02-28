#include <exception>
#include <iostream>

void nothrow() {
  try {
    throw std::bad_alloc();
  }

  catch (std::bad_cast & e) {
    std::cout << "exception catch" << std::endl;
  }

  catch (std::bad_alloc & e) {
    std::cout << "exception catch" << std::endl;
  }

  std::cout << "resume excuting nothrow" << std::endl;
}

int main() {
  nothrow();
  std::cout << "terminating program normally" << std::endl;
}
