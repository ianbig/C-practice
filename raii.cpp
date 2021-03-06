#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

class Test {
 public:
  Test() { std::cout << "Test Constructor is called" << std::endl; }

  ~Test() { std::cout << "~Test() is called" << std::endl; }
};

void test() {
  std::unique_ptr<Test> t(new Test());
  // Test * t = new Test();
  throw std::exception();
}

int main() {
  try {
    test();
  }

  catch (std::exception & e) {
    std::cout << "In catch" << std::endl;
    exit(EXIT_SUCCESS);
  }
}
