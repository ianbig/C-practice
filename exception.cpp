#include <exception>
#include <iostream>

class Test {
 public:
  int * ptr;
  Test() : ptr(new int[4]) {}

  ~Test() {
    std::cout << "~Test() is called" << std::endl;
    delete[] ptr;
  }
};

void throwStuff() {
  Test t;
  throw std::exception();
}

int main() {
  throwStuff();
}
